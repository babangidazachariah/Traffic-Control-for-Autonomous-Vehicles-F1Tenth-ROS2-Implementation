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
        
        
        #Create IntersectionBSM publisher
        self.dsrcPublisher = self.create_publisher(IntersectionBSM, '/dsrcmsg', 1000) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #Create DSRCMessage subscriber
        #self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/dsrcmsg', self.RecordTrafficData, 200) # qos_profile=rclpy.qos.qos_profile_system_default)
        #self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/southpath', self.RecordTrafficData, 200) # qos_profile=rclpy.qos.qos_profile_system_default)
        #self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/northpath', self.RecordTrafficData, 200) # qos_profile=rclpy.qos.qos_profile_system_default)
        #self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/eastpath', self.RecordTrafficData, 200) # qos_profile=rclpy.qos.qos_profile_system_default)
        self.dsrcSubscriber = self.create_subscription(IntersectionBSM, '/westpath', self.RecordTrafficData, 50) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        #record my intersection traffic data
        self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp'])
        self.northTrafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp'])
        self.southTrafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp'])
        self.westTrafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp'])
        self.eastTrafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime', 'timestamp'])
        
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
        
       
    
    def WriteTrafficData(self, tlsmsg):
        #Write trafficData to csv file when phase duration remains 2s so that it is available to controller
        dur = time.time() - tlsmsg.starttime
        if (((tlsmsg.duration - dur) > 2) and ((tlsmsg.duration - dur) < 3)):
            #Write the traffic data to file just before the controller accesses it
            #rdy = False
            #remove too old vehicles from self.trafficData
            curTime = time.time()
            print("Initial: ", len(self.westTrafficData))
            #"""
            try:
                self.westTrafficData = self.westTrafficData[curTime - self.westTrafficData['timestamp'] <= 30]
            except IndexError as e:
                curTime = 0
            #"""
            trafficData = self.westTrafficData.copy() #Copy current self.trafficData
            self.westTrafficData.drop(self.westTrafficData.index)
            
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
                trafficData.to_csv('src/onecim/trafficData/westTrafficData.csv')
                print(len(trafficData), ' written to file')#from ', self.totalVehPub, ' published vehs of ', self.createdCount, ' created Vehs')
                #rdy = True
            except Exception as e:
                print("Traffic Data Read Error")
        
    def InsertNewRecord(self, msg):
        """
            Insert new traffic data of a given vehicle
        """
        #Delete instance of this vehicle that exist for a different flow
        #print('msg.vehicleid', msg.vehicleid)
        #self.trafficData = self.trafficData[~((self.trafficData['vehicleid'] == msg.vehicleid) & (self.trafficData['approachleg'] != msg.approachleg))]
    
        self.westTrafficData.loc[len(self.westTrafficData)] = {'vehicleid': msg.vehicleid, 
                                                        'junctionid': msg.junctionid, 
                                                        'approachleg': msg.approachleg, 
                                                        'departleg': msg.departleg,
                                                        'vehicletype': msg.vehicletype, 
                                                        'distfromstopline':msg.distfromstopline, 
                                                        'point':tuple(msg.point), 
                                                        'arrivaltime': msg.arrivaltime, 
                                                        'speed': msg.speed, 
                                                        'priority': msg.priority,
                                                        'stoppedtime':msg.stoppedtime,
                                                        'timestamp':msg.timestamp
                                                    }
    def DeleteVehicleFromIntersection(self, vehicleid, approachleg):
        #print('Deleting Veh: ', vehicleid, ' on approach: ', approachleg)
        #Get the vehicle to be deleted and compute the delay in the system
        #tmpTFData = self.trafficData[((self.trafficData['vehicleid'] == vehicleid) & (self.trafficData['approachleg'] == approachleg))]
        
        #Delete the vehicle
        self.westTrafficData = self.westTrafficData[~((self.westTrafficData['vehicleid'] == vehicleid) & (self.westTrafficData['approachleg'] == approachleg))]
        """
        #Compute the delay:
        if not math.isnan(tmpTFData['waitingtime']):
            self.waitingTime += tmpTFData['waitingtime']
            self.waitingTimeCounter += 1
        elif not math.isnan(tmpTFData['stoppedtime']):
            wTime = time.time() - tmpTFData['stoppedtime']
            self.waitingTime += wTime
            self.waitingTimeCounter += 1
        else:
            self.waitingTimeCounter += 1 #meaning waiting time is zero as vehicle never stopped
        print('Sum of Waiting Time: ',self.waitingTime)
        print('Number of times Waiting Times habe been computed: ', self.waitingTimeCounter)
        print('Average of waiting time so far: ', (self.waitingTime/self.waitingTimeCounter))
        """
    def RecordTrafficData(self, msg): 
        """
            This function receives a DSRC Message from vehicl(s), checks if the vehicle already exist in trafficData for the present intersection
            If the vehicle has already been added, it updates location/point, speed, distancetostopline
        """
        if msg.distfromstopline > -(self.MINSTOPLINEDIST * 0.16):
            self.InsertNewRecord(msg)
        else:
            self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
        """
        idx = None 
        
        #print('VehicleID: ', msg.vehicleid)
        #print('Before: ', self.trafficData)
        curTime = time.time()
        
        try:
            self.trafficData = self.trafficData[curTime - self.trafficData['timestamp'] <= 80]
        except IndexError as e:
            curTime = 0
        
        #check if self.trafficData is not empty
        if len(self.trafficData) > 0: #There is a record in it
            try:
                #try to retrieve the vehicle record nat the current intersection
                idx = self.trafficData[((self.trafficData['vehicleid'] == msg.vehicleid) & (self.trafficData['approachleg'] == msg.approachleg))].index[0]
                
                if msg.distfromstopline > (-self.MINSTOPLINEDIST * 0.16) : #vehicle is yet past the intersection, thus, we update its data
                    #if the vehicle exist, we check its speed to see if it is zero (0)
                    if msg.speed == 0:
                        #it means vehicle stoped because of signal or some other vehicle
                        if math.isnan(self.trafficData.at[idx, 'stoppedtime']):
                            #mean it has not been recorded previously.
                            self.trafficData.at[idx, 'stoppedtime'] = time.time()
                            
                    else: 
                        #print('Vehicle Speed is not Zero')
                        if not math.isnan(self.trafficData.at[idx, 'stoppedtime']):
                            #meaning the vehicle had stopped and is now moving, thus we computes
                            #its waiting and store it in the waiting time fiel
                            self.trafficData.at[idx, 'waitingtime'] = time.time() - self.trafficData.at[idx, 'stoppedtime']
                            
                    #update disttostoline, point, and speed
                    pointTuple = tuple(msg.point)
                    #print('Tuple Value: ', pointTuple)

                    # Assign values to 'point' and 'speed' columns separately
                    self.trafficData.at[idx, 'point'] = pointTuple
                    self.trafficData.at[idx, 'speed'] = msg.speed
                    self.trafficData.at[idx, 'distfromstopline'] = msg.distfromstopline
                    self.trafficData.at[idx, 'timestamp'] = time.time()
                    print("Updated vehicle: ", msg.vehicleid)
                else: #Vehicle has gone past the intersection, thus we remove it from the record
                    #delete vehicle record from dataframe
                    print('Deleting: ',msg.vehicleid)
                    #print(self.trafficData)
                    self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
                    #print('After Deleting: ',msg.vehicleid)
                    #print(self.trafficData)
                    
            except IndexError as e:
                if idx is None: #Just to confirm that generated the error that hindered updates, which means vehicle is not in the dataframe
                    #When it fails to retrieve idx, it means record for the vehicle at the current intersection does not exist.
                    #We add it as a new record
                    if msg.distfromstopline > (-self.MINSTOPLINEDIST * 0.16): 
                        self.InsertNewRecord(msg)
                        print("Inserted vehicle: ", msg.vehicleid)
                    else:
                        self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
        else: #this is the first record to be inserted  
            if msg.distfromstopline > (-self.MINSTOPLINEDIST * 0.16):
                self.InsertNewRecord(msg)
                print("Inserted vehicle: ", msg.vehicleid)
            else:
                self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
                print('Deleting: ',msg.vehicleid)
                
        #print('After: ', self.trafficData)
        #Write dataframe to csv file
        self.trafficData.to_csv('src/onecim/trafficData/trafficData.csv')
        print('All Traffic Data: ', len(self.trafficData))
        """
        
def main(args=None):
    rclpy.init(args=args)
    print("Traffic Recording Node")
    cimController = CIMAutonomousVehicle()
    rclpy.spin(cimController)
    
    cimController.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

