import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import PoseStamped, Point
from visualization_msgs.msg import Marker, MarkerArray
import csv
import numpy as np
import tf2_ros
import math

class PurePursuit(Node):
    def __init__(self, path_file, lookahead_distance=2.0, max_steering_angle=25.0, smoothing_alpha=0.2):
        super().__init__('pure_pursuit_node')
        
        self.wheelbase = 0.3302

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.path = self.load_path(path_file)
        self.lookahead_distance = lookahead_distance
        self.max_steering_angle = np.radians(max_steering_angle)
        self.speed = 0.5

        self.drive_publisher = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        self.path_publisher = self.create_publisher(MarkerArray, '/path', 10)
        self.waypoint_publisher = self.create_publisher(MarkerArray, 'visualization_marker_array', 10)

        # Smoothing parameters
        self.smoothing_alpha = smoothing_alpha
        self.previous_steering_angle = 0.0
        self.steering_angle = 0.0
        # Publish path and waypoint markers
        self.publish_path_markers()

    def load_path(self, file_path):
        waypoints = []

        with open(file_path, 'r') as file:
            reader = csv.reader(file)
            next(reader)  # Skip the first row

            for row in reader:
                x, y = map(float, row)
                waypoints.append((x, y))

        return waypoints

    def get_robot_pose(self):
        """
            returns pose_theta angle of rotation z and w
                as well as pose_stamp based on translation x and y
        """
        try:
            transform_stamped = self.tf_buffer.lookup_transform('map', 'ego_racecar/base_link', rclpy.time.Time())
            
            pose_theta = math.atan2(transform_stamped.transform.rotation.z, transform_stamped.transform.rotation.w) * 2.0 
        
            pose_stamped = PoseStamped()
            pose_stamped.header = transform_stamped.header
            pose_stamped.pose.position.x = transform_stamped.transform.translation.x
            pose_stamped.pose.position.y = transform_stamped.transform.translation.y
            return pose_theta, pose_stamped
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
            self.get_logger().warn("Error getting robot pose")
            return None, None

    def find_closest_point(self, current_pose):
        closest_point_index = np.argmin(
            [np.linalg.norm(np.array(current_pose) - np.array(point)) for point in self.path]
        )
        return closest_point_index

    def find_lookahead_point(self, current_pose):
        closest_point_index = self.find_closest_point((current_pose.pose.position.x, current_pose.pose.position.y))

        while True:
            distance = np.linalg.norm(
                np.array(self.path[closest_point_index]) - np.array([current_pose.pose.position.x, current_pose.pose.position.y])
            )

            if distance > self.lookahead_distance or closest_point_index == len(self.path) - 1:
                break

            closest_point_index += 1

        lookahead_point = np.array(self.path[closest_point_index])
        heading_vector = lookahead_point - np.array([current_pose.pose.position.x, current_pose.pose.position.y])
        heading_angle = np.arctan2(heading_vector[1], heading_vector[0])

        if np.abs(heading_angle) > np.radians(90):
            closest_point_index -= 1
            lookahead_point = np.array(self.path[closest_point_index])

        return lookahead_point

    def set_steering_angle(self, pose_theta, lookahead_point, position):
        """
        Returns actuation
        """
        #position = lookahead_point - curr_position
        ref_point = lookahead_point[0:2] - position
        print('Ref Point: ', ref_point)
        # Extract the Waypoint information
        waypoint_y = np.dot(np.array([np.sin(-pose_theta), np.cos(-pose_theta)]), lookahead_point[0:2] - ref_point)
        #self.speed = lookahead_point[2]
        if np.abs(waypoint_y) < 1e-6:
            self.steering_angle = 0.0
        # Define the radius of the arc to follow
        radius = 1 / (2.0 * waypoint_y / self.lookahead_distance ** 2)

        # Calculate the steering angle based on the curvature of the arc to follow
        steering_angle = np.arctan(self.wheelbase / radius)

        self.steering_angle = steering_angle 
        
   
    def calculate_steering(self, current_pose, lookahead_point):
        y = lookahead_point[1] - current_pose.pose.position.y 
        r = np.linalg.norm(np.array(lookahead_point) - np.array([current_pose.pose.position.x, current_pose.pose.position.y]))

        # Avoid division by zero
        if r == 0:
            return 0.0

        steering_angle = (2 * y) / (r ** 2)
        
        
        # Apply low-pass filter for smoothing
        smoothed_steering_angle = self.smoothing_alpha * steering_angle #+ (1 - self.smoothing_alpha) * self.previous_steering_angle

        # Update the previous steering angle for the next iteration
        self.previous_steering_angle = smoothed_steering_angle

        return np.clip(smoothed_steering_angle, -self.max_steering_angle, self.max_steering_angle)

    def publish_drive_command(self, steering_angle, speed=0.5):
        drive_msg = AckermannDriveStamped()
        drive_msg.header.stamp = self.get_clock().now().to_msg()
        drive_msg.drive.steering_angle = steering_angle
        drive_msg.drive.speed = speed
        self.drive_publisher.publish(drive_msg)

    def publish_marker_array(self, marker_array, publisher):
        for marker in marker_array.markers:
            marker.header.stamp = self.get_clock().now().to_msg()

        publisher.publish(marker_array)

    def publish_path_markers(self):
        path_marker_array = MarkerArray()

        for i in range(len(self.path) - 1):
            marker = Marker()
            marker.header.frame_id = 'map'
            marker.id = i
            marker.type = Marker.LINE_STRIP
            marker.action = Marker.ADD
            marker.points.append(Point(x=self.path[i][0], y=self.path[i][1], z=0.0))
            marker.points.append(Point(x=self.path[i + 1][0], y=self.path[i + 1][1], z=0.0))
            marker.scale.x = 0.02  # Line width
            marker.color.a = 1.0
            marker.color.r = 0.0
            marker.color.g = 0.0
            marker.color.b = 1.0
            path_marker_array.markers.append(marker)

        self.publish_marker_array(path_marker_array, self.path_publisher)

    def publish_waypoint_markers(self, lookahead_point):
        waypoint_marker_array = MarkerArray()

        marker = Marker()
        marker.header.frame_id = 'map'
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.pose.position.x = lookahead_point[0]
        marker.pose.position.y = lookahead_point[1]
        marker.pose.position.z = 0.0
        marker.scale.x = 0.1  # Sphere diameter
        marker.scale.y = 0.1
        marker.scale.z = 0.1
        marker.color.a = 1.0
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.0
        waypoint_marker_array.markers.append(marker)

        self.publish_marker_array(waypoint_marker_array, self.waypoint_publisher)

    def run_pure_pursuit(self):
        pose_theta, current_pose = self.get_robot_pose()
        if current_pose is not None and pose_theta is not None:
            lookahead_point = self.find_lookahead_point(current_pose)
            curr_position = np.array([current_pose.pose.position.x, current_pose.pose.position.y])
            print('Current Position',curr_position)
            print('Lookahead Point:',lookahead_point)
            
            #steering_angle = self.calculate_steering(current_pose, lookahead_point)
            self.set_steering_angle(pose_theta,lookahead_point, curr_position)
            self.publish_drive_command(steering_angle=self.steering_angle, speed=self.speed)

            # Publish path and waypoint markers
            self.publish_path_markers()
            self.publish_waypoint_markers(lookahead_point)

def main(args=None):
    rclpy.init(args=args)
    #'/home/babangida/ros_ws/Spielberg_centerline.csv'  
    #'/home/babangida/ros_ws/northsouth2d.csv'
    path_file = '/home/babangida/ros_ws/northsouth2d.csv'  
    pure_pursuit = PurePursuit(path_file, lookahead_distance=1.5, max_steering_angle=25.0, smoothing_alpha=0.3)

    try:
        while rclpy.ok():
            pure_pursuit.run_pure_pursuit()
            rclpy.spin_once(pure_pursuit, timeout_sec=0.1)

    finally:
        pure_pursuit.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
