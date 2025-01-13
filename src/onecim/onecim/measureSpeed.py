import time
import pandas as pd
import numpy as np
import scipy.interpolate as interp
import math
import random as rnd

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
    

    def __init__(self):
        """" 
        Initialize the topics, publishers and subscribers
        """
        super().__init__("CIMAutonomousVehicleController")
        
        lidarScanTopic = "/opp_scan"
        driveTopic = "/opp_drive"
        
        self.lidarScanSubs = self.create_subscription(
                            LaserScan,
                            lidarScanTopic,
                            self.ProcessLidar,
                            10
                        )
                        
        self.drivePubs = self.create_publisher(
                            AckermannDriveStamped,
                            driveTopic,
                            10
                        )
        self.drivePubss = self.create_publisher(
                            AckermannDriveStamped,
                            '/drive',
                            10
                        )
        
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        
        
        self.getPosition = False
        self.measured = 0
        self.timer = self.create_timer(1, self.MeasureSpeed)
        
      
        
    def GetVehiclePose(self):
        """
            This function returns the current position and orientation of the vehicle
        """
        try:
            trans = self.tf_buffer.lookup_transform('map', 'opp_racecar/base_link', rclpy.time.Time()) 
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
            self.get_logger().error('TF2 exception') 
            return None, None, None
        
        pose = trans.transform.translation 
        
        pose_theta = math.atan2(trans.transform.rotation.z, trans.transform.rotation.w) * 2.0 
        
        return pose.x, pose.y, pose_theta
        
        
    def PreProcessLidarScan(self, ranges, kind='linear', const=-10):
        """
            This function preprocesses lidar scan to eliminte NAN and INF values using either linear or cubic interpolation
            Also, a constant may be used.
        """
        # Convert the laser scan message to a numpy array
        arr = np.array(ranges)
        
        if const == -10:
            
            # Get the indices of the valid and invalid values
            valid_idx = np.where(np.isfinite(arr))[0]
            invalid_idx = np.where(np.isnan(arr) | np.isinf(arr))[0]
            # Create an array of angles corresponding to the lidar ranges
            angles = np.linspace(msg.angle_min, msg.angle_max, len(arr))
            # Perform linear interpolation on the invalid values
            # You can change the kind argument to 'cubic' for cubic interpolation
            f = interp.interp1d(angles[valid_idx], arr[valid_idx], kind='linear', fill_value='extrapolate')
            arr[invalid_idx] = f(angles[invalid_idx])
        else:
            # Replace the NAN or INF values with zeros
            arr[np.isnan(arr) | np.isinf(arr)] = const
        return arr
        
    def GetFieldOfView(self, ranges):
        """"
            Slices the Lidar ranges to focus on the front field of view (135 : -135) degrees
        """
        #preprocess to remove NAN and INF readings
        
        # remove quadrant of LiDAR directly behind us
        eighth = int(len(ranges)/8)
        
        #preprocess the focused field of view
        fov = self.PreProcessLidarScan(ranges[eighth:-eighth], const=10)
        return fov #np.array(ranges[eighth:-eighth])
        
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
            
        
    def CheckObstacle(self, scan, gap):
        obsScan = np.where(scan < gap, True, False)
        #print(obsSubScan)
        if np.any(obsScan): #if there is any lidar ray that is less than or equal to 1, it implies an obstancle, thus we break 
            return True
        return False
    
    def DriveCMD(self, steerAngle, speed, pub):
        #Prepare parameters for driving the vehicle
        driveMsg = AckermannDriveStamped()
        #driveMsg.header = data.header
        driveMsg.drive.steering_angle = steerAngle
        driveMsg.drive.speed = speed
        pub.publish(driveMsg)
     
    def MeasureSpeed(self):
        #Get Vehicle Pose details
        poseX, poseY, poseTheta = self.GetVehiclePose()
        print('A Second:')
        if poseX is not None:
            print('x: ', poseX, ' y: ', poseY)
            self.getPosition = True
            self.DriveCMD(0.0, 1.0, self.drivePubs)
            x, y, t = self.GetVehiclePose()
            print('x: ', x, ' y: ', y)
            self.measured += 1
        if self.measured >= 2:
            rclpy.shutdown()
    def ProcessLidar(self, data):
                   
        if not self.getPosition:    
            print('self.getPosition')
            self.DriveCMD(0.0, 1.0, self.drivePubs)
            self.DriveCMD(0.0, 1.0, self.drivePubss)
            
        #self.PublishDriveCommand(self.disparityExtender.GetStraightSteeringAngle(), self.speed)


def main(args=None):
    rclpy.init(args=args)
    print("Hybrid Cooperative Intersection Management Aware East-West Controller Node")
    cimController = CIMAutonomousVehicle()
    rclpy.spin(cimController)
    
    cimController.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

