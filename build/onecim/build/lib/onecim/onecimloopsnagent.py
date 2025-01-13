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
    """
        Autonomous Vehicle Controller with DSRC-Based Cooperative Intersection Management Capabilities
        
    """

    def __init__(self):
        """" 
        Initialize the topics, publishers and subscribers
        """
        super().__init__("CIMAutonomousVehicleController")
        
        lidarScanTopic = "/scan"
        self.lidarScanSubs = self.create_subscription(
                            LaserScan,
                            lidarScanTopic,
                            self.ProcessLidar,
                            10
                        )
                        
        driveTopic = "/drive"                
        self.drivePubs = self.create_publisher(
                            AckermannDriveStamped,
                            driveTopic,
                            10
                        )
        #Instantiate Disparity Extender Object
        self.disparityExtender = DisparityExtender()
        self.purePursuit = PurePursuitPlanner('/home/babangida/ros_ws/src/onecim/paths/Processed/sw0wptsvelocityprofile.csv', 'snpath', 'snpoint')
        
        self.speed = 1.0
        self.recmdedSpeed = 1.0
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        
        #Create IntersectionBSM publisher
        self.dsrcPublisher = self.create_publisher(IntersectionBSM, '/dsrcmsg', 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #Create DSRCMessage subscriber
        self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/dsrcmsg', self.MyIntersectionTraffic, 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.vehAtCurJunction = {} #Used to maintain a python dictionary of vehicles at the current intersection vehicles are added for current intersection using DSRCMessage subscriber
        
        #Create IntersectionBSM subscriber
        self.dsrcSubscriber = self.create_subscription(OneCIMTlsMsg, '/tls', self.TlsBasedTrajectoryPlanning, 2) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        
        #record my intersection traffic data
        self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority'])
        
        self.agentPath = 'SW0'
        self.vehicleID = 'SN1' #North-South or South-North Number: SN1, SN2, ... NS1, NS2, ... Could be plate Number
        self.arrivalTime = 0.0
        self.vehicleType = 1 # Based on vehicle type codes found at https://actar.org/pdf/ca_veh1.pdf
        self.point = Point()
        self.vehiclePriority = 0 #Thus, we specify here our priority standard: 0 mean no priority. Higher values impliy higher priority
        
        self.minGap = 0.7
        self.toFroStopLine = True #set to True when the vehicle is approaching stop line and at certain distance 
                                    #and false whent the vehicle has gone certain distance from the line
        self.atStopLine = False
        self.distFromStopLine = 2000.0 #set to a very large value
        self.MINSTOPLINEDIST = 5.0
        self.currStopLinePoint = None
        self.approachLeg = 'SW0'
        self.departureLeg = 'SW0'
        self.arrivedDestination = False
        self.checkNextIntersection = True
        self.obstacleInFront = False
        self.frontLidarScan = None
        
        #Record this vehicle's waiting times at intersections
        self.waitingTimeData = pd.DataFrame(data={}, columns=['approachLeg', 'waitTime']) 
        self.simStartTime = time.time() #record the time the simulation started
        self.simDuration = 900  #declaring how long (in clock seconds) a vehicle to run in this simulation
        self.timer = self.create_timer(1, self.StopRecordingWaitTime)
        self.waitTimeFileName = '/home/babangida/ros_ws/src/onecim/results/onecimsnagent.csv' #FISHybridCIMewagent  STLSCIMewagent

        self.poseX = 2000.0
        self.poseY = 2000.0 #These are set to incredibly large values deliberately to allow the vehicle move instead of thinking it has arrived at stop line
        
        self.northStartPoint = (41.2903, 3.88033)
        self.southStartPoint = (-16.9602, -2.39461)
        self.westStartPoint  = (8.57243, 27.9159)
        self.eastStartPoint  = (14.906, -27.0955)
        
        self.tlsProcessingTIme = pd.DataFrame(data={}, columns=['starttime', 'endtime']) 
		
    def ChoosePath(self):
        """
            This function uses a random number generator to determine randomly 
            which path to follow: left-turn, through, or right-turn at the 
            on the intersection of SN or NS path
        """
        pIdx = rnd.randint(0, 2)
        poseX, poseY, poseTheta = self.GetVehiclePose()
        path = '/home/babangida/ros_ws/src/onecim/paths/Processed/'
        chosenPath = None
        wpts = None
        nWpts = ['ne0wptsvelocityprofile', 'ns1wptsvelocityprofile', 'nw1wptsvelocityprofile'] #['NE0', 'NS1', 'NW1'] 
        sWpts = ['sw0wptsvelocityprofile', 'sn1wptsvelocityprofile', 'se1wptsvelocityprofile'] #['SW0', 'SN1', 'SE1']
        wWpts = ['wn0wptsvelocityprofile', 'we1wptsvelocityprofile', 'ws1wptsvelocityprofile'] #['WN0', 'WE1', 'WS1']
        eWpts = ['es0wptsvelocityprofile', 'ew1wptsvelocityprofile', 'en1wptsvelocityprofile'] #['ES0', 'EW1', 'EN1']
        
        nPaths = ['NE0', 'NS1', 'NW1'] 
        sPaths = ['SW0', 'SN1', 'SE1']
        wPaths = ['WN0', 'WE1', 'WS1']
        ePaths = ['ES0', 'EW1', 'EN1']
        #print('pIdx: ', pIdx)
        #The agent is at or going to South
        if self.agentPath[1] == 'S':
            chosenPath = sPaths[pIdx]
            wtps = sWpts[pIdx]
        
        #the agent is at or going to North
        elif self.agentPath[1] == 'N':
            chosenPath = nPaths[pIdx]
            wtps = nWpts[pIdx]
        
        #The agent is at or going to West
        elif self.agentPath[1] == 'W':
            chosenPath = wPaths[pIdx]
            wtps = wWpts[pIdx]
            
        #The agent is at or going to East
        elif self.agentPath[1] == 'E':
            chosenPath = ePaths[pIdx]
            wtps = eWpts[pIdx]
         
        #The approachLeg, departureLeg, and agentPath store the same velue but used at different locations
        #for different purposes.
        self.agentPath = chosenPath
        self.approachLeg = chosenPath
        self.departureLeg = chosenPath
        
        #instatiate pure pursuit algorithm with new set of waypoints.
        wptsPath = path + wtps + '.csv'
        self.purePursuit = PurePursuitPlanner(wptsPath, 'snpath', 'snpoint')
        self.currStopLinePoint = None
        
        
        
    def StopRecordingWaitTime(self):
        diff = time.time() - self.simStartTime 
        #print('Sim Duration:', diff)
        
        if diff >= self.simDuration: #
            path = self.waitingTimeData.to_csv("vehDelayTimeSn.csv") #write recorded waitTime to CSV file for analysis
            path = self.tlsProcessingTIme.to_csv('vehProcessingTime.csv')
			
            #print('Waiting Times file path: ',path)
            self.PublishDriveCommand()
            rclpy.shutdown()
            
    def RecordWaitingTime(self):
        """
            This function records the waiting time of this vehicle at each intersection.
        """
        waitTime = time.time() - self.arrivalTime 
        self.waitingTimeData.loc[len(self.waitingTimeData)] = {'approachLeg': self.approachLeg, 'waitTime': waitTime}
        
        
    def TlsBasedTrajectoryPlanning(self, tlsmsg):
        """
            Vehicle plans trajectory at the intersection based on traffic lights.
        """
        #print('receiving tls: ', tlsmsg.pathids, ' Dur: ', tlsmsg.duration)
        #print('Green Paths: ',tlsmsg.pathids)
        start = time.time()
        dur = time.time() - tlsmsg.starttime
        #print('distFromStopLine: ', self.distFromStopLine, ' Rem Duration: ', dur, ' Assigned Dur: ', tlsmsg.duration)
        if tlsmsg.starttime is not None and self.arrivalTime is not None:
            #When I received tls msg, I check the intersection keypoints for mine
            
            if self.currStopLinePoint is None:
                for point in tlsmsg.approachpoints:
                    if point.key == self.approachLeg:
                        #print('Key: ', point.key)
                        #print('x: ', point.x)
                        #print('y: ', point.y)
                        self.currStopLinePoint = (point.x, point.y)
                        #self.currStopLinePoint[1] = [point.y]
                        #print('point: ', self.currStopLinePoint)
                        #print('point x: ', self.currStopLinePoint[0])
                        #print('point y: ', self.currStopLinePoint[1])
                        break
                
           
            #print('distFromStopLine: ', self.distFromStopLine, ' Duration: ', dur , ' appLeg: ', self.approachLeg)
            if self.approachLeg not in tlsmsg.pathids : #Check to ensure the received tls message is for the vehicle path - vehicle path scheduled
                #check if this vehicle is at the stop line threshold
                
                #poseX, poseY, poseTheta =self.GetVehiclePose()
                #dist = self.CalculateDistance(poseX, poseY, self.currStopLinePoint[0], self.currStopLinePoint[1])
                
                
                
                #if abs(self.distFromStopLine) < 1.5 and dur < (tlsmsg.duration - 3):
                if ((self.distFromStopLine > 0 and self.distFromStopLine < 1.5)):
                        print('SN Agent @ stop line: distFromStopLine=', self.distFromStopLine, ' duration: ', dur)
                        self.speed = 0.
                        #self.PublishDriveCommand()
                        #rclpy.shutdown()
                
            else:
                #Delay starting to move for 2s
                if dur <= 2 and self.speed == 0.0:
                    #print('Delay moving for 2s, now is: ', dur)
                    self.speed = 0.
                    
                else:
                    #print('Start moving now',)
                    #self.speed = 1.0
                    self.speed = self.IntersectionAwareTrajPlanning()
          
        #print('Speed: ', self.speed)
        end = time.time()
        self.tlsProcessingTIme.loc[len(self.tlsProcessingTIme)] = {'starttime': start, 
                                                        'endtime': end 
                                                    } 
     
    def GetConcurrentFlows(self, appLeg, departLeg):
        """
            This function gets the flows that can utilize the intersection without high risk of collision(s)
        
        
        if appLeg == 'NS' or appLeg == 'SN':
            scheFlows = ['SN','NS']
        if appLeg == 'WE' or appLeg == 'EW':
            scheFlows = ['EW','WE']
        """   
        appLegs = None
        scheFlows = None 
        #print('Approach Leg: ',appLeg)
        if appLeg in ['NE0','SW0']: #movement 1 and 5
            scheFlows = ['NE0','SW0']
            
        elif appLeg in ['WN0','ES0']: #movement 3 and 7
            scheFlows = ['WN0','ES0']
            
        elif appLeg in ['NS1', 'NW1', 'SN1', 'SE1']: #movement 2, 6, or their right-turn
            scheFlows = ['NS1', 'NW1', 'SN1', 'SE1']
            
        elif appLeg in ['WE1', 'WS1', 'EW1', 'EN1']: #movement 4 and 4 or thei right-turn
            scheFlows = ['WE1', 'WS1', 'EW1', 'EN1']
        
        #self.tlsPaths = scheFlows
        #print('scheFlows: ', scheFlows)
        return scheFlows
        
                    
    def IntersectionAwareTrajPlanning(self):
        """
            This function analyzes the traffic composition at the vehicles current intersection and decide the 
            appropriate speed for navigating the intersection.
        """
        speed = 0.0
        if len(self.trafficData) > 0: #There are vehicles at the this vehicle's current intersection
            speed = self.recmdedSpeed
            #Get vehicles on the same lane as this vehicle
            tmpTfData = self.trafficData[(self.trafficData['approachleg'] == self.approachLeg)]
            #print(self.trafficData)
            if len(tmpTfData) > 0: #There are vehicles on the same lane
                
                #Analyze distance between this vehicle and the one before it
                for idx, row in tmpTfData.iterrows():
                    if row['distfromstopline'] < self.distFromStopLine: #meaning there is a vehicle before this vehicle at the intersection
                        
                        #Calculate distance to the vehicle
                        poseX, poseY, poseTheta = self.GetVehiclePose()
                        dist = self.CalculateDistance(row['point'][0], row['point'][1], poseX, poseY ) #self.currStopLinePoint[0], self.currStopLinePoint[1]
                        
                        if dist <= self.minGap:
                            #speed = 0.0 #Commented because of simulation vehicles
                            print("A Virtual Vehicle in front, I will passing over it...")
                        #else:
                        #    speed = self.recmdedSpeed
                                
                        
           
           
            #Check current intersection for opposing/conflicting vehicles 
            flows = self.GetConcurrentFlows(self.approachLeg, self.approachLeg)
            tmpTfData = []
            if len(flows) == 2:
                tmpTfData = self.trafficData[(self.trafficData['approachleg'] != flows[0]) & (self.trafficData['approachleg'] != flows[1])]
            elif len(flows) == 4:
                tmpTfData = self.trafficData[
                                            (self.trafficData['approachleg'] != flows[0]) &
                                            (self.trafficData['approachleg'] != flows[1]) &
                                            (self.trafficData['approachleg'] != flows[2]) &
                                            (self.trafficData['approachleg'] != flows[3])
                                        ]

            if len(tmpTfData) > 0 : #Meaning there are vehicles on the other approach(es)
                
                #Analyze distFromStopLine to see if any of those is in the intersection
                for idx, row in tmpTfData.iterrows():
                    if row['distfromstopline'] < 0 and row['distfromstopline'] > -(self.MINSTOPLINEDIST * 0.65): #meaning there is a vehicle in the intersection
                        p = row['point']
                        d = self.CalculateDistance(self.currStopLinePoint[0],self.currStopLinePoint[1], p[0], p[1])
                        if d <= 2 and self.distFromStopLine > 0:
                            print(self.distFromStopLine)
                            speed = 0.2
                        else:
                            speed = 1.0
                    #else:
                    #    speed = self.recmdedSpeed
                            
        else: #There are no vehicles at the vehicle's current intersection
            speed = 1.0
        
        #print('IntersectionAwareTrajPlanning speed: ', speed)
        return speed 

 
    def InsertNewRecord(self, msg):
        """
            Insert new traffic data of a given vehicle
        """
        self.trafficData.loc[len(self.trafficData)] = {'vehicleid': msg.vehicleid, 
                                                        'junctionid': msg.junctionid, 
                                                        'approachleg': msg.approachleg, 
                                                        'departleg': msg.departleg,
                                                        'vehicletype': msg.vehicletype, 
                                                        'distfromstopline':msg.distfromstopline, 
                                                        'point':tuple(msg.point), 
                                                        'arrivaltime': msg.arrivaltime, 
                                                        'speed': msg.speed, 
                                                        'priority': msg.priority
                                                    }
                                                    
    def MyIntersectionTraffic(self, msg): 
        """
            This function receives a DSRC Message from vehicle(s), checks if the vehicle already exist in trafficData for the present intersection
            If the vehicle has already been added, it updates location/point, speed, distancetostopline
        """
        #print('VehicleID: ', msg.vehicleid)
        idx = None 
        
        #ensure the current msg is not from this (the vehicle) but from other vehicles and that the messaging vehicle has the same approach leg as this veicle
        if msg.vehicleid != self.vehicleID and msg.approachleg == self.approachLeg:
            #check if self.trafficData is not empty
            if len(self.trafficData) > 0: #There is a record in it
                try:
                    #try to retrieve the vehicle record nat the current intersection
                    idx = self.trafficData[((self.trafficData['vehicleid'] == msg.vehicleid) & (self.trafficData['approachleg'] == msg.approachleg))].index[0]
                    
                    if msg.distfromstopline > -self.MINSTOPLINEDIST/2.5 : #vehicle is yet past the intersection, thus, we update its data
                        #update disttostoline, point, and speed
                        pointTuple = tuple(msg.point)
                        #print('Tuple Value: ', pointTuple)

                        # Assign values to 'point' and 'speed' columns separately
                        self.trafficData.at[idx, 'point'] = pointTuple
                        self.trafficData.at[idx, 'speed'] = msg.speed
                        self.trafficData.at[idx, 'distfromstopline'] = msg.distfromstopline
                    else: #Vehicle has gone past the intersection, thus we remove it from the record
                        #delete vehicle record from dataframe
                        self.trafficData = self.trafficData[~((self.trafficData['vehicleid'] == msg.vehicleid) & (self.trafficData['approachleg'] == msg.approachleg))]
                
                except IndexError as e:
                    if idx is None: #Just to confirm that generated the error that hindered updates, which means vehicle is not in the dataframe
                        #When it fails to retrieve idx, it means record for the vehicle at the current intersection does not exist.
                        #We add it as a new record
                        self.InsertNewRecord(msg)
                    
            else: #this is the first record to be inserted                                            
                self.InsertNewRecord(msg)
            
                
    def PublishDSRCMsg(self, appLeg, deptLeg, speed):
       # print('arrivalTime: ',self.arrivalTime)
        
        dsrcmsg = IntersectionBSM()
        dsrcmsg.vehicleid = self.vehicleID
        dsrcmsg.junctionid = appLeg
        dsrcmsg.approachleg = appLeg
        dsrcmsg.departleg = deptLeg
        dsrcmsg.vehicletype = self.vehicleType
        dsrcmsg.distfromstopline = self.distFromStopLine 
        dsrcmsg.point = self.point
        dsrcmsg.arrivaltime = self.arrivalTime
        dsrcmsg.speed = speed
        dsrcmsg.priority = self.vehiclePriority
        self.dsrcPublisher.publish(dsrcmsg)
        
    def CalculateDistance(self, x1, y1, x2, y2):
        """
            (x1, y1) is the vehicle point
            (x2, y2) is the stop line (critical point)
        """
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)  
        
    
    
    def StartStopDSRCMsgs(self, poseX, poseY, appLeg, deptLeg):
        dist = self.MINSTOPLINEDIST * 1.4
        if self.currStopLinePoint is not None:
            dist = self.CalculateDistance(poseX, poseY, self.currStopLinePoint[0], self.currStopLinePoint[1])
            distFro = 1000 #initialized to an unreasonable large number so that if distFro < -self.MINSTOPLINEDIST: is only satisfied when it needs to
            
        #print('status of toFroStopLine: ', self.toFroStopLine)
        if dist <= self.MINSTOPLINEDIST: #vehicle should be publishing DSRC Messages
            #print('Publishing DSRC Msg')
            
            if self.toFroStopLine: #If it true, vehicle is yet at the intersection or gone past intersection 
                self.toFroStopLine = False
                self.arrivalTime = time.time()
                #print('Recorded Start Time on: ',self.approachLeg)
                
            #if vehicle is at the point or within a threshold distance that is approximated to the stop line point, assume it has gone past the point
            if dist <= 1:
                self.atStopLine = True
                #print('Arrived Stop Line on: ',self.approachLeg)
                
                #print('Vehicle arrived at stop line')
                #self.speed = 0. #stop vehicle at the stop line
                
            else:
                
                distTo = dist 
                distFro = 1000. #or math.inf
                self.distFromStopLine = dist
            
            if self.atStopLine:
                distTo = 1000. #or math.inf
                distFro = -dist
                self.distFromStopLine = distFro
                #print('Distance to stop line: ', self.distFromStopLine)
           
        if self.distFromStopLine <= (self.MINSTOPLINEDIST * 2) and self.distFromStopLine > -self.MINSTOPLINEDIST/2:
            self.PublishDSRCMsg(appLeg, deptLeg, self.speed)
        #    print('Publishing DSRC Msg at: ', self.distFromStopLine)
        #else:
        #    print('No longer publishing DSRC Msg at: ', self.distFromStopLine)
            
        #if negative distance is less than the negative self.MINSTOPLINEDIST meaning vehicle has gone beyond the 
        #intersection and should stop publishing DSRC message or check the next intersection on the way.
        #print('Dist From Line: ', distFro)
        if self.atStopLine and -dist <= -self.MINSTOPLINEDIST:
            #Record vehicle waiting time at intersection 
            self.RecordWaitingTime()
            #print('Recorded waitingTime on: ',self.approachLeg)
            #self.checkNextIntersection = True
            self.toFroStopLine = True
            self.atStopLine = False
            #self.distFromStopLine = 0.
            #print('Distance from stop line: ', distFro)
        #else:
            #self.checkNextIntersection = False
        #Compute distance to end of path.
        #dist = self.CalculateDistance(poseX, poseY, 27.6704, -0.827079)
        
    def PublishDriveCommand(self, steerAngle=0.0, speed=0.0):
        #print('Speed: ', speed)
        if abs(steerAngle) > self.disparityExtender.GetStraightSteeringAngle() and speed > 1.0:
            speed = 1.0
        if speed > 2:
            speed = 2.0
           
        if self.frontLidarScan is not None:
            gap = 1.5
            obsAt = 2.0
            for gap in [1.5, 1.0]:
                #If more than 50% are less than gap distance away, we should take note
                if (np.sum(self.frontLidarScan < gap)/(len(self.frontLidarScan))) > 0.6 and speed >= 1.0:
                    obsAt = gap
            if obsAt == 1.0:
                speed = 0.0
                print('There is obstacle ahead')
            elif obsAt == 1.5:
                speed = 0.5
                
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
        #print('gap: ', gap, ' dataType: ', type(gap))
        obsScan = np.where(scan < gap, True, False)
        #print(obsSubScan)
        if np.any(obsScan): #if there is any lidar ray that is less than or equal to 1, it implies an obstancle, thus we break 
            return True
        return False
        
    def ProcessLidar(self, data):
        #Get Vehicle Pose details
        poseX, poseY, poseTheta = self.GetVehiclePose()
        if poseX is not None:
            self.point = [poseX, poseY] #np.array((poseX, poseY))
            startPoint = None
            #The agent is at or going to South
            if self.agentPath[1] == 'S':
                startPoint = self.southStartPoint
                
            #the agent is at or going to North
            elif self.agentPath[1] == 'N':
                startPoint = self.northStartPoint
            
             #The agent is at or going to West
            elif self.agentPath[1] == 'W':
                startPoint = self.westStartPoint
                
            #The agent is at or going to East
            elif self.agentPath[1] == 'E':
                startPoint = self.eastStartPoint
            
            #Compute distance to start of new path.
            dist = self.CalculateDistance(poseX, poseY, startPoint[0], startPoint[1])
            #print(self.agentPath, ' Dist to new path', dist, '', startPoint)
            if dist <= 1:
                #self.arrivedDestination = True  
                #self.PublishDriveCommand()
                #rclpy.shutdown()
                print('Completed ',self.approachLeg, ' Choose a new path')
                self.ChoosePath()
                print('New Path: ', self.approachLeg)
                
            self.StartStopDSRCMsgs(poseX, poseY, self.approachLeg, self.departureLeg)
            
        #Determine if there are obstacles in front
        radPerPoint = (2*np.pi)/len(data.ranges)
        fovScan = self.GetFieldOfView(data.ranges)
        adjSpeed = self.speed
        steerAngle = 0.0
        self.frontLidarScan = np.array(self.GetFrontLidarScan(data.ranges,radPerPoint))
        if self.CheckObstacle(fovScan, 0.7):
            #print("snagent::Disparity Extender Executing")
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
            if poseX is not None:
                #print("Pure Pursuit Executing: x: ", poseX, ', y: ', poseY, ', theta', poseTheta )
                spd, steerAngle = self.purePursuit.plan(pose_x=poseX, pose_y=poseY, pose_theta=poseTheta)
                adjSpeed = self.speed * 2.7
            else:
                adjSpeed = 0.5
        #print(adjSpeed)    
        self.PublishDriveCommand(steerAngle, adjSpeed)
        #self.PublishDriveCommand(self.disparityExtender.GetStraightSteeringAngle(), self.speed)


def main(args=None):
    rclpy.init(args=args)
    print("Hybrid Cooperative Intersection Management Aware South-North Controller Node")
    cimController = CIMAutonomousVehicle()
    rclpy.spin(cimController)
    
    cimController.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

