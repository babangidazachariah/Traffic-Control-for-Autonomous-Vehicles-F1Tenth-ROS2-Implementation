"""
    In order to better simulate vehicular arrival, have a parameter that specifies 
    number of vehicles per hour - hourlyflowrate 
    Given hourly flow rate, determine second by second flow rate:
        secondflowrate = hourlyflowrate / 3600
    For every second, compute a probability (random number) representing arrival probability.
    Every second, based on probability, add a vehicle to the road segment or network
"""
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
from onecim.FISBasedDecentralizedCIM import FISBasedDecentralizedCIM


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
        
        self.speed = 1.0
        self.recmdedSpeed = 1.0
        
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self) 
        
        #Create IntersectionBSM publisher
        self.dsrcPublisher = self.create_publisher(IntersectionBSM, '/dsrcmsg', 1000) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #Create DSRCMessage subscriber
        #self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/dsrcmsg', self.RecordTrafficData, 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.vehAtCurJunction = {} #Used to maintain a python dictionary of vehicles at the current intersection vehicles are added for current intersection using DSRCMessage subscriber
        
        #Create OneCIMTlsMsg subscriber
        #self.dsrcSubscriber = self.create_subscription(OneCIMTlsMsg, '/tls', self.TlsBasedTrajectoryPlanning, 2) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #Create OneCIMTlsMsg Publisher
        self.tlsPub = self.create_publisher(OneCIMTlsMsg, '/tls', 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        
        #record my intersection traffic data
        self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime'])
        
        self.agentPath = 'SW0'
        self.vehicleID = 'SN1' #North-South or South-North Number: SN1, SN2, ... NS1, NS2, ... Could be plate Number
        self.arrivalTime = 0.0
        self.stoppedTime = 0.0
        self.vehicleType = 1 # Based on vehicle type codes found at https://actar.org/pdf/ca_veh1.pdf
        self.point = Point()
        self.vehiclePriority = 0 #Thus, we specify here our priority standard: 0 mean no priority. Higher values impliy higher priority
        
        self.minGap = 0.7
        self.toFroStopLine = True #set to True when the vehicle is approaching stop line and at certain distance 
                                    #and false whent the vehicle has gone certain distance from the line
        self.atStopLine = False
        self.distFromStopLine = 2000.0 #set to a very large value
        self.MINSTOPLINEDIST = 5.0
        
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
        self.vehPub = self.create_publisher(MarkerArray, '/vehicles', 10)
        self.vehicles = []
        self.drawnVehicles = []
        self.CreateVehicles()
        self.transTime = pd.DataFrame(data={}, columns=['vehicleid', 'transtime']) 
        self.timer = self.create_timer(1, self.StopRecordingTransTime)
        
        
    def StopRecordingTransTime(self):
        diff = time.time() - self.simStartTime 
        #print('Sim Duration:', diff)
        
        if diff >= self.simDuration: #
            path = self.transTime.to_csv('thirtyVehSTLsTransTime.csv') #write recorded waitTime to CSV file for analysis
            #print('Waiting Times file path: ',path)
            #self.PublishDriveCommand()
            rclpy.shutdown()
            
    def CreateVehicles(self):
        """
            This function create simulated virtual vehicles used to test the response time of controllers
            
        """
        
        #L = [0, 1]
        nPaths = ['NE0', 'NS1', 'NW1'] 
        sPaths = ['SW0', 'SN1', 'SE1']
        wPaths = ['WN0', 'WE1', 'WS1']
        ePaths = ['ES0', 'EW1', 'EN1']
        
        allPaths = [nPaths, sPaths, wPaths, ePaths] #[sPaths, ePaths]# [nPaths, sPaths, wPaths, ePaths]

        # Loop through each list and access each element
        for directionPaths in allPaths:
            print(f"Paths for direction: {directionPaths}")
            for path in directionPaths:
               self.CreateVehicle(path)
        print(self.vehicles)
        print('Len: ', len(self.vehicles))
        self.DrawVehicles()
        self.vehPub.publish(self.drawnVehicles)
        
        
    def CreateVehicle(self, path):
        """
            Creates a vehicle information
            tenVehs= [0.8,  2.0, 3.2,  4.8] [sPaths, ePaths] = 24 Virtual vehicles
            fifteenVehs = [0.8,  2.0, 3.2,  4.8, 6.4] [nPaths, sPaths, wPaths, ePaths]
            thirtyVehs = [0.8,  2.0, 3.2,  4.8, 6.4, 7.4, 9.0, 11.0, 13.0, 15.0] [nPaths, sPaths, wPaths, ePaths]
        """
        distFromStop = [0.8,  2.0, 3.2,  4.8, 6.4, 7.4, 9.0, 11.0, 13.0, 15.0]#, 17.0, 19.8, 22.0, 23.0, 25.0, 27.0, 29.0, 32.0, 34.0, 37.0, 40.0, 43.0, 47.0, 50.0]
        wpts = pd.read_csv('/home/babangida/ros_ws/src/onecim/paths/' + self.ChoosePath(path, path[2]))
        ub = int(len(wpts)/2)
        lb = int(ub * 0.2)
        k = len(distFromStop) - 1
        while k > -1: 
            for i in range(lb, ub):
                x = wpts.at[i,'x'] 
                y = wpts.at[i,'y']
                #k = len(distFromStop) - 1
               
                dist = self.DistanceFromStopLine(path, (x,y))
                if dist > distFromStop[k] - 0.5 and dist < distFromStop[k] + 0.5:
                    print('Vehicle Created')
                    #Create the vehicle info.
                    self.vehicles.append([path + str(k), 'JC1', path, path, dist, (x,y), time.time(), rnd.randint(0, 2), 1, time.time(), rnd.randint(0, 20)])
                    break
                    
            k -= 1
                
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
        
    def PublishDSRCMsg(self, veh):
        # print('arrivalTime: ',self.arrivalTime)
        #['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime']      
        dsrcmsg = IntersectionBSM()
        dsrcmsg.vehicleid = veh[0]
        dsrcmsg.junctionid = veh[1]
        dsrcmsg.approachleg = veh[2]
        dsrcmsg.departleg = veh[3]
        
        dsrcmsg.distfromstopline = veh[4]
        dsrcmsg.point = veh[5]
        dsrcmsg.arrivaltime = veh[6]
        dsrcmsg.speed = rnd.uniform(0, 4) #So that vehicular movement and stops may be properly simulated
        
        self.dsrcPublisher.publish(dsrcmsg)
        pubTime = time.time()
        
        self.transTime.loc[len(self.transTime)] = {'vehicleid': veh[0], 
                                                        'transtime': pubTime 
                                                    }
    
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
        if p == 'S':
            wpts = sWpts[lane]
        
        #the agent is at or going to North
        elif p == 'N':
            wpts = nWpts[lane]
            print('pIdx: ', path[0] == ' N ')
        
        #The agent is at or going to West
        elif p == 'W':
            wpts = wWpts[lane]
            
        #The agent is at or going to East
        elif p == 'E':
            wpts = eWpts[lane]
         
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
            marker.scale.y = 1.0
        elif  leg[0] == 'N' or leg[0] == 'S':
            marker.scale.x = 1.0
            marker.scale.y = 0.5
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 0.707
            
        
        return marker
        
    def DrawVehicles(self):
        marker_array = MarkerArray()
        colorCode = None
        redColorCode = (1.0, 0.0, 0.0)
        self.idx = 0
        
        
        
        #print('appLegs: ', appLegs) 
      #['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime']  
        for vehicle in self.vehicles:
            marker_array.markers.append(self.DrawVehicle(vehicle[5], vehicle[2], (0.0, 1.0, 0.0)))
            
        self.drawnVehicles = marker_array
            
    def ProcessLidar(self, data):
        for vehicle in self.vehicles:
            self.PublishDSRCMsg(vehicle)
        
        
def main(args=None):
    rclpy.init(args=args)
    print("Hybrid Cooperative Intersection Management Aware South-North Controller Node")
    cimController = CIMAutonomousVehicle()
    rclpy.spin(cimController)
    
    cimController.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

