"""
staticTrafficLightSouthNorthAgent (stlssnagent.py)
"""
import time
import numpy as np
import scipy.interpolate as interp
import math
import random as rnd

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import Pose, PoseStamped
from visualization_msgs.msg import Marker, MarkerArray
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

#Import DSRC Message Package
from dsrcmsg.msg import DSRCMessage, TrafficLightsMessage
from trafficrecord.action import VehWaitTime

#import local packages
from cim.DisparityExtenderObstacleAvoidance import DisparityExtender
from cim.PurePursuit import PurePursuitPlanner


class CIMAutonomousVehicle(Node):
    """
        Autonomous Vehicle Controller with DSRC-Based Cooperative Intersection Management Capabilities
        
    """

    def __init__(self):
        """" 
        Initialize the topics, publishers and subscribers
        """
        super().__init__("CIMAutonomousVehicleController")
        lidarScanTopic = "/scan"
        driveTopic = "/drive"
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
        #Instantiate Disparity Extender Object
        self.disparityExtender = DisparityExtender()
        self.purePursuit = PurePursuitPlanner('/home/babangida/ros_ws/src/reactivemethods/nsouthopttrajwptsconstvelocity.csv', '/nspath', '/nspoint')
        self.speed = 1.0
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        
        #Create DSRCMessage publisher
        self.dsrcPublisher = self.create_publisher(DSRCMessage, '/dsrcmsg', 10) #qos_profile=rclpy.qos.qos_profile_system_default)
        #Create DSRCMessage subscriber
        self.dsrcSubscriber = self.create_subscription(TrafficLightsMessage, '/tls', self.StlsBasedTrajectoryPlanning, 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        self.agentPath = 'NS'
        self.vehicleID = 'SN1' #North-South or South-North Number: SN1, SN2, ... NS1, NS2, ... Could be plate Number
        self.initialTime = None
        self.toFroStopLine = True #set to True when the vehicle is approaching stop line and at certain distance 
                                    #and false whent the vehicle has gone certain distance from the line
        self.atStopLine = False
        self.absDistStopLine = 0.0    
        self.MINSTOPLINEDIST = 3.0
        self.currStopLinePoint = None
        self.approachLeg = None
        self.departureLeg = None
        self.checkNextIntersection = True
        
        self.prevPathIds = None
        self.sendTrafficInfo = True #That is, traffic info is not sent and should be sent for the current intersection
        
        self.trafficRecordClient = ActionClient(self, VehWaitTime, 'vehwaittime')
        self.tlsmsgIdx = 0 #Used for debugging synchronization between tls and agent
        
    def GetTIRResult(self, future):
        result = future.result().result
        if result.recorded:
            self.sendTrafficInfo = True
            
    def IsTrafficInfoRecorded(self, future):
        
        goalHandle = future.result()
        if not goalHandle.accepted:
            self.get_logger().info('Goal rejected :(')
            self.sendTrafficInfo = True #That is, trafficInfo was not accepted for recording and should be sent for the current intersection
            return

        #self.get_logger().info('Goal accepted :)')
        self.sendTrafficInfo = False #That is, trafficInfo was accepted for recording and shoul not be sent again for the current intersection
        self.getTIRResultFuture = goalHandle.get_result_async()
        self.getTIRResultFuture.add_done_callback(self.GetTIRResult)
        
    def SendTrafficInfo(self):
        #Sends vehicle waiting time at an intersection to the traffic record and analysis node
        trafficRecordMsg = VehWaitTime.Goal()
        trafficRecordMsg.approachleg = self.approachLeg
        trafficRecordMsg.waittime = time.time() - self.initialTime
        self.trafficRecordClient.wait_for_server()
        self.sendTrafficInfoFuture = self.trafficRecordClient.send_goal_async(trafficRecordMsg)
        self.sendTrafficInfoFuture.add_done_callback(self.IsTrafficInfoRecorded)
        
    def IsStopLineAhead(self,vx, vy,  sx, sy):
        """
            Detemines if a point (sx, sy) is ahead of (vx, vy) of a vehicle position
        """
        isahead = False
        vPoint = np.array([vx, vy])
        sLPoint = np.array([sx, sy])
        hVector = sLPoint - vPoint
        vAngle = np.arctan2(hVector[1], hVector[0])
        
        # Check if the vAngle is less than pi/2 (90 degrees), indicating that the stop line point (sx,sy) is ahead of the vehicle
        if vAngle > np.radians(90):
            print("The point is ahead of the vehicle.")
            isahead = True
        else:
            print("The point is not ahead of the vehicle.")
            isahead = False
        return isahead
        
        
    def StlsBasedTrajectoryPlanning(self, tlsmsg):
        """
            Vehicle plans trajectory at the intersection based on traffic lights.
        """
        #print('self.tlsmsgIdx:', self.tlsmsgIdx)
        
        if tlsmsg.starttime is not None and self.initialTime is not None:
            if self.approachLeg not in tlsmsg.pathids : #Check to ensure the received tls message is for the vehicle path - vehicle path scheduled
                #check if this vehicle is at the stop line threshold
                #print('Path IDs: ', tlsmsg.pathids)
                #poseX, poseY, poseTheta =self.GetVehiclePose()
                #dist = self.CalculateDistance(poseX, poseY, self.currStopLinePoint[0], self.currStopLinePoint[1])
                dur = time.time() - tlsmsg.starttime
                #print('absDistStopLine: ', self.absDistStopLine, ' Duration: ', dur)
                #if abs(self.absDistStopLine) < 1.5 and dur < (tlsmsg.duration - 3):
                #print('rem dur: ', tlsmsg.duration - dur)
                #print('Dist2Lin: ', dist) #self.absDistStopLine)
                #print('ApproLeg: ', self.approachLeg)
                #isahead = self.IsStopLineAhead(poseX, poseY, self.currStopLinePoint[0], self.currStopLinePoint[1])
                
                #if (tlsmsg.duration - dur) < 5 and dist < 1.0 and isahead is True:
                #if dist < 2.0 and isahead is True:
                if ((self.absDistStopLine > 0 and self.absDistStopLine < 1.5)): # or (self.absDistStopLine < 0 and self.absDistStopLine > -0.5)):
                    #if dist < 1.0:
                        print('SN Agent @ stop line: absDistStopLine=', self.absDistStopLine, ' duration: ', dur)
                        self.speed = 0.
                    #else:
                    #    self.speed = 1.0
                #else:
                #    self.speed = 1.0
            else:
                self.speed = 1.0
        self.tlsmsgIdx += 1
        
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
            stopLinePoints = [(4.0, -0.85), (14.7, -0.85), (15.7, 6), (4.95, 6)] #[(4.35, -0.85), (15.15, -0.85), (15.4, 6), (4.6, 6)]
        elif agentPath == 'WE':
            appLegs = ['WEJ4', 'WEJ1', 'EWJ2', 'EWJ3'] 
            deptLegs = ['J4WE', 'J1WE', 'J2EW', 'J3EW']
            stopLinePoints = [(4.5,6.5),  (4.5, -0.25), (15.3, -1.25), (15.3, 5.55)] #[(4.5,6.2),  (4.5, -0.65), (15.3, -1), (15.3, 5.85)]
        
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
            self.currStopLinePoint = pt
            self.approachLeg = appLeg
            self.departureLeg = deptLeg
            return True
            
        else:
            return False
        #return minDist, flow 
        
    
    def StartStopDSRCMsgs(self, poseX, poseY, appLeg, deptLeg):
        
        dist = self.CalculateDistance(poseX, poseY, self.currStopLinePoint[0], self.currStopLinePoint[1])
        distFro = 1000 #initialized to an unreasonable large number so that if distFro < -self.MINSTOPLINEDIST: is only satisfied when it needs to
        #print('Distance to stop line: ', dist)
        #print('status of toFroStopLine: ', self.toFroStopLine)
        if dist <= self.MINSTOPLINEDIST: #vehicle should be publishing DSRC Messages
            #print('Publishing DSRC Msg')
            if self.toFroStopLine: #If it true, vehicle is yet at the intersection or gone past intersection 
                self.toFroStopLine = False
                self.initialTime = time.time()
                
            #if vehicle is at the point or within a threshold distance that is approximated to the stop line point, assume it has gone past the point
            if dist <= 1:
                
                self.atStopLine = True
                #print('Vehicle arrived at stop line')
                #self.speed = 0. #stop vehicle at the stop line
                
            else:
                
                distTo = dist 
                distFro = 1000. #or math.inf
                self.absDistStopLine = distTo
            
            if self.atStopLine:
                distTo = 1000. #or math.inf
                distFro = -dist
                self.absDistStopLine = distFro
            
            #print('Dist to Line: ', distTo)
            self.PublishDSRCMsg(self.vehicleID, appLeg, deptLeg, distTo, distFro, self.speed)
            
            
        #if negative distance is less than the negative self.MINSTOPLINEDIST meaning vehicle has gone beyond the 
        #intersection and should stop publishing DSRC message or check the next intersection on the way.
        #print('Dist From Line: ', distFro)
        if self.atStopLine and -dist <= (-self.MINSTOPLINEDIST * 2):
            #Send trafficInfo to be recorded
            self.SendTrafficInfo()
            
            self.checkNextIntersection = True
            self.toFroStopLine = True
            self.atStopLine = False
            #self.absDistStopLine = 0.
            #print('Distance from stop line: ', distFro)
        else:
            self.checkNextIntersection = False
            
           
    def PublishDriveCommand(self, steerAngle=0.0, speed=0.0):
        
        #Prepare parameters for driving the vehicle
        driveMsg = AckermannDriveStamped()
        #driveMsg.header = data.header
        driveMsg.drive.steering_angle = steerAngle
        driveMsg.drive.speed = speed
        self.drivePubs.publish(driveMsg)
        
    def GetVehiclePose(self):
        """
            This function returns the current position and orientation of the vehicle
        """
        try:
            trans = self.tf_buffer.lookup_transform('map', 'ego_racecar/base_link', rclpy.time.Time()) 
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
        
    def ProcessLidar(self, data):
        #Get Vehicle Pose details
        poseX, poseY, poseTheta = self.GetVehiclePose()
        if poseX is not None:
            if self.checkNextIntersection:
                #Check is vehicle is certain distance away from stop line
                if self.GetStopLineDistance(poseX, poseY, self.agentPath):
                    self.checkNextIntersection = False
                    #print('Next Intersection is: ', self.approachLeg)
                #else:
                    #print('stop line: ',self.currStopLinePoint)
                    #print('Veh posit: ', poseX, ', ', poseY)
            else:
                # poseX, poseY, appLeg, deptLeg
                self.StartStopDSRCMsgs(poseX, poseY, self.approachLeg, self.departureLeg)
            
        #Determine if there are obstacles in front
        radPerPoint = (2*np.pi)/len(data.ranges)
        fovScan = self.GetFieldOfView(data.ranges)
        adjSpeed = self.speed
        if self.CheckObstacle(fovScan):
            #print("Disparity Extender Executing")
            #Obstacle exist in front of vehicle, thus activate the Obstacle avoidance controller (DistaparityExtender)
            steerAngle = self.disparityExtender.GetDisparityExtenderSteerAngle(fovScan, radPerPoint)
            if abs(steerAngle) > self.disparityExtender.GetStraightSteeringAngle():
                #self.speed = 1.
                adjSpeed = 1.
                #print(self.speed)
            else:
                adjSpeed = self.speed * 1.7
            self.PublishDriveCommand(steerAngle, self.speed)
            
        else: 
            #No obstacle, activate Pure Pursuit algorithm
            #print("Pure Pursuit Executing")
            spd, steerAngle = self.purePursuit.plan(pose_x=poseX, pose_y=poseY, pose_theta=poseTheta)
            adjSpeed = self.speed * 2.7
        #print(adjSpeed)    
        self.PublishDriveCommand(steerAngle, adjSpeed)
        #self.PublishDriveCommand(self.disparityExtender.GetStraightSteeringAngle(), self.speed)


def main(args=None):
    rclpy.init(args=args)
    print("Static TLS Intersection Management Aware Controller Node")
    cimController = CIMAutonomousVehicle()
    rclpy.spin(cimController)
    
    cimController.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

