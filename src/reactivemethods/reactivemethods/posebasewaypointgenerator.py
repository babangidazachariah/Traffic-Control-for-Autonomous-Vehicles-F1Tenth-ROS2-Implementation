#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import csv
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Pose


class WaypointGenerator(Node):

    def __init__(self, filename):
        super().__init__('waypoint_generator')
        self._sub_pose = self.create_subscription(
            PoseStamped,
            '/goal_pose',
            self._process_pose,
            10
        )
        # Subscribe to odometry topic to get the current pose
        self.odom_subscriber = self.create_subscription(
            Odometry, 
            '/ego_racecar/odom', 
            self.odom_callback, 10
        )
        
        
        
        self.goal_pose = Pose()
        self._filename = filename
        self._file = open(self._filename, 'w', newline='')
        self._csv_writer = csv.writer(self._file)
        self.count = 0

    def _process_pose(self, msg):
        p = msg.pose

        d#ata = [p.position.x, p.position.y, p.position.z]
        #self._csv_writer.writerow(data)
        self.get_logger().info(f'Clicked: ({p.position.x}, {p.position.y}, {p.position.z})')
        
    def odom_callback(self, odom_msg):
        if self.count == 0:
            self._csv_writer.writerow(['x', 'y'])
            self.count += 1
            
        # Extract current position (x, y) from the odometry message
        current_x = odom_msg.pose.pose.position.x
        current_y = odom_msg.pose.pose.position.y
        self._csv_writer.writerow([current_x, current_y])

    def spin(self):
        rclpy.spin(self)
        self._file.close()
        self.get_logger().info(f'Waypoints saved to {self._filename}')


def main(args=None):
    rclpy.init(args=args)
    filename = 'wetwoloop.csv'
    waypoint_generator = WaypointGenerator(filename)
    waypoint_generator.get_logger().info('Initialized')
    waypoint_generator.spin()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
