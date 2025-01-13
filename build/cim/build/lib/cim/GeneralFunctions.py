import time
import numpy as np
import scipy.interpolate as interp
import math
import random as rnd

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import Pose, PoseStamped
from visualization_msgs.msg import Marker, MarkerArray
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

#Import DSRC Message Package
from dsrcmsg.msg import DSRCMessage, MySpeed

#import local packages
from cim.DisparityExtenderObstacleAvoidance import DisparityExtender
from cim.PurePursuit import PurePursuitPlanner


class CIMGeneralFunctions(Node):
    """
        General/Support Functions for Autonomous Vehicle Controller with DSRC-Based Cooperative Intersection Management Capabilities
        
    """

    def __init__(self):
        """" 
        Initialize the topics, publishers and subscribers
        """
        super().__init__("GeneralFunctions")
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
    
    def PublishVehicleSpeed(self, publisher, speed):
        ##Given an instatiated publisher, publish the desired speed or vehicle
        vehSpeed = MySpeed()
        vehSpeed.vehicleid = vehID
        vehSpeed.speed = speed
        publisher.publish(vehSpeed)
        
        
    def PublishDSRCMsg(self, vehid, appLeg, deptLeg, distTo, distFro, speed):
        #print(self.initialTime)
        
        dsrcmsg = DSRCMessage()
        dsrcmsg.vehicleid = vehid
        dsrcmsg.initialtime = self.initialTime
        dsrcmsg.currenttime =  time.time()
        dsrcmsg.approachleg = appLeg
        dsrcmsg.departureleg = deptLeg
        dsrcmsg.disttostopline = distTo
        dsrcmsg.distfromstopline = distFro 
        dsrcmsg.speed = speed
        self.dsrcPublisher.publish(dsrcmsg)
        
    def CalculateDistance(self, x1, y1, x2, y2):
        """
            (x1, y1) is the vehicle point
            (x2, y2) is the stop line (critical point)
        """
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)  
        
    def GetStopLineDistance(self, vehX, vehY, agentPath):
        """
            This function sets the next stop line, approachLeg and departureLeg Names based on the closest distance to the stop 
            line point given an agentPath Name. It may be tweek and extended to work with any map such Google map.
            However, for the purpose of this static map, the following is used for all the junctions and approach legs in the map.
        """
        #South-West Junction: West-East flow stop line is (4.5,6.2); North-South flow stop line is (4.6, 6)
        #South-East Junction: West-East flow stop line is (4.5, -0.65); South-North flow stop line is (4.35, -0.85)
        #North-East Junction: East-West flow stop line is (15.3, -1); South-North flow stop line is (15.15, -0.85)
        #North-West Junction: East-West flow stop line is (15.3, 5.85); South-North flow stop line is (15.4, 6)
        dist = None
        junc = None
        appLegs = None
        deptLegs = None
        appLeg = None
        deptLeg = None
        stopLinePoints = None
        pt = None
        
        
        # Initialize a variable to store the minimum distance
        minDist = math.inf
        if agentPath == 'NS':
            appLegs = ['SNJ1', 'SNJ2', 'NSJ3', 'NSJ4'] 
            deptLegs = ['J1SN', 'J2SN', 'J3NS', 'J4NS']
            stopLinePoints = [(4.35, -0.85), (15.15, -0.85), (15.4, 6), (4.6, 6)]
        elif agentPath == 'WE':
            appLegs = ['WEJ4', 'WEJ1', 'EWJ2', 'EWJ3'] 
            deptLegs = ['J4WE', 'J1WE', 'J2EW', 'J3EW']
            stopLinePoints = [(4.5,6.2),  (4.5, -0.65), (15.3, -1), (15.3, 5.85)]
        
        for point, apl, dpl in zip(stopLinePoints, appLegs, deptLegs):
            # Calculate the distance between the point and the current point in the set
            dist = self.CalculateDistance(vehX, vehY, point[0], point[1])
            # Update the minimum distance if the current distance is smaller
            if dist < minDist:
                minDist = dist
                appLeg = apl
                deptLeg = dpl
                pt = point
                
        
        
        if minDist <= 5:
            #self.currStopLinePoint = pt
            #self.approachLeg = appLeg
            #self.departureLeg = deptLeg
            #return True
            return pt, appLeg, deptLeg
            
        else:
            return None, None, None
        #return minDist, flow 
        
    
    def GetVehiclePose(self, vehLink):
        """
            This function returns the current position and orientation of the vehicle
        """
        try:
            trans = self.tf_buffer.lookup_transform('map', vehLink, rclpy.time.Time()) 
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
        
        
    def CheckObstacle(self, scan):
        obsScan = np.where(scan < 0.5, True, False)
        #print(obsSubScan)
        if np.any(obsScan): #if there is any lidar ray that is less than or equal to 1, it implies an obstancle, thus we break 
            return True
        return False
        
    


def main(args=None):
    rclpy.init(args=args)
    print("General Functions")
    genNode = CIMGeneralFunctions()
    rclpy.spin(genNode)
    
    genNode.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()


