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
from geometry_msgs.msg import Pose, PoseStamped, Point

from visualization_msgs.msg import Marker, MarkerArray
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

#Import DSRC Message Package
from dsrcmsg.msg import DSRCMessage, TrafficLightsMessage
from trafficrecord.action import VehWaitTime, HybridCIM

#import local packages
from cim.DisparityExtenderObstacleAvoidance import DisparityExtender
from cim.PurePursuit import PurePursuitPlanner

"""
    This ewagent code made as snagent code for debugging purpose
    opp_drive and opp_scan were changed drive and scan
    opp_racecar was changed ego_racecar/base_link
    
    
    self.absDistStopLine was not being initialized early enough when the code begin execution
"""
class FISCIMEwagent(Node):
    """
        Autonomous Vehicle based on FIS-Based Hybrid (Centralized and Decentralized) 
        Control with DSRC-Based Cooperative Intersection Management Capabilities
        
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
        #self.timer = self.create_timer(0.005, self.DrivingControl)
        
        #Instantiate Disparity Extender Object
        self.disparityExtender = DisparityExtender()
        self.purePursuit = PurePursuitPlanner('/home/babangida/ros_ws/src/reactivemethods/weastopttrajwptsconstvelocity.csv', 'wepath', 'wepoint')
        self.speed = 1.0
        self.steerAngle = 0.0
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        
        #Create DSRCMessage publisher
        self.dsrcPublisher = self.create_publisher(DSRCMessage, '/dsrcmsg', 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        #Create DSRCMessage subscriber
        self.dsrcSubscriber = self.create_subscription(TrafficLightsMessage, '/tls', self.TlsBasedTrajectoryPlanning, 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        self.agentPath = 'WE'
        self.vehicleID = 'EW1' #North-South or South-North Number: SN1, SN2, ... NS1, NS2, ... Could be plate Number
        self.initialTime = None
        self.toFroStopLine = True #set to True when the vehicle is approaching stop line and at certain distance 
                                    #and false whent the vehicle has gone certain distance from the line
        self.atStopLine = False
        self.absDistStopLine = 0.
        self.MINSTOPLINEDIST = 3.0
        self.currStopLinePoint = None
        self.approachLeg = None
        self.departureLeg = None
        
        self.stopMe = False #Set to True in TlsBasedTrajectoryPlanning when self.approachLeg is not in the current traffic phase with green signal
        self.recmdedSpeed = 1.0
        self.vehAtCurJunction = {} #Used to maintain a python dictionary of vehicles at the current intersection vehicles are added for current intersection using DSRCMessage subscriber
        #Create DSRCMessage subscriber
        self.dsrcSubscriber = self.create_subscription(DSRCMessage, '/dsrcmsg', self.VehicleAtCurIntersection, 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        self.checkNextIntersection = True
        self.junction = 'EWJ2'
        self.point = Point()
        self.vehicleType = 1 # Based on vehicle type codes found at https://actar.org/pdf/ca_veh1.pdf
        
        #In standards such as DSRC and C-V2X, priority is not explicitly specified in a dedicated 
        #field like "priority level." Instead, it emerges from the negotiation process facilitated by the exchanged messages.
        self.vehiclePriority = 0 #Thus, we specify here our priority standard: 0 mean no priority. Higher values impliy higher priority
        
        
        self.isWaitingTimeRecorded = False #That is, traffic info is not sent and should be sent for the current intersection
        self.isPresenceRecorded = False
        
        self.trafficRecordClient = ActionClient(self, VehWaitTime, 'vehwaittime') #Action client for recording waiting time of vehicle at intersection
        self.registerPresenceClient = ActionClient(self, HybridCIM, 'hybridcim',) #Action client for registering vehicle presence at an intersection
        
        
    def GetTIRResult(self, future):
        result = future.result().result
        if result.recorded:
            self.isWaitingTimeRecorded = True
           
    def IsTrafficInfoRecorded(self, future):
        
        goalHandle = future.result()
        if not goalHandle.accepted:
            self.get_logger().info('Waiting Time Recording Goal rejected :(')
            self.isWaitingTimeRecorded = True #That is, trafficInfo was not accepted for recording and should be sent for the current intersection
            return

        #self.get_logger().info('Waiting Time Recording Goal accepted :)')
        self.isWaitingTimeRecorded = False #That is, trafficInfo was accepted for recording and shoul not be sent again for the current intersection
        self.getTIRResultFuture = goalHandle.get_result_async()
        self.getTIRResultFuture.add_done_callback(self.GetTIRResult)
    
    def RecordWaitingTime(self):
        #Sends vehicle waiting time at an intersection to the traffic record and analysis node
        trafficRecordMsg = VehWaitTime.Goal()
        trafficRecordMsg.approachleg = self.approachLeg
        trafficRecordMsg.waittime = time.time() - self.initialTime
        self.trafficRecordClient.wait_for_server()
        self.sendTrafficInfoFuture = self.trafficRecordClient.send_goal_async(trafficRecordMsg)
        self.sendTrafficInfoFuture.add_done_callback(self.IsTrafficInfoRecorded)
     
           
    def GetPRResult(self, future):
        result = future.result().result
        if result.recorded:
            self.isPresenceRecorded = True
    
    def IsPresenceRegistered(self, future):
        goalHandle = future.result()
        if not goalHandle.accepted:
            self.get_logger().info('Presence Registration Goal rejected :(')
            self.isPresenceRecorded = False #That is, trafficInfo was not accepted for recording and should be sent for the current intersection
            return

        #self.get_logger().info('Presence Registration Goal accepted :)')
        self.isPresenceRecorded = True #That is, trafficInfo was accepted for recording and shoul not be sent again for the current intersection
        self.getPRResultFuture = goalHandle.get_result_async()
        self.getPRResultFuture.add_done_callback(self.GetPRResult)
    
        
    def RegisterPresence(self):
        if not self.isPresenceRecorded:
            if self.initialTime is None:
                self.initialTime = time.time()
                
            regPresenceMsg = HybridCIM.Goal()
            regPresenceMsg.vehicleid = self.vehicleID
            regPresenceMsg.junction = self.junction
            regPresenceMsg.approachleg = self.approachLeg
            regPresenceMsg.departleg = self.departureLeg
            regPresenceMsg.arrivaltime = self.initialTime
            regPresenceMsg.point = self.point
            regPresenceMsg.speed = self.speed
            regPresenceMsg.vehicletype = self.vehicleType
            regPresenceMsg.priority = self.vehiclePriority
            
            self.isPresenceRecorded = True
            self.registerPresenceClient.wait_for_server()
            self.regPreInFuture = self.registerPresenceClient.send_goal_async(regPresenceMsg)
            self.regPreInFuture.add_done_callback(self.IsPresenceRegistered)
        
   
    def TlsBasedTrajectoryPlanning(self, tlsmsg):
        """
            Vehicle plans trajectory at the intersection based on traffic lights.
        """
        #print('tlsmsg.starttime: ', tlsmsg.starttime, '', self.initialTime)
        if tlsmsg.starttime is not None : # and self.initialTime is not None:
        
            #print('Path with Green: ', tlsmsg.pathids)
            
            if self.approachLeg not in tlsmsg.pathids : #Check to ensure the received tls message is for the vehicle path - vehicle path scheduled
                #check if this vehicle is at the stop line threshold
                #print('ewagent has Red:')
                #print('Agent Path: ', self.agentPath)
                #print('ApproachLeg: ', self.approachLeg)
                #print('Path with Green: ', tlsmsg.pathids)
                #poseX, poseY, poseTheta =self.GetVehiclePose()
                #dist = self.CalculateDistance(poseX, poseY, self.currStopLinePoint[0], self.currStopLinePoint[1])
                
                dur = time.time() - tlsmsg.starttime
                #print('absDistStopLine: ', self.absDistStopLine, ' Duration: ', dur)
                #if abs(self.absDistStopLine) < 1.5 and dur < (tlsmsg.duration - 3):
                
                #print('tlsmsg.duration: ', tlsmsg.duration, ' durtation: ', dur)
                if ((self.absDistStopLine > 0 and self.absDistStopLine < 1.5)):
                    print('SN Agent @ stop line: absDistStopLine=', self.absDistStopLine, ' duration: ', dur)
                    self.speed = 0.
                    self.stopMe = True
            else:
                #print('self.stopMe = False: ', tlsmsg.duration, ' durtation: ', dur)
                self.stopMe = False
                #print('ewagent has green')
                #print('Recommended Speed: ',tlsmsg.speed)
                self.recmdedSpeed = tlsmsg.speed 

    def DrivingControl(self):
        """
            
        """
        
        vehIn = False #variable to determine if there is vehicle in the intersection
        if self.stopMe is True: #self.stopMe is True ==> This vehicle has the Red Signal
            self.speed = 0.0
            #print('self.stopMe: ', self.stopMe)
            
        else: #self.stopMe is True ==> This vehicle has the Green Signal
            #Check other vehicles and decide whether to use recommended speed or sensors determined speed.
            for veh in self.vehAtCurJunction:
                if veh['distfromstopline'] < -0.5 and veh['approachleg'] != self.approachLeg: #A vehicle is already in the conflict zone, I should wait
                    vehIn = True
                    
        # In a way this is like forming car following flow at constant speed. 
        #However, it is not optimal as further away vehicles may not come faster
        #even when there no vehicles ahead of them.
        if vehIn is True:
            self.speed = 0.5
        else:
            if abs(self.steerAngle) > self.disparityExtender.GetStraightSteeringAngle():
                self.speed = 1.0 
            else:
                self.speed = self.recmdedSpeed
            
        #print('speed: ', self.speed)        
        self.PublishDriveCommand(self.steerAngle, self.speed)
                    
       
    def VehicleAtCurIntersection(self, msg):
        """
            Records vehicles at the current intersection of the this vehicle 
        """
        #ensure the current msg is not from this (the vehicle) but from other vehicles and that the messaging vehicle has the same approach leg as this veicle
        if msg.vehicleid != self.vehicleID and msg.approachleg == self.approachLeg:
            if msg.vehicleid not in self.vehAtCurJunction: #Vehicle has not been added to this vehicle's current intersection vehicular record
                self.vehAtCurJunction[msg.vehicleid].append({
                    
                    'initialtime': msg.initialtime,
                    'approachleg': msg.approachleg,
                    'departureleg': msg.departureleg,
                    'disttostopline': msg.disttostopline,
                    'distfromstopline': msg.distfromstopline,
                    'speed': msg.speed
    
                    
                })
            else: #Vehicle has been added to the record, just update the record
                for veh in self.vehAtCurJunction:
                    veh['approachleg'] = msg.approachleg #Allowed here in case vehicle are allowed changing lanes within intersection zones but just before conflict zone
                    veh['departureleg'] = msg.departureleg
                    veh['disttostopline'] = msg.disttostopline
                    veh['distfromstopline'] = msg.distfromstopline
                    veh['speed'] = msg.speed
                    
    
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
        dsrcmsg.point = self.point
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
        nextStopDetermined = False
        
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
                
        
        
        if minDist <= 4:
            self.currStopLinePoint = pt
            self.approachLeg = appLeg
            self.junction = appLeg
            self.departureLeg = deptLeg
            self.isPresenceRecorded = False
            nextStopDetermined = True
            print('NextJunction: ', appLeg)
        
        return nextStopDetermined 
        
    
    def StartStopDSRCMsgs(self, poseX, poseY, appLeg, deptLeg):
        
        dist = self.CalculateDistance(poseX, poseY, self.currStopLinePoint[0], self.currStopLinePoint[1])
        distFro = 1000 #initialized to an unreasonable large number so that if distFro < -self.MINSTOPLINEDIST: is only satisfied when it needs to
        print('Distance to stop line: ', dist)
        #print('status of toFroStopLine: ', self.toFroStopLine)
        if dist <= self.MINSTOPLINEDIST: #vehicle should be publishing DSRC Messages
            #Record vehicular presence at an intersection
            if not self.isPresenceRecorded:
                self.RegisterPresence()
                
            #print('Publishing DSRC Msg')
            #print('self.toFroStopLine(True)', self.toFroStopLine, ' Dist2Line: ', dist)
            if self.toFroStopLine: #If it true, vehicle is yet at the intersection or gone past intersection 
                self.toFroStopLine = False
                self.initialTime = time.time()
                
            #if vehicle is at the point or within a threshold distance that is approximated to the stop line point, assume it has gone past the point
            if dist <= 1:
                print('dist <= 1 setting atStopLine to True')
                self.atStopLine = True
                #print('Vehicle arrived at stop line')
                #self.speed = 0. #stop vehicle at the stop line
                
            else:
                
                distTo = dist 
                distFro = 1000. #or math.inf
                self.absDistStopLine = dist
            
            if self.atStopLine:
                distTo = 1000. #or math.inf
                distFro = -dist
                self.absDistStopLine = distFro
            
            #print('dist <= self.MINSTOPLINEDIST - self.absDistStopLine: ', self.absDistStopLine)
            self.PublishDSRCMsg(self.vehicleID, appLeg, deptLeg, distTo, distFro, self.speed)
            
            
        #if negative distance is less than the negative self.MINSTOPLINEDIST meaning vehicle has gone beyond the 
        #intersection and should stop publishing DSRC message or check the next intersection on the way.
        #print('Dist From Line: ', distFro)
        if self.atStopLine and -dist <= (-self.MINSTOPLINEDIST * 2):
        
            #Send trafficInfo to be recorded
            print('StartingRecordWaitingTime')
            self.RecordWaitingTime()
            print('FinishedRecordWaitingTime')
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
            
            self.point = [poseX, poseY] #np.array((poseX, poseY))
            if self.checkNextIntersection:
                #Check is vehicle is certain distance away from stop line
                if self.GetStopLineDistance(poseX, poseY, self.agentPath):
                    #print('checkNextIntersection')
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
        
        #print('ProcessLidar Speed: ', self.speed)
        
        adjSpeed = self.speed
        if self.CheckObstacle(fovScan):
            #print("ewagent::Disparity Extender Executing")
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
        #self.steerAngle = steerAngle
        #self.speed = adjSpeed
        
        #print('SteerAngle: ', steerAngle, ' adjSpeed: ', adjSpeed)
        self.PublishDriveCommand(steerAngle, adjSpeed)
        #self.PublishDriveCommand(self.disparityExtender.GetStraightSteeringAngle(), self.speed)


def main(args=None):
    rclpy.init(args=args)
    print("Cooperative Intersection Management Aware Controller Node for East-West Agent")
    cimController = FISCIMEwagent()
    rclpy.spin(cimController)
    
    cimController.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

