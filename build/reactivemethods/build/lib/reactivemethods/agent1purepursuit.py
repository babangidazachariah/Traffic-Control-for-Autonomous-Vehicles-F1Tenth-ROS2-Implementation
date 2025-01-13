#https://github.com/f1tenth-dev/pure_pursuit/blob/master/scripts/vehicle_controller.py Another implementation

import math
import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import PoseStamped
from visualization_msgs.msg import Marker, MarkerArray
import tf2_ros
import csv

class PurePursuitNode(Node):

    def __init__(self):
        super().__init__('pure_pursuit_node')
        self.cmd_pub = self.create_publisher(AckermannDriveStamped, 'drive', 10) 
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        
        self.waypoints = [] 
        self.current_waypoint = None 
        self.waypoint_index = 0
        self.lookahead_dist = 1.0 
        self.desired_linear_vel = 1.5 
        self.max_steering_angle = math.pi / 4 
        self.wheelbase = 0.3302
        self.timer = self.create_timer(0.1, self.timer_callback) 
        
        #self.load_waypoints('/home/babangida/ros_ws/src/reactivemethods/Spielberg_centerline.csv') 
        self.load_waypoints('/home/user/myros_ws/intersection/agent1_southnorth.csv') 
        
        
        #self.dsrcbsm_sub = self.create_subscription(Dsrcbsm, '/dsrcbsm', self.dsrcbsm_callback, 10)
        #self.dsrcbsm_pub = self.create_publisher(Dsrcbsm, '/dsrcbsm', 10)
        
        #Specify point before intersection:::Intersection Stop Line
        self.ctl_x = 0.38393493
        self.ctl_y = 0.103215553
        
        #self.name = 'agent1'
        #self.fromroad = 'south'
        #self.toroad = 'west'
        #self.dsrcbsm = Dsrcbsm()
        #self.dsrcbsm.fromroad = self.fromroad
        #self.dsrcbsm.toroad = self.toroad
        #self.dsrcbsm.name = self.name
        
     
    def dsrcbsm_callback(self, msg):
        if msg.name == self.name:
            print('Self Data')
        else:
            print("Other Agent Data")


    def timer_callback(self):
       
            try:
                trans = self.tf_buffer.lookup_transform('map', 'ego_racecar/base_link', rclpy.time.Time()) 
            except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
                self.get_logger().error('TF2 exception') 
                return
            
            
            vehicle_pos = trans.transform.translation 
            vehicle_yaw = math.atan2(trans.transform.rotation.z, trans.transform.rotation.w) * 2.0 
            dist = math.sqrt((vehicle_pos.x - self.ctl_x)**2 + (vehicle_pos.y - self.ctl_y)**2)
            angle = math.atan2(self.ctl_y - vehicle_pos.y, self.ctl_x - vehicle_pos.x) 
            angle_diff = math.atan2(math.sin(angle - vehicle_yaw), math.cos(angle - vehicle_yaw))
            print('vehicle_pos.x', vehicle_pos.x)
            
            
           
    
    def publish_drive_command(self, steering_angle):
        cmd_vel = AckermannDriveStamped() 
        
        cmd_vel.header.stamp = self.get_clock().now().to_msg() 
        cmd_vel.header.frame_id = 'base_link' 
        cmd_vel.drive.speed = self.speed 
        cmd_vel.drive.steering_angle = steering_angle 
        cmd_vel.drive.steering_angle_velocity = 0.0 
        steering_angle = max(-self.max_steering_angle, min(cmd_vel.drive.steering_angle, self.max_steering_angle)) 
        cmd_vel.drive.steering_angle = steering_angle
        print('Steering Angle: ', steering_angle)
        self.cmd_pub.publish(cmd_vel)
        
    def distance_to_criticalpoint(self, x, y):
        dist = float('inf') 
        try:
            trans = self.tf_buffer.lookup_transform('map', 'opp_racecar/base_link', rclpy.time.Time()) 
            vehicle_pos = trans.transform.translation
            dist = math.sqrt((vehicle_pos.x - x)**2 + (vehicle_pos.y - y)**2)  
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
            self.get_logger().error('TF2 exception')
            
        return dist
        
        
    def find_closest_point(self):
        
        min_dist = float('inf') 
        
        min_point = None 

        try:
            trans = self.tf_buffer.lookup_transform('map', 'ego_racecar/base_link', rclpy.time.Time()) 
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
            self.get_logger().error('TF2 exception') 
            return None
        
        vehicle_pos = trans.transform.translation 
        vehicle_yaw = math.atan2(trans.transform.rotation.z, trans.transform.rotation.w) * 2.0 
        #print('vx', vehicle_pos.x ,', vy', vehicle_pos.y)
        ang = 0
        vyaw = 0
        angdiff = 0
        for i in range(len(self.waypoints)): 
            p = self.waypoints[i].pose.position 
            dist = math.sqrt((vehicle_pos.x - p.x)**2 + (vehicle_pos.y - p.y)**2)
            angle = math.atan2(p.y - vehicle_pos.y, p.x - vehicle_pos.x) 
            angle_diff = math.atan2(math.sin(angle - vehicle_yaw), math.cos(angle - vehicle_yaw))
            
            #if dist < min_dist and dist > self.lookahead_dist and angle > vehicle_yaw: 
            if dist < min_dist and dist > self.lookahead_dist and abs(angle_diff) < math.pi/2:

                min_dist = dist 
                self.min_index = i 
                min_point = self.waypoints[i] #
                self.waypoint_index = i
                ang = angle
                angdiff = angle_diff
                vyaw = vehicle_yaw
                
        
        #print('Veh Yaw: ', vehicle_yaw)
        #print('Angle: ', angle)
        #print('Angle Diff: ', angle_diff)
        #print('Min_point: ', min_point)
        
        
        return min_point 
        
    def publish_markers(self):
        marker_array = MarkerArray()

        # Add markers to the MarkerArray
        for i in range(len(self.waypoints)):
            p = self.waypoints[i].pose.position
            marker = Marker()
            marker.header.frame_id = 'a1waypoint_map'
            marker.id = i
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            marker.pose.position.x = p.x
            marker.pose.position.y = p.y
            marker.pose.position.z = 0.0
            marker.scale.x = 0.5
            marker.scale.y = 0.5
            marker.scale.z = 0.5
            marker.color.a = 1.0
            marker.color.r = 0.0 
            marker.color.g = 1.0 
            marker.color.b = 0.0
            marker_array.markers.append(marker)

        self.markerarray_pub.publish(marker_array)   
    
    
    def load_waypoints(self, filename):
        with open(filename) as csvfile: 
            reader = csv.reader(csvfile) 
            i = 0
            for row in reader: 
                if i > 0:
                    x = float(row[0]) 
                    y = float(row[1]) 
                    z = float(0) 
                    waypoint = PoseStamped() 
                    waypoint.header.frame_id = 'map' 
                    waypoint.pose.position.x = x 
                    waypoint.pose.position.y = y 
                    waypoint.pose.position.z = z
                    waypoint.pose.orientation.w = 1.0 
                    self.waypoints.append(waypoint) 
                    
                i += 1
                
        self.publish_markers()
      
      
def main(args=None):
    rclpy.init(args=args) 
    node = PurePursuitNode() 
    rclpy.spin(node) 
    rclpy.shutdown() 

if __name__ == '__main__':
    main() 

