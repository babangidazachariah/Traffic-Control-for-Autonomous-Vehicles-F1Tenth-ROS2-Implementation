"""
    In order to better simulate vehicular arrival, have a parameter that specifies 
    number of vehicles per hour - hourlyflowrate 
    Given hourly flow rate, determine second by second flow rate:
        secondflowrate = hourlyflowrate / 3600
    For every second, compute a probability (random number) representing arrival probability.
    Every second, based on probability, add a vehicle to the road segment or network
"""
import os
import shutil
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


class IntegrateTrafficRecords(Node):
    """
        Autonomous Vehicle Controller with DSRC-Based Cooperative Intersection Management Capabilities
        
    """

    def __init__(self):
        """" 
        Initialize the topics, publishers and subscribers
        """
        super().__init__("CIMAutonomousVehicleController")
        
        
        #Create IntersectionBSM publisher
        self.dsrcPublisher = self.create_publisher(IntersectionBSM, '/dsrcmsg', 1000) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        
        #record my intersection traffic data
        self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp'])
        
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
        self.MINSTOPLINEDIST = 10.0
        
        self.approachLeg = 'SW0'
        self.departureLeg = 'SW0'
        self.arrivedDestination = False
        self.checkNextIntersection = True
        self.obstacleInFront = False
        self.frontLidarScan = None
        #Create OneCIMTlsMsg subscriber
        self.dsrcSubscriber = self.create_subscription(OneCIMTlsMsg, '/tls', self.WriteTrafficData, 2) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #Record this vehicle's waiting times at intersections
        
        self.simStartTime = time.time() #record the time the simulation started
        self.simDuration = 900  #declaring how long (in clock seconds) a vehicle to run in this simulation
        self.ResetTrafficData()
       
    def ResetTrafficData(self):
        for fileName in os.listdir('src/onecim/trafficData'):
            filePath = os.path.join('src/onecim/trafficData', fileName)
            try:
                if os.path.isfile(filePath):
                    os.remove(filePath)  # Remove file if it's a regular file
                    print('deteled: ', filePath)
            except Exception as e:
                print(f"Error deleting file {filePath}: {e}")
             
    def WriteTrafficData(self, tlsmsg):
        #Write trafficData to csv file when phase duration remains 2s so that it is available to controller
        dur = time.time() - tlsmsg.starttime
        if (((tlsmsg.duration - dur) > 1) and ((tlsmsg.duration - dur) < 2)):
            #Write the traffic data to file just before the controller accesses it
            #rdy = False
            #remove too old vehicles from self.trafficData
            try:
                eTD = pd.read_csv('src/onecim/trafficData/eastTrafficData.csv')
                print('East TF: ', len(eTD))
                wTD = pd.read_csv('src/onecim/trafficData/westTrafficData.csv')
                print('West TF: ', len(wTD))
                nTD = pd.read_csv('src/onecim/trafficData/northTrafficData.csv')
                print('North TF: ', len(nTD))
                sTD = pd.read_csv('src/onecim/trafficData/southTrafficData.csv')
                print('South TF: ', len(sTD))
                self.trafficData = pd.concat([eTD, wTD, nTD,sTD]).reset_index(drop=True)
                rdy = True
            except Exception as e:
                print("Traffic Data Read Error")
            
            curTime = time.time()
            print("Initial: ", len(self.trafficData))
            
            trafficData = self.trafficData.copy() #Copy current self.trafficData
            
            print('Received ', len(trafficData))
            
            trafficData = trafficData.sort_values(by='timestamp', ascending=False)
            
            # Drop duplicates, keeping only the first occurrence (most recent timestamp)
            trafficData = trafficData.drop_duplicates(subset='vehicleid')
            
            #Drop vehicles whose distFromStopLine is less than (-self.MINSTOPLINEDIST * 0.16) 
            trafficData = trafficData[(trafficData['distfromstopline'] > (-self.MINSTOPLINEDIST * 0.16))]
            
            # Reset index after dropping duplicates
            trafficData = trafficData.reset_index(drop=True)
            
            #while not rdy: #Comment if not sure that traffic data will be available and uncomment if sure
            try:
                trafficData.to_csv('src/onecim/trafficData/trafficData.csv')
                print(len(trafficData), ' written to file')#from ', self.totalVehPub, ' published vehs of ', self.createdCount, ' created Vehs')
                #rdy = True
            except Exception as e:
                print("Traffic Data Read Error")
        
   
def main(args=None):
    
    rclpy.init(args=args)
    print("Node: Integrate Traffic Records")
    itr = IntegrateTrafficRecords()
    
    rclpy.spin(itr)
    
    itr.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

