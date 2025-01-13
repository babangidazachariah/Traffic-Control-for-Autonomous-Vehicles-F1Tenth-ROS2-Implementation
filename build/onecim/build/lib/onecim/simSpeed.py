import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped
from sensor_msgs.msg import LaserScan
import tf2_ros
import math
import time

class StraightTrackingNode(Node):
    def __init__(self):
        super().__init__('straight_tracking_node')
        self.publisher_ = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        self.subscription_ = self.create_subscription(LaserScan, '/scan', self.drive_straight, 10)
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        self.speed = 1.0  # Default speed
        self.arrived = False
        self.start = 0
        self.startTime = None
        self.endTime = None
        self.initDist = 0.0
        self.finalDist = 0.0

    def GetVehiclePose(self):
        try:
            trans = self.tf_buffer.lookup_transform('map', 'ego_racecar/base_link', rclpy.time.Time()) 
            self.start += 1
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
            self.get_logger().error('TF2 exception: {}'.format(str(e))) 
            return None, None, None
        
        pose = trans.transform.translation 
        
        pose_theta = math.atan2(trans.transform.rotation.z, trans.transform.rotation.w) * 2.0 
        
        return pose.x, pose.y, pose_theta
        
    def CalculateDistance(self, x1, y1, x2, y2):
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)  
        
    def drive_straight(self, msg):
        if self.arrived:
            return

        drive_msg = AckermannDriveStamped()
        drive_msg.drive.speed = self.speed
        
        poseX, poseY, poseTheta = self.GetVehiclePose()
        if poseX is None:
            return
       
            
        dist = self.CalculateDistance(poseX, poseY, 1.01726, -0.787557)
        self.get_logger().info("Distance: {:.2f}".format(dist))
        if self.start == 1:
            print('Started')
            self.initDist = dist
            self.startTime = time.time()
            
        if dist <= 0.5:
            self.arrived = True
            drive_msg.drive.speed = 0.0  # Stop the vehicle once the distance is covered
            self.publisher_.publish(drive_msg)
            self.get_logger().info("Reached target distance.")
            self.endTime = time.time()
            print('initDist: ', self.initDist, ' finalDist: ', self.finalDist)
            print('Time taken: ', self.endTime - self.startTime)
            rclpy.shutdown()
            return

        self.publisher_.publish(drive_msg)

def main(args=None):
    rclpy.init(args=args)
    straight_tracking_node = StraightTrackingNode()
    rclpy.spin(straight_tracking_node)
    straight_tracking_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

