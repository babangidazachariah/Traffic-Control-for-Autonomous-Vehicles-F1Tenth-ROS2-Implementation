"""
    In order to better simulate vehicular arrival, have a parameter that specifies 
    number of vehicles per hour - hourlyflowrate 
    Given hourly flow rate, determine second by second flow rate:
        secondflowrate = hourlyflowrate / 3600
    For every second, compute a probability (random number) representing arrival probability.
    Every second, based on probability, add a vehicle to the road segment or network
    
    
    https://www.dbpia.co.kr/Journal/articleDetail?nodeId=NODE11100950 Fuzzy Logic intersection for autonomous vehicles
    
"""
import time
import threading as td
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
from onecim.FISBasedDecentralizedCIM import FISBasedDecentralizedCIM


class TimedVehicleGeneration(Node):
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
        
        self.speed = 1.0
        self.recmdedSpeed = 1.0
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        
        #Create IntersectionBSM publisher
        self.dsrcPublisher = self.create_publisher(IntersectionBSM, '/dsrcmsg', 100) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.northPublisher = self.create_publisher(IntersectionBSM, '/northpath', 100) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.southPublisher = self.create_publisher(IntersectionBSM, '/southpath', 100) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.eastPublisher = self.create_publisher(IntersectionBSM, '/eastpath', 100) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.westPublisher = self.create_publisher(IntersectionBSM, '/westpath', 100) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #Create DSRCMessage subscriber
        #self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/dsrcmsg', self.RecordTrafficData, 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.vehAtCurJunction = {} #Used to maintain a python dictionary of vehicles at the current intersection vehicles are added for current intersection using DSRCMessage subscriber
        
        #Create OneCIMTlsMsg subscriber
        self.dsrcSubscriber = self.create_subscription(OneCIMTlsMsg, '/tls', self.TlsBasedTrajectoryPlanning, 2) # qos_profile=rclpy.qos.qos_profile_system_default)
        #Create Acknoledgement subscriber
        self.dsrcAcknowledgement = self.create_subscription(String[], '/ack', self.Acknowledgement, 20) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #Create OneCIMTlsMsg Publisher
        self.tlsPub = self.create_publisher(OneCIMTlsMsg, '/tls', 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        
        #record my intersection traffic data
        #self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime'])
        self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp'])
        
        self.agentPath = 'SW0'
        self.vehicleID = 'SN1' #North-South or South-North Number: SN1, SN2, ... NS1, NS2, ... Could be plate Number
        self.arrivalTime = 0.0
        self.stoppedTime = 0.0
        self.vehicleType = 1 # Based on vehicle type codes found at https://actar.org/pdf/ca_veh1.pdf
        self.point = Point()
        self.vehiclePriority = 0 #Thus, we specify here our priority standard: 0 mean no priority. Higher values impliy higher priority
        
        self.minGap = 2.0
        self.toFroStopLine = True #set to True when the vehicle is approaching stop line and at certain distance 
                                    #and false whent the vehicle has gone certain distance from the line
        self.atStopLine = False
        self.distFromStopLine = 2000.0 #set to a very large value
        self.MINSTOPLINEDIST = 10.0
        
        self.approachLeg = 'SW0'
        self.departureLeg = 'SW0'
        self.arrivedDestination = False
        self.checkNextIntersection = True
        self.obstacleInFront = False
        self.frontLidarScan = None
        
        #Record this vehicle's waiting times at intersections
        
        self.simStartTime = time.time() #record the time the simulation started
        self.simDuration = 900  #declaring how long (in clock seconds) a vehicle to run in this simulation
        #self.timer = self.create_timer(1, self.StopRecordingWaitTime)
        self.waitTimeFileName = 'src/onecim/results/onecimsnagent.csv' #FISHybridCIMewagent  STLSCIMewagent

        self.poseX = 2000.0
        self.poseY = 2000.0 #These are set to incredibly large values deliberately to allow the vehicle move instead of thinking it has arrived at stop line
        
        self.northStartPoint = (41.2903, 3.88033)
        self.southStartPoint = (-16.9602, -2.39461)
        self.westStartPoint  = (8.57243, 27.9159)
        self.eastStartPoint  = (14.906, -27.0955)
        
        #OneCIM notable points
        self.intersectionApproachLegs = self.CreateApproachKeyPoints() #{'EW': (5.67632, -4.22149), 'SN': (1.01726, -0.787557), 'WE': (4.04208, 3.99244), 'NS':(9.7611, 0.740437) }
        self.intersectionDepartLegs = self.CreateDepartKeyPoints() #{'EW':(6.11296, 3.86962), 'SN': (9.48962, -0.8483), 'WE': (4.03338, -4.06445), 'NS': (1.03482, 1.0365)}
        self.tlsPaths = ['SW0','NE0']
        self.startTime = None #TLS phase duration start time
        self.tlsMSG = None #Stores a received tlsmsg, so that this vehicle may publish the same when the publi
        
        self.fisbasedcontroller = FISBasedDecentralizedCIM()
        self.publishTls = False
        
        self.currStopLinePoint = self.GetStopLine('SW0')
        self.vehPub = self.create_publisher(MarkerArray, '/vehicles', 100)
        self.vehicles = []
        self.drawnVehicles = MarkerArray()
        #self.CreateVehicles()
        self.transTime = pd.DataFrame(data={}, columns=['vehicleid', 'transtime']) 
        self.delayTime = pd.DataFrame(data={}, columns=['vehicleid', 'delaytime']) 
        self.timer = self.create_timer(1, self.StopRecordingTransTime)
        
        self.eastSouth = []
        self.eastNorth = []
        self.eastWest = []
        
        self.southWest = []
        self.southNorth = []
        self.southEast = []
        
        self.northSouth = []
        self.northEast = []
        self.northWest = []
        
        self.westEast = []
        self.westSouth = []
        self.westNorth = []
        
        self.hourlyFlowRate = 200 #vehicles per hour to used in determining if a vehicle shoul be added to a flow or not every second
        self.crtVeh = self.create_timer(9, self.CreateVehicles)
        self.rdrwVeh = self.create_timer(0.3, self.ReDrawVehicles)
        self.rdrwVeh = self.create_timer(0.2, self.PublishVehicles)
        self.idx = 0
        self.vehID = -1
        self.createdCount = 0
        self.removedCount = 0
        self.vehPubIndex = 0
        self.totalVehPub = 0
        
        self.lock = td.Lock()
        """
        cd ros_ws
        . /opt/ros/foxy/setup.bash
        . install/setup.bash
        ros2 launch f1tenth_gym_ros gym_bridge_launch.py
        """
    def StopRecordingTransTime(self):
        diff = time.time() - self.simStartTime 
        #print('Sim Duration:', diff)
        
        if diff >= self.simDuration: #
            path = self.transTime.to_csv('vehTransTime.csv') #write recorded waitTime to CSV file for analysis
            path = self.delayTime.to_csv('delayTime.csv')
            with open('output.txt', 'w') as f:
                # Write some text to the file
                f.write("Created: {}\n".format( self.createdCount))
                f.write("Removed: {}\n".format(self.removedCount))
                f.write("Throughput Performance: {}\n".format(((self.removedCount/self.createdCount) * 100)))
            #self.PublishDriveCommand()
            rclpy.shutdown()
    
    def Acknowledgement(self, ack):
        """"
            This function receives handshake acknwledgement sent by central controller and updates the vehicle's
            acknowledgement status to 2
        """"
        if ack[0] == 'ES': #road ID
            idx = None 
            for index, vehicle in enumerate(self.eastSouth):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.eastSouth[idx][11] = int(ack[2])
            self.eastSouth[idx][12] = None
            
        elif ack[0] == 'EN': #road ID
            idx = None 
            for index, vehicle in enumerate(self.eastNorth):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.eastNorth[idx][11] = int(ack[2]) 
            self.eastNorth[idx][12] = None
            
        elif ack[0] == 'EW': #road ID
            idx = None 
            for index, vehicle in enumerate(self.eastWest):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.eastWest[idx][11] = int(ack[2]) 
            self.eastWest[idx][12] = None
            
        elif ack[0] == 'SW': #road ID
            idx = None 
            for index, vehicle in enumerate(self.southWest):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.southWest[idx][11] = int(ack[2]) 
            self.southWest[idx][12] = None
            
        elif ack[0] == 'SN': #road ID
            idx = None 
            for index, vehicle in enumerate(self.southNorth):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.southNorth[idx][11] = int(ack[2]) 
            self.southNorth[idx][12] = None
            
        elif ack[0] == 'SE': #road ID
            idx = None 
            for index, vehicle in enumerate(self.southEast):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.southEast[idx][11] = int(ack[2]) 
            self.southEast[idx][12] = None
        
         elif ack[0] == 'NS': #road ID
            idx = None 
            for index, vehicle in enumerate(self.northSouth):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.northSouth[idx][11] = int(ack[2]) 
            self.northSouth[idx][12] = None
            
        elif ack[0] == 'NE': #road ID
            idx = None 
            for index, vehicle in enumerate(self.northEast):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.northEast[idx][11] = int(ack[2]) 
            self.northEast[idx][12] = None
            
             
        elif ack[0] == 'NW': #road ID
            idx = None 
            for index, vehicle in enumerate(self.northWest):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.northWest[idx][11] = int(ack[2]) 
            self.northWest[idx][12] = None
            
        
        elif ack[0] == 'WE': #road ID
            idx = None 
            for index, vehicle in enumerate(self.westEast):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.westEast[idx][11] = int(ack[2]) 
            self.westEast[idx][12] = None
            
        elif ack[0] == 'WS': #road ID
            idx = None 
            for index, vehicle in enumerate(self.westSouth):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.westSouth[idx][11] = int(ack[2]) 
            self.westSouth[idx][12] = None
            
        elif ack[0] == 'WN': #road ID
            idx = None 
            for index, vehicle in enumerate(self.westNorth):
                if vehicle[0] == ack[1]: #vehicle ID
                    idx = index
                    break
            self.westNorth[idx][11] = int(ack[2]) 
            self.westNorth[idx][12] = None
       
        
    def CreateVehicles(self):
        """
            This function is called every second
            This function create simulated virtual vehicles used to test the response time of controllers
            
        """
        
        secondsFlowRate = self.hourlyFlowRate / 3600
        #L = [0, 1]
        nPaths = ['NE0', 'NS1', 'NW1'] 
        sPaths = ['SW0', 'SN1', 'SE1']
        wPaths = ['WN0', 'WE1', 'WS1']
        ePaths = ['ES0', 'EW1', 'EN1']
        
        allPaths = [nPaths, sPaths, wPaths, ePaths] # [sPaths, ePaths] #   [sPaths, nPaths]# [sPaths, ePaths] #
        
        #Limit the number of vehicles in the network to 100 at most
        if (self.createdCount - self.removedCount) < 100:
            # Loop through each list and access each element
            for directionPaths in allPaths:
                #print(f"Paths for direction: {directionPaths}")
                for path in directionPaths:
                
                    #prob = rnd.random()
                    #print(prob, ' ', secondsFlowRate)
                    #if prob <= secondsFlowRate:
                    #print('Creating a Vehicle on ', path)
                    #add vehicle to flow
                    veh = self.AddVehicle(path)
                    self.createdCount += 1
                    print('Total Vehicles in Simulation: ', self.createdCount - self.removedCount)
                    if path == 'NE0':
                        self.northEast.append(veh)
                    elif path == 'NS1':
                        self.northSouth.append(veh)
                    elif path == 'NW1':
                        self.northWest.append(veh)
                        
                    elif path == 'SW0':
                        self.southWest.append(veh)
                    elif path == 'SN1':
                        self.southNorth.append(veh)
                    elif path == 'SE1':
                        self.southEast.append(veh)
                        
                    elif path == 'WN0':
                        self.westNorth.append(veh)
                    elif path == 'WE1':
                        self.westEast.append(veh)
                    elif path == 'WS1':
                        self.westSouth.append(veh)
                
                    elif path == 'ES0':
                        self.eastSouth.append(veh)
                    elif path == 'EW1':
                        self.eastWest.append(veh)
                    elif path == 'EN1':
                        self.eastNorth.append(veh)
                
                   
                   
        #self.vehicles = self.northEast + self.northSouth + self.northWest + self.southWest + self.southNorth + self.southEast + self.westNorth + self.westEast + self.westSouth + self.eastSouth + self.eastWest + self.eastNorth
                        
        #print(self.vehicles)
        #print('Len: ', len(self.vehicles))
        #self.DrawVehicles()
        #self.vehPub.publish(self.drawnVehicles)
        
        
    def TlsBasedTrajectoryPlanning(self, tlsmsg):
        """
            This function sets the traffic light message as received from the controller.
            self.tlsMSG = tlsmsg  is used in self.MoveVehicles()
        """
        
        self.tlsMSG = tlsmsg
        
        #Write trafficData to csv file when phase duration remains 2s so that it is available to controller
        dur = time.time() - tlsmsg.starttime
        if (((tlsmsg.duration - dur) > 2) and ((tlsmsg.duration - dur) <= 3)):
            #Write the traffic data to file just before the controller accesses it
            rdy = False
            #while not rdy: #Comment if not sure that traffic data will be available and uncomment if sure
            try:
                self.trafficData.to_csv('src/onecim/trafficData/trafficData.csv')
                #print(len(self.trafficData), ' written from ', self.totalVehPub, ' published vehs of ', self.createdCount, ' created Vehs')
                rdy = True
            except Exception as e:
                print("Traffic Data Read Error")
        
        
    def DrawVehicle(self, point, leg, color):
        marker = Marker()
        marker.header.frame_id = 'map'
        
        marker.scale.z = 0.2
        marker.pose.position.z = 0.0
        marker.color.a = 1.0
        marker.color.r = color[0] 
        marker.color.g = color[1] 
        marker.color.b = color[2]
        marker.type = Marker.CUBE
        marker.action = Marker.ADD
        marker.id = self.idx
        self.idx += 1
        marker.pose.position.x = float(point[0])
        marker.pose.position.y = float(point[1])
        
        if leg[0] == 'W' or leg[0] =='E':
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 1.0
            marker.scale.x = 0.5
            marker.scale.y = 0.5 #1.0
        elif  leg[0] == 'N' or leg[0] == 'S':
            marker.scale.x = 0.5 #1.0
            marker.scale.y = 0.5
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 0.707
            
        
        return marker
        
    def DrawVehicles(self, vehicles):
        markerArray = MarkerArray()
        colorCode = None
        redColorCode = (1.0, 0.0, 0.0)
        #self.idx = 0
        
        
        
        #print('appLegs: ', appLegs) 
      #['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', handshakeStatus]  
        color = ()
        for vehicle in vehicles:
            if vehicle[11] == 0: #Vehicle is yet to initiate a handshake ==>  Black
                color = (0.0, 0.0, 0.0)
            elif vehicle[11] == 1: #Vehicle is approaching intersection has initiated welcome handshake but yet to received acknoledgement ===>Blue
                color = (0.0, 0.0, 1.0)
            elif vehicle[11] == 2: #Vehicle is approaching intersection has initiated welcome handshake and received acknoledgement ===> Yellow
                color = (1.0, 1.0, 0.0)
            elif vehicle[11] == 3: #Vehicle crossed intersection has initiated good bye handshake but yet to received acknoledgement ===> Cyan (Bright Green)
                color = (0.0, 1.0, 1.0)
            elif vehicle[11] == 4: #Vehicle crossed intersection has initiated good bye handshake and received acknoledgement ===> dark, bluish-green 
                color = (0.0, 0.5, 0.5)
                
            self.drawnVehicles.markers.append(self.DrawVehicle(vehicle[5], vehicle[2], color))
            
        return markerArray
    
    def ReDrawVehicles(self):
        """
            This function redraws vehicles to depict movement
        """
        self.idx = 0
        self.drawnVehicles = []
        self.drawnVehicles = MarkerArray()
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.eastSouth, 'ES0')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles = veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.eastNorth, 'EN1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.eastWest, 'EW1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.southWest, 'SW0')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.southNorth, 'SN1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.southEast, 'SE1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.northSouth, 'NS1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.northEast, 'NE0')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.northWest, 'NW1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.westEast, 'WE1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles += veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.westSouth, 'WS1')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        #veh = 
        self.DrawVehicles(self.MoveVehicles(self.westNorth, 'WN0')).markers
        #if len(veh) > 0:
        #    self.drawnVehicles +=  veh 
        
        #print(type(self.drawnVehicles))
        #if len(self.drawnVehicles) > 0:
        
        self.vehPub.publish(self.drawnVehicles)
        
    def PublishVehicles(self):
        """
            This function publishes vehicular IntersectionBSM message every second.
        """
        veh = 0
        self.vehPubIndex += 1
        #if self.vehPubIndex == 1:
        for vehicle in self.eastSouth:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'eastpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
        #elif self.vehPubIndex == 2:        
        for vehicle in self.eastNorth:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'eastpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
                
        #elif self.vehPubIndex == 3:
        for vehicle in self.eastWest:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'eastpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
                
        #elif self.vehPubIndex == 4:
        for vehicle in self.southWest:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'southpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
                
        #elif self.vehPubIndex == 5:
        for vehicle in self.southNorth:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'southpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
                
        #elif self.vehPubIndex == 6:
        for vehicle in self.southEast:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'southpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
        
        #elif self.vehPubIndex == 7:
        northCount = 0
        for vehicle in self.northSouth:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'northpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
                northCount += 1
                
        #elif self.vehPubIndex == 8:
        for vehicle in self.northEast:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'northpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                
                veh += 1
                northCount += 1
                
        #elif self.vehPubIndex == 9:
        for vehicle in self.northWest:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'northpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
                northCount += 1
        
        #elif self.vehPubIndex == 10:
        for vehicle in self.westEast:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'westpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                
                veh += 1
                
        #elif self.vehPubIndex == 11:
        for vehicle in self.westSouth:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'westpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                veh += 1
                
        #elif self.vehPubIndex == 12:
        for vehicle in self.westNorth:
            if vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.19):
                vehicle[12] = self.PublishDSRCMsg(vehicle, 'westpath') #vehicle and corresponding topic
                if vehicle[12] is not None:
                    vehicle[11] = 1 #Vehicle has initiated approach handshake
                eh += 1
        #print(veh, ' Vehs published data from the ', (self.createdCount - self.removedCount), '  Vehs in the network.')
        """
        else:
            print(self.totalVehPub, ' in Publishing phase from the ', self.createdCount, ' created Vehs')
            self.vehPubIndex = 0
            self.totalVehPub = 0
        self.totalVehPub += veh
        """    
        
        
        
                
    def MoveVehicles(self, vehicles, path):
        """
            This function moves vehicles along their path in the network
           #['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 
           'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp']
        """
        stopVehs = False
        x0 = 0
        y0 = 0
        #Get vehicles waypoints
        wpts = pd.read_csv('src/onecim/paths/' + self.ChoosePath(path, path[2]))
        nextIdx = 10
        wptsLength = len(wpts)
            
        for vehicle in vehicles:
            
            point = vehicle[5]
            #print('Point: ', point)
            dist = self.DistanceFromStopLine(path, point)
            if dist <= 1.0:
                vehicle[4] = -dist
            #Set the distfromstopline field
            if vehicle[4] <= 0: #If it has been previously set to negative value
                vehicle[4] = -dist
            else:
                vehicle[4] = dist
                
            #update arrival time
            if vehicle[6] is None and vehicle[4] > 0 and dist <= self.MINSTOPLINEDIST:
                vehicle[6] = time.time()
            
            
            #Record stoppedtime
            if vehicle[7] == 0 and vehicle[4] <= self.MINSTOPLINEDIST and vehicle[4] >= -(self.MINSTOPLINEDIST * 0.2):
                vehicle[9] = time.time() 
            
                
            #record delay time
            if  vehicle[6] is not None and vehicle[4] <= -(self.MINSTOPLINEDIST * 0.45):
                delay = time.time() - vehicle[6]
                vehicle[6] = None
                vehicle[9] = None
                self.delayTime.loc[len(self.delayTime)] = {'vehicleid': vehicle[0],
                                                            'delaytime': delay
                                                           }
                
            if not self.tlsMSG is None:
                
                if path not in self.tlsMSG.pathids:
                    if not stopVehs:
                        #print(vehicle[0], " has no right of way @ ", vehicle[4])
                        #print(vehicle[0],' on ', vehicle[2], ' @Dist: ', vehicle[4], ' tlsMSG: ', self.tlsMSG.pathids)
                        if (vehicle[4] >= 0 and vehicle[4] <= 1.0) or (vehicle[4] < 0 and vehicle[4] >= -0.2):   
                            #This vehicle and every other 
                            #print('Stopped Vehicle: ', vehicle[0])
                            stopVehs = True
                            x0 = point[0]
                            y0 = point[1]
                            #Update speed field
                            vehicle[7] = 0
                            #Change the distfromstopline field to negative
                            vehicle[4] = -dist #Set such as though it has just gone past the stop line
                        #elif vehicle[4] < 0 and vehicle[4] >= 1.0:
                            
                        else:
                            #Retrieve current locatio/point
                            idx = wpts[((wpts['x'] == point[0]) & (wpts['y'] == point[1]))].index[0]
                            if (idx + nextIdx + 1) < wptsLength:
                                #set the next location/point
                                x = wpts.at[(idx + nextIdx), 'x']
                                y = wpts.at[(idx + nextIdx), 'y']
                                vehicle[5] = (x,y)
                                vehicle[7] = 3
                            else:
                                vehicles.remove(vehicle)
                                self.removedCount += 1
                    else:
                        #Stop subsequent vehicles that are 1.0m apart
                        dist = self.CalculateDistance(point[0], point[1], x0, y0)
                        if dist >= 1.5:
                            #It means vehicle can move further
                            #Retrieve current locatio/point
                            idx = wpts[((wpts['x'] == point[0]) & (wpts['y'] == point[1]))].index[0]
                            #set the next location/point
                            if (idx + nextIdx + 1) < wptsLength:
                                x = wpts.at[(idx + nextIdx), 'x']
                                y = wpts.at[(idx + nextIdx), 'y']
                                vehicle[5] = (x,y)
                                vehicle[7] = 3
                            else:
                                vehicles.remove(vehicle)
                                self.removedCount += 1
                        else:
                            #vehicle need to stop
                            x0 = point[0]
                            y0 = point[1]
                            vehicle[7] = 0
                    
                else:
                    
                    #Move vehicle
                    #print(vehicle[0], " has right of way")
                    #Retrieve current locatio/point
                    idx = wpts[((wpts['x'] == point[0]) & (wpts['y'] == point[1]))].index[0]
                    if (idx + nextIdx + 1) < wptsLength:
                        #set the next location/point
                        x = wpts.at[(idx + nextIdx), 'x']
                        y = wpts.at[(idx + nextIdx), 'y']
                        vehicle[5] = (x,y)
                        vehicle[7] = 3
                    else:
                        vehicles.remove(vehicle)
                        self.removedCount += 1
            
            #print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
        return vehicles
        
       
    def AddVehicle(self, path):
        """
            This function adds a vehicle to the simulation on a given path
        """
        wpts = pd.read_csv('src/onecim/paths/' + self.ChoosePath(path, path[2]))
        dist = 0
        i = 0
        x0 = wpts.at[i,'x']
        y0 = wpts.at[i,'y']
        x  = 0
        y = 0
        while dist < 5:
            x = wpts.at[i,'x'] 
            y = wpts.at[i,'y']
            dist = self.CalculateDistance(x0, y0, x, y)
            #print('dist: ', dist)
            i+=1
        self.vehID += 1    
        return [path + str(self.vehID), 'JC1', path, path, self.DistanceFromStopLine(path, (x,y)), (x,y), None, rnd.randint(0, 2), 1, None, None, 0, None]
        #['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', handShakeStatus]
    
                
    def CreateApproachKeyPoints(self):
        """
            This function creates list of dictionary  points for an intersection 
            First letter is the approach leg, 
            Second letter is the depart leg
            Number represent the lane: 0 is inner lane, 1 is outer lane
        """
        
        #Southbound approach
        sw0 = OneCIMKeypoints(key='SW0', x=6.45326, y=-0.197454) 
        sn1 = OneCIMKeypoints(key='SN1', x=6.45326, y=-1.24986)
        se1 = OneCIMKeypoints(key='SE1', x=6.45326, y=-1.24986)
        
        #Northbound approach
        ne0 = OneCIMKeypoints(key='NE0', x=16.1896, y=1.30897) 
        ns1 = OneCIMKeypoints(key='NS1', x=16.1896, y=2.8237)
        nw1 = OneCIMKeypoints(key='NW1', x=16.1896, y=2.8237)
        
        #Westbound approach
        wn0 = OneCIMKeypoints(key='WN0', x=10.5759, y=5.81817) 
        we1 = OneCIMKeypoints(key='WE1', x=9.21734, y=5.81817)
        ws1 = OneCIMKeypoints(key='WS1', x=9.21734, y=5.81817)
        
        #Eastbound approach
        es0 = OneCIMKeypoints(key='ES0', x=12.1985, y=-3.87282) 
        ew1 = OneCIMKeypoints(key='EW1', x=13.6945, y=-3.87282)
        en1 = OneCIMKeypoints(key='EN1', x=13.6945, y=-3.87282)
        
        stopLinesList = [sw0, sn1, se1, ne0, ns1, nw1, wn0, we1, ws1, es0, ew1, en1]
        return stopLinesList
        
        
    def CreateDepartKeyPoints(self):
        """
            This function creates list of dictionary  points for an intersection 
            First letter is the approach leg, 
            Second letter is the depart leg
            Number represent the lane: 0 is inner lane, 1 is outer lane
        """
        sw0 = OneCIMKeypoints(key='SW0', x=10.4326, y=-4.28049) #left-turn: south to West
        sn1 = OneCIMKeypoints(key='SN1', x=5.89548, y=2.60523) #through: South to North
        se1 = OneCIMKeypoints(key='SE1', x=13.4185, y=6.4993) #right-turn: south to east
        
        
        ne0 = OneCIMKeypoints(key='NE0', x=12.131,  y=6.4993) #left-turn: North to east
        ns1 = OneCIMKeypoints(key='NS1', x=16.5769, y=-1.5712) #through: North to South
        nw1 = OneCIMKeypoints(key='NW1', x=9.10096, y=-4.28049) #right-turn: North to West
        
        
        wn0 = OneCIMKeypoints(key='WN0', x=5.89548, y=2.605234) #left-turn: West to North
        we1 = OneCIMKeypoints(key='WE1', x=13.4185, y=6.4993) #through: West to East
        ws1 = OneCIMKeypoints(key='WS1', x=16.5769, y=-1.5712) #right-turn: West to South
        
        es0 = OneCIMKeypoints(key='ES0', x=16.5769, y=-0.216032) #left-turn: West to South
        ew1 = OneCIMKeypoints(key='EW1', x=13.4185, y=6.4993) #through: East to West
        en1 = OneCIMKeypoints(key='EN1', x=5.89548, y=2.60523) #right-turn: East to North
        
        safePointsDepartList = [sw0, sn1, se1, ne0, ns1, nw1, wn0, we1, ws1, es0, ew1, en1]
        return safePointsDepartList
    
    def ExecuteRecVeh(self, vehicleid, junctionid, approachleg, departleg, distfromstopline, point, arrivaltime, speed, priority, stoppedtime, waitingtime):
        """
            This function is used to execute self.RecordTrafficData in a synchronized thread.
        """
        self.lock.acquire()
        self.RecordTrafficData([vehicleid, junctionid, approachleg, departleg, distfromstopline, point, arrivaltime, speed, priority, stoppedtime, waitingtime])
        self.lock.release()
        
    def PublishDSRCMsg(self, veh, topic):
        # print('arrivalTime: ',self.arrivalTime)
        #['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline',
        #'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime']      
        
        pubStatus = False
        pubTime = None
        if veh[11] == 0: #Meaning this vehicle has not publish approach handshake before:
            pubStatus = True
        elif veh[11] == 1: #Vehicle has published but yet to receive acknowledgement
            #Check if since last published message its being 2 seconds
            if ((time.time() - veh[12]) >= 2:
                pubStatus = True
        elif veh[11] == 2 and veh[4] < -2: #publish Depart handshake message
            pubStatus = True
            veh[11] = 3   
                
        if pubStatus:
            dsrcmsg = IntersectionBSM()
            dsrcmsg.vehicleid = veh[0]
            dsrcmsg.junctionid = veh[1]
            dsrcmsg.approachleg = veh[2]
            dsrcmsg.departleg = veh[3]

            dsrcmsg.distfromstopline = veh[4]
            dsrcmsg.point = veh[5]
            dsrcmsg.arrivaltime = veh[6]
            dsrcmsg.speed = float(veh[7]) #rnd.uniform(0, 4) #So that vehicular movement and stops may be properly simulated
            dsrcmsg.stoppedtime = veh[9] if veh[9] is not None else time.time() + 50 #if stoppedtime is not set, set it to a large value so 
            dsrcmsg.timestamp = time.time()

            #publish based on topic
            if topic == 'westpath':
                self.westPublisher.publish(dsrcmsg)
            elif topic == 'eastpath':
                self.eastPublisher.publish(dsrcmsg)
            elif topic == 'northpath':
                self.northPublisher.publish(dsrcmsg)
            elif topic == 'southpath':
                self.southPublisher.publish(dsrcmsg)
            
            
            self.dsrcPublisher.publish(dsrcmsg)
            

            pubTime = time.time()

            self.transTime.loc[len(self.transTime)] = {'vehicleid': veh[0], 
                                                            'transtime': pubTime 
                                                        }
        return pubTime 
        """
        #Assuming that all vehicular messages are received by the controller
        #Thus, instead of just publishing the vehicle data, we record it in the csv file
        #which is used by the central traffic light controller.
        
        #self.RecordTrafficData(veh)
        #Creating a thread to add or update vehicle data in self.trafficData using synchronous threads
        td.Thread(target=self.ExecuteRecVeh, args=(veh)).start() 
        """
        
    def GetStopLine(self, appLeg):
        """
            This function retrieves the approach leg's stop line point from the self.intersectionApproachLegs
        """
        point = None
        for pt in self.intersectionApproachLegs:
            
            if pt.key == appLeg:
                #print(pt.key, ' comapared to ', appLeg)
                point = (pt.x, pt.y)
                #print('New point: ',self.currStopLinePoint)
                #time.sleep(2)
                break
                
        return point
        
                    
    def ChoosePath(self, path, lane):
        """
            This function uses a random number generator to determine randomly 
            which path to follow: left-turn, through, or right-turn at the 
            on the intersection of SN or NS path
        """
        p = path[0]
        #print(path, ', ', lane, ',"', p,'"', type(p) )
        pIdx = rnd.randint(0, 2)
        
        #path = '/home/babangida/ros_ws/src/onecim/paths/Processed/'
        chosenPath = None
        wpts = None
        nWpts = ['ne0pts', 'ns1pts', 'nw1pts'] #['NE0', 'NS1', 'NW1'] 
        sWpts = ['sw0pts', 'sn1pts', 'se1pts'] #['SW0', 'SN1', 'SE1']
        wWpts = ['wn0pts', 'we1pts', 'ws1pts'] #['WN0', 'WE1', 'WS1']
        eWpts = ['es0pts', 'ew1pts', 'en1pts'] #['ES0', 'EW1', 'EN1']
        
        nPaths = ['NE0', 'NS1', 'NW1'] 
        sPaths = ['SW0', 'SN1', 'SE1']
        wPaths = ['WN0', 'WE1', 'WS1']
        ePaths = ['ES0', 'EW1', 'EN1']
        
        #print('pIdx: ', path[0] == ' N ')
        p = path[0]
        #print("Value of p:", p)
        lane = int(lane)
        #The agent is at or going to South
        if path[0] == 'S' and path[1] == 'W':
            wpts = sWpts[0]
        elif path[0] == 'S' and path[1] == 'N':
            wpts = sWpts[1]
        elif path[0] == 'S' and path[1] == 'E':
            wpts = sWpts[2]
        
        elif path[0] == 'N' and path[1] == 'E':
            wpts = nWpts[0]
            #print('pIdx: ', path[0] == ' N ')
        elif path[0] == 'N' and path[1] == 'S':
            wpts = nWpts[1]
        elif path[0] == 'N' and path[1] == 'W':
            wpts = nWpts[2]
            
        elif path[0] == 'W' and path[1] == 'N':
            wpts = wWpts[0]
        elif path[0] == 'W' and path[1] == 'E':
            wpts = wWpts[1]    
        elif path[0] == 'W' and path[1] == 'S':
            wpts = wWpts[2]
            
        elif path[0] == 'E' and path[1] == 'S':
            wpts = eWpts[0]
        elif path[0] == 'E' and path[1] == 'W':
            wpts = eWpts[1]
        elif path[0] == 'E' and path[1] == 'N':
            wpts = eWpts[2]
            
        #The approachLeg, departureLeg, and agentPath store the same velue but used at different locations
        #for different purposes.
       
        #instatiate pure pursuit algorithm with new set of waypoints.
        wptsPath = wpts + '.csv'
        
        return wptsPath
     
    def CalculateDistance(self, x1, y1, x2, y2):
        """
            (x1, y1) is the vehicle point
            (x2, y2) is the stop line (critical point)
        """
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)  
          
    def DistanceFromStopLine(self, appLeg, point):
        """
            Given an approach Leg and a vehicle coordinate point, 
            search for the approach leg's stop line point and calculate
            the distance of vehicle point from the stop line.
        """
        dist = 0.0
        for pt in self.intersectionApproachLegs:
            if pt.key == appLeg:
                x1, y1 = pt.x, pt.y
                x2 = point[0]
                y2 = point[1]
                #print('x1: ', x1, ' y1: ', y1, ' x2: ', x2, ' y2: ', y2)
                dist = self.CalculateDistance(x1, y1, x2, y2)
                break
        return dist
    

    
      
    def ProcessLidar(self, data):
        pass
        #for vehicle in self.vehicles:
        #    self.PublishDSRCMsg(vehicle)
        
        
def main(args=None):
    rclpy.init(args=args)
    print("Hybrid Cooperative Intersection Management Aware South-North Controller Node")
    tVehGen = TimedVehicleGeneration()
    rclpy.spin(tVehGen)
    
    tVehGen.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

