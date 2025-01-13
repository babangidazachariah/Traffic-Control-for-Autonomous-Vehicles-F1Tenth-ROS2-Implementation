import time
import pandas as pd
import numpy as np
import scipy.interpolate as interp
import math
import random as rnd

import matplotlib.pyplot as plt

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import Pose, PoseStamped, Point
from visualization_msgs.msg import Marker, MarkerArray
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

#Import DSRC Message Package
from dsrcmsg.msg import IntersectionBSM, TrafficLightsMessage, OneCIMTlsMsg, OneCIMKeypoints
from trafficrecord.action import VehWaitTime

#import local packages
from onecim.DisparityExtenderObstacleAvoidance import DisparityExtender
from onecim.PurePursuit import PurePursuitPlanner


class CIMAutonomousVehicle(Node):
    """
        Autonomous Vehicle Controller with DSRC-Based Cooperative Intersection Management Capabilities
        
    """

    def __init__(self):
        """" 
        Initialize the topics, publishers and subscribers
        """
        super().__init__("CIMAutonomousVehicleController")
        
       
        lidarScanTopic = "/opp_scan"
        self.lidarScanSubs = self.create_subscription(
                            LaserScan,
                            lidarScanTopic,
                            self.ProcessLidar,
                            10
                        )
                  
        #Instantiate Disparity Extender Object
        self.disparityExtender = DisparityExtender()
        self.purePursuit = PurePursuitPlanner('/home/babangida/ros_ws/src/onecim/paths/Processed/ew1wptsvelocityprofile.csv', 'snpath', 'snpoint')
   
    def GetFrontLidarScan(self, ranges, radPerPoint):
        # Number of laser rays in the scan
        num_ranges = len(ranges)

        # Angular resolution of the LiDAR scan
        #angle_increment = data.angle_increment

        # Center index of the LiDAR scan
        center_index = num_ranges // 2

        # 45 degrees to the left and right of the vehicle
        angle_range = math.radians(22.5)  # Convert degrees to radians
        num_points_to_the_side = int(angle_range / radPerPoint) #angle_increment)

        # Ranges in front of the vehicle (45 degrees to the left and right)
        ranges_front = ranges[center_index - num_points_to_the_side: center_index + num_points_to_the_side]

        # Process the ranges in front of the vehicle as needed
        #print("Ranges in front of the vehicle:", ranges_front)
        return ranges_front  
    """
    def plotLidar(self, ranges):
                
        # Assuming ranges is a list or numpy array containing the lidar scan ranges
        # and angles is a corresponding list or numpy array containing the angle values
        #ranges = np.random.rand(1081) * 10  # Random distances for demonstration
        angles = np.linspace(-np.pi*3/4, np.pi*3/4, len(ranges))  # Angle values from -3pi/4 to 3pi/4

        # Convert polar coordinates to Cartesian coordinates
        x = ranges * np.cos(angles)
        y = ranges * np.sin(angles)

        # Plot lidar scan starting from the origin
        plt.figure(figsize=(8, 6))
        plt.plot(x, y, c='blue')  # Plot lidar scan
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.title('Lidar Scan')
        plt.grid(True)
        plt.axis('equal')  # Set aspect ratio to be equal
        plt.show()
    """
    
    def plotLidar(self, ranges):
        # Define the angles corresponding to the full ranges
        full_angles = np.linspace(-np.pi*3/4, np.pi*3/4, len(ranges))

        # Convert polar coordinates to Cartesian coordinates for full ranges
        full_x = ranges * np.cos(full_angles)
        full_y = ranges * np.sin(full_angles)

        # Define the subset of angles corresponding to the ranges to the left and right of the center
        center_index = len(full_angles) // 2
        left_start = center_index - 67
        left_end = center_index
        right_start = center_index + 1
        right_end = center_index + 68

        # Slice the full ranges to obtain the left and right subsets
        left_ranges = ranges[left_start:left_end]
        left_angles = full_angles[left_start:left_end]
        right_ranges = ranges[right_start:right_end]
        right_angles = full_angles[right_start:right_end]

        # Convert polar coordinates to Cartesian coordinates for the left and right subsets
        left_x = left_ranges * np.cos(left_angles)
        left_y = left_ranges * np.sin(left_angles)
        right_x = right_ranges * np.cos(right_angles)
        right_y = right_ranges * np.sin(right_angles)

        # Plot lidar scan starting from the origin
        plt.figure(figsize=(8, 6))
        plt.plot(full_x, full_y, c='blue', label='Full Scan')  # Plot full lidar scan
        plt.plot(left_x, left_y, c='red', label='Left Scan')  # Plot left lidar scan
        plt.plot(right_x, right_y, c='green', label='Right Scan')  # Plot right lidar scan
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.title('Lidar Scan')
        plt.grid(True)
        plt.axis('equal')  # Set aspect ratio to be equal
        plt.legend()  # Show legend
        plt.show()

    def ProcessLidar(self, data):
        radPerPoint = (2*np.pi)/len(data.ranges)
        frontLidarScan = np.array(self.GetFrontLidarScan(data.ranges,radPerPoint))
        print('radperpoint: ', radPerPoint)
        print('full length: ', len(data.ranges))
        print('length: ', len(frontLidarScan))
        print(frontLidarScan)
        print('percentage: ', np.sum(frontLidarScan < 1.0)/(len(frontLidarScan)))
        self.plotLidar(np.array(data.ranges))
        time.sleep(50)
        
def main(args=None):
    rclpy.init(args=args)
    print("Hybrid Cooperative Intersection Management Aware South-North Controller Node")
    cimController = CIMAutonomousVehicle()
    rclpy.spin(cimController)
    
    cimController.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

