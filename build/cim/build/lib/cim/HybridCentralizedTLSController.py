import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray

import pandas as pd
import numpy as np
from scipy.spatial.distance import cdist

import time
import math

#Import DSRC Message Package
from dsrcmsg.msg import TrafficLightsMessage
from trafficrecord.action import HybridCIM

from rclpy.action import ActionServer

class HybridCIMTLS(Node):
    """
        
    """
    def __init__(self):
        super().__init__('HybridCentralizedTrafficController')
        self.trafficLightPub = self.create_publisher(MarkerArray, '/tlsbulbs', 10)
        self.timer = self.create_timer(0.1, self.SwitchTrafficSignal) 
        self.startTime = 0.0
        self.switch = False
        self.idx = None
        
        self.signalDuration = None
        self.durationCounter = 0
        self.nextSignalDuration = None
        
        self.minPhaseDuration = 5 #Minimum phase duration assignable to a flow
        self.maxPhaseDuration = 9 #Maximum phase duration assignable to a flow
        
        self.scheduledFlows = None #Holds list of flows that have been scheduled to utilize the intersection
        
        self.tlsPub = self.create_publisher(TrafficLightsMessage, '/tls', 10)
        self.tlsBulbsSettings = None
        
        self.trafficData = pd.DataFrame(data={}, columns=['junction', 'approachleg', 'departleg', 'vehicleid', 'vehicletype', 'point', 'speed', 'arrivaltime', 'priority'])
        self._action_server = ActionServer(
            self,
            HybridCIM,
            'hybridcim',
            self.RecordTrafficData)
    
        self.scheduledTime = None
        self.nextScheduleTime = None
        
        self.scheduledVehicles = None
        self.nextScheduledVehicles = None
        
        
    def TLSPublisher(self):
        tlsmsg = TrafficLightsMessage()
        tlsmsg.pathids = self.tlsPath
        tlsmsg.starttime = self.startTime
        tlsmsg.duration = self.signalDuration
        
        print('Green Flow: ', self.tlsPath, ' StartTime: ', self.startTime, ' Duration: ', self.signalDuration)
        self.tlsPub.publish(tlsmsg)
        
    def CreateTrafficLightBulb(self, point, leg, color):
        marker = Marker()
        marker.header.frame_id = 'map'
        marker.scale.x = 0.1
        marker.scale.y = 1.0
        marker.scale.z = 0.1
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
        if 'WEJ' in leg :
            marker.pose.orientation.z = 0.707
            marker.pose.orientation.w = 0.707
        elif  'NSJ' in leg:
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 1.0
        
        return marker
        
    def TrafficLights(self, appLeg, color='green'):
        marker_array = MarkerArray()
        greenPoints = None
        redPoints = None
        self.idx = 0
        self.tlsPath = appLeg #Path to be assigned green wave
        
        if 'NSJ' in appLeg or 'SNJ' in appLeg:
            greenPoints = [(4.0, -0.85), (14.7, -0.85), (15.7, 6), (4.95, 6)]
            redPoints = [(4.5,6.5),  (4.5, -0.25), (15.3, -1.25), (15.3, 5.55)]
            
            self.switch = False
            for point in greenPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NSJ', (0.0, 1.0, 0.0)))
            for point in redPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WEJ', (1.0, 0.0, 0.0)))
        elif 'WEJ' in appLeg or 'EWJ' in appLeg:
            redPoints = [(4.0, -0.85), (14.7, -0.85), (15.7, 6), (4.95, 6)]
            greenPoints = [(4.5,6.5),  (4.5, -0.25), (15.3, -1.25), (15.3, 5.55)]
            
            self.switch = True
            for point in greenPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WEJ', (0.0, 1.0, 0.0)))
            for point in redPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NSJ', (1.0, 0.0, 0.0)))
        
        self.tlsBulbsSettings = marker_array
        
    def GetCompatibleFlows(self, appLeg):
        """
            This function gets the flows that can utilize the intersection without high risk of collision(s)
        """
        appLegs = None
        scheFlows = None 
        if 'NSJ' in appLeg or 'SNJ' in appLeg: # North-South flows are compatible with the appLeg 
            #thus, return the flows and their stop line(s) point
            appLegs =  {'SNJ1': (4.0, -0.85), 'SNJ2': (14.7, -0.85), 'NSJ3':(15.7, 6), 'NSJ4':(4.95, 6)}
            scheFlows = ['SNJ1', 'SNJ2', 'NSJ3', 'NSJ4']
        elif 'WEJ' in appLeg or 'EWJ' in appLeg:
            appLegs = {'WEJ1': (4.5, -0.25), 'EWJ2': (15.3, -1.25), 'EWJ3':(15.3, 5.55), 'WEJ4': (4.5,6.5)}
            scheFlows = ['WEJ1', 'EWJ2', 'EWJ3', 'WEJ4']
        
        self.scheduledFlows = scheFlows
        return appLegs
        
    def GetDistance(self, point1, point2):
        return np.sqrt((point2[0] - point1[0]) ** 2 + (point2[1] - point1[1]) ** 2)
    
    def SetPhaseDuration(self, vehDistances, waitingTime):
        """
            This function set the phase duration for given traffic flow based on waiting time and queue length (number of vehicles or
            distance of the furthest vehicle)waiting at the intersection.
            
            Here models coul be developed to intelligently determine the appropriate phase duration. 
            
            However, for the pupose this simulation.
            If number of vehicle is to be used, queueLength = int(len(vehDistances)/4) to represent average number of vehicles on each approach leg of the 
            intersections to be assigned green wave
            
            if distance is to be used, queueLength = max(vehDistances), to represent the distance of the furthest vehicle.
            
            phaseDuration = int((queueLength * waitingTime)/(queueLength + waitingTime)) or some other model
            
            phase duration needs to be bounded between Minimum and Maximum assignable phase durations
            
        """
        queueLength = max(vehDistances)
        phaseDuration = int((queueLength * waitingTime)/(queueLength + waitingTime))
        self.nextSignalDuration = np.clip(phaseDuration, self.minPhaseDuration, self.maxPhaseDuration)
        
        
        
    
    def SwitchTrafficSignal(self):
        appLeg = None
        duration = time.time() - self.startTime 
        
        maxArivalTime = 0
        
        if (self.signalDuration - self.durationCounter) <= 5: # 5s to end of signal duration
            # Determine the next flow to be assigned the green wave
            
            flowsAndStopLines = None
            vehDistances = np.array([])
            flows = None
            
            #Determine the vehicle with max waiting time
            scheduleIdx = self.trafficData.loc[self.trafficData['arrivaltime'].idxmin()]
            maxWaitingTime = self.trafficData.loc[scheduleIdx]['arrivaltime'] #Get the max waiting time
            
            #get approach leg to be scheduled - having the vehicle with the longest waiting time
            appLeg = self.trafficData[scheduleIdx]['approachleg']
            
            #get compatible flows (other approach legs) that may be scheduled to utilize the intersection 
            #without (or reduced) risk of collision
            flowsAndStopLines = self.GetCompatibleFlows(appLeg)
            
            for flow in flowsAndStopLines:
                #Retrieve vehicles on the same flow as the vehicle with highest waiting time
                vehicles = self.trafficData.loc[self.trafficData['approachleg']== flow]
                
                #determine the furthest vehicle from their stop line on the flow
                flowStopLinePoint = flowsAndStopLines[flow]
                vehiclePoints = np.array(vehicles['point'].tolist())
                distances = cdist(vehiclePoints, np.array([flowStopLinePoint]), 'euclidean')
                vehDistances = np.concatenate((vehDistances, distances), axis=0)
            
            self.SetPhaseDuration(vehDistances, maxWaitingTime)
            
            
            

            
        if self.startTime == 0.0:
            appLeg = 'NSJ'
            
        
        if not self.switch and duration >= self.signalDuration :
            appLeg = 'WEJ'
            
        elif self.switch and duration >= self.signalDuration :
            appLeg = 'NSJ'
             
            
        self.TrafficLights(appLe)
        self.startTime = time.time()
        self.TLSPublisher()
        self.trafficLightPub.publish(self.tlsBulbsSettings)
    
    
    def RecordTrafficData(self, req):
        #if new approach leg, append the leg to Traffic Data
        param = req.request.parameters
        
        #if appleg not in self.trafficData['approachleg'].values:
        self.trafficData.loc[len(self.trafficData)] = {'junction': param.junction, 'approachleg': param.approachleg, 
                                                        'departleg': param.departleg, 'vehicleid': param.vehicleid, 
                                                        'vehicletype': param.vehicletype, 'point':param.point, 'speed': param.speed, 
                                                        'arrivaltime': param.arrivaltime, 'priority': param.priority
                                                    }
                                                    
        
        
        if self.signalDuration == None: #System just starting and no vehicle (or flow) has been scheduled
        
            print('Here')
        
        else: #System has already started and performed a schedule
            if param.vehicleid in self.scheduledVehicles: #This vehicle has been scheduled, return the information to the vehicle
                #df = df.drop(df[(df['column1'] == value1) & (df['column2'] == value2)].index) # Remove vehicle from the waiting vehicle dataframe (list)
                print('Here')
            else: #Provide feedback to the vehicle
                print('Here')
            
        
        
        

def main(args=None):
    rclpy.init(args=args)
    print("Centralized controller of Hybrid CIM and Traffic Lights System Node")
    tls = HybridCIMTLS()
    rclpy.spin(tls)
    
    tls.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()
