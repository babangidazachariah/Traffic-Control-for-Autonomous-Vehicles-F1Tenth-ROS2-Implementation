import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray

import pandas as pd
import numpy as np
from scipy.spatial.distance import cdist
from scipy.stats import hmean

import time
import math
import random

#Import DSRC Message Package
from dsrcmsg.msg import IntersectionBSM, TrafficLightsMessage, OneCIMTlsMsg, OneCIMKeypoints


from cim.FISTrafficSignalOptimizer import FuzzyIntersectionManager

from rclpy.action import ActionServer

class FISBasedOneCIMTLS(Node):
    """
        OneCIMTlsMsg.msg
        
    """
    def __init__(self):
        super().__init__('HybridCentralizedTrafficController')
        self.trafficLightPub = self.create_publisher(MarkerArray, '/tlsbulbs', 10)
        self.dsrcmsSub = self.create_subscription(IntersectionBSM, '/dsrcmsg', self.RecordTrafficData, 10)
        self.timer = self.create_timer(0.1, self.SwitchTrafficSignal) 
        self.startTime = 0.0
        self.switch = False
        self.idx = None
        self.tlsPaths = []
        self.MINSTOPLINEDIST = 3.0
        
        self.signalDuration = 0
        self.durationCounter = 0
        self.nextSignalDuration = 5 #Set this value to serve as the initial condition in SwitchTrafficSignal()
        self.nextSchedulePerformed = False
        
        self.recommendedSpeed = 0
        self.nextRecommendedSpeed = 0
        self.nextFlow = None #A set of compatible flows to be assigned green wave in the next phase
        
        self.minPhaseDuration = 5 #Minimum phase duration assignable to a flow
        self.maxPhaseDuration = 9 #Maximum phase duration assignable to a flow
        
        self.scheduledFlows = None #Holds list of flows that have been scheduled to utilize the intersection
        
        self.tlsPub = self.create_publisher(OneCIMTlsMsg, '/tls', 10)
        self.tlsBulbsSettings = None
        
        
        self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority'])
        
        self.scheduledTime = None
        self.nextScheduleTime = None
        
        self.scheduledVehicles = None
        self.nextScheduledVehicles = None
        self.fiscontroller = FuzzyIntersectionManager()
        
        #OneCIM notable points
        self.approachLegs = self.CreateApproachKeyPoints() #{'EW': (5.67632, -4.22149), 'SN': (1.01726, -0.787557), 'WE': (4.04208, 3.99244), 'NS':(9.7611, 0.740437) }
        self.departLegs = self.CreateDepartKeyPoints() #{'EW':(6.11296, 3.86962), 'SN': (9.48962, -0.8483), 'WE': (4.03338, -4.06445), 'NS': (1.03482, 1.0365)}
        
    def CreateApproachKeyPoints(self):
        """
            This function creates list of dictionary  points for an intersection 
        """
        dict1 = OneCIMKeypoints(key='EW', x=5.67632, y=-4.22149)
        dict2 = OneCIMKeypoints(key='SN', x=0.527696, y=-0.747791)
        dict3 = OneCIMKeypoints(key='WE', x=4.11425, y=4.30944)
        dict4 = OneCIMKeypoints(key='NS', x=9.7611, y=0.740437)
        
        my_list = [dict1, dict2, dict3, dict4]
        return my_list
        
        
    def CreateDepartKeyPoints(self):
        dict1 = OneCIMKeypoints(key='EW', x=6.11296, y=3.86962)
        dict2 = OneCIMKeypoints(key='SN', x=9.48962, y=-0.8483)
        dict3 = OneCIMKeypoints(key='WE', x=4.03338, y=-4.06445)
        dict4 = OneCIMKeypoints(key='NS', x=1.03482, y=1.0365)
        my_list = [dict1, dict2, dict3, dict4]
        return my_list
        
    def TLSPublisher(self):
        #print('Publishing tls')
        #print('self.signalDuration: ', self.signalDuration)
        if len(self.tlsPaths) > 0:
            print('self.tlsPaths', self.tlsPaths)
            tlsmsg = OneCIMTlsMsg(pathids = self.tlsPaths, starttime = self.startTime, duration = float(self.signalDuration),
                                approachpoints=self.approachLegs, departpoints=self.departLegs)
        #print(self.tlsPaths)
        #tlsmsg.pathids = self.tlsPaths
        #tlsmsg.starttime = self.startTime
        #tlsmsg.duration = float(self.signalDuration)
        #OneCIMTlsMsg(tlsmsg.approachpoints=self.approachLegs) 
        #OneCIMTlsMsg(tlsmsg.departpoints=self.departLegs)
        #tlsmsg.speed = float(self.recommendedSpeed)
        
        #print('Green Flow: ', self.tlsPaths, ' StartTime: ', self.startTime, ' Duration: ', self.signalDuration)
        self.tlsPub.publish(tlsmsg)
        
    def CreateTrafficLightBulb(self, point, leg, color):
        marker = Marker()
        marker.header.frame_id = 'map'
        marker.scale.x = 0.2
        marker.scale.y = 1.55
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
        if 'WE' in leg :
            marker.pose.orientation.z = 0.707
            marker.pose.orientation.w = 0.707
        elif  'NS' in leg:
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 1.0
        
        return marker
        
    def TrafficLights(self, appLeg, color='green'):
        marker_array = MarkerArray()
        greenPoints = None
        redPoints = None
        self.idx = 0
        
        if color =='yellow':
            if 'NS' in appLeg:
            
                greenPoints = [(1.01726, -0.787557), (9.7611, 0.740437)]
                redPoints = [(5.67632, -4.22149),  (4.04208, 3.99244)]
                
                self.switch = False
                for point in greenPoints:
                    marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NS', (1.0, 1.0, 0.0)))
                for point in redPoints:
                    marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WE', (1.0, 0.0, 0.0)))
            elif 'WE' in appLeg:
                redPoints = [(1.01726, -0.787557), (9.7611, 0.740437)]
                greenPoints = [(5.67632, -4.22149),  (4.04208, 3.99244)]
                               
                self.switch = True
                for point in greenPoints:
                    marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WE', (1.0, 1.0, 0.0)))
                for point in redPoints:
                    marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NS', (1.0, 0.0, 0.0)))

            
        elif 'NS' in appLeg or 'SN' in appLeg:
            greenPoints = [(1.01726, -0.787557), (9.7611, 0.740437)]
            redPoints = [(5.67632, -4.22149),  (4.04208, 3.99244)]
                
            self.switch = False
            for point in greenPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NS', (0.0, 1.0, 0.0)))
            for point in redPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WE', (1.0, 0.0, 0.0)))
        elif 'WE' in appLeg or 'EW' in appLeg:
            redPoints = [(1.01726, -0.787557), (9.7611, 0.740437)]
            greenPoints = [(5.67632, -4.22149),  (4.04208, 3.99244)]
                 
            self.switch = True   
            for point in greenPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WE', (0.0, 1.0, 0.0)))
            for point in redPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NS', (1.0, 0.0, 0.0)))
        
        self.tlsBulbsSettings = marker_array
        
    def GetCompatibleFlows(self, appLeg):
        """
            This function gets the flows that can utilize the intersection without high risk of collision(s)
        """
        appLegs = None
        scheFlows = None 
        if appLeg == 'NS' or appLeg == 'SN':
            scheFlows = ['SN','NS']
        if appLeg == 'WE' or appLeg == 'EW':
            scheFlows = ['EW','WE']
                
        #self.tlsPaths = scheFlows
        return scheFlows
        
    def GetDistance(self, point1, point2):
        return np.sqrt((point2[0] - point1[0]) ** 2 + (point2[1] - point1[1]) ** 2)
    
    
    def StartFromInitial(self):
        #Assigns yellow phase to a random set of compatible flows: signal phase
        appLeg = None
        if random.randint(1, 2) == 1:
            appLeg = 'NS'
        else:
            appLeg = 'WE'
        self.signalDuration = 5
        self.recommendedSpeed = random.randint(1, 4)
        self.nextFlow = self.GetCompatibleFlows(appLeg)
        
        
    def DistanceFromStopLine(self, appLeg, point):
        """
            Given an approach Leg and a vehicle coordinate point, 
            search for the approach leg's stop line point and calculate
            the distance of vehicle point from the stop line.
        """
        dist = 0.0
        for pt in self.approachLegs:
            if pt.key == appLeg:
                x1, y1 = pt.x, pt.y
                x2 = point[0]
                y2 = point[1]
                #print('x1: ', x1, ' y1: ', y1, ' x2: ', x2, ' y2: ', y2)
                dist = self.CalculateDistance(x1, y1, x2, y2)
                break
        return dist
        
    def CalculateDistance(self, x1, y1, x2, y2):
        """
            (x1, y1) is the vehicle point
            (x2, y2) is the stop line (critical point)
        """
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2) 
        
    def ComputePhaseDuration(self, appLeg, point, speed):
        """
            This function computes the distance between a vehicle and its stop line
            then computes the time required for the vehicle to arrive the stop at the 
            given speed
        """
        dist = 0.0
        
        for pt in self.approachLegs:
            if pt.key == appLeg:
                x1, y1 = pt.x, pt.y
                x2 = point[0]
                y2 = point[1]
                #print('x1: ', x1, ' y1: ', y1, ' x2: ', x2, ' y2: ', y2)
                dist = self.CalculateDistance(x1, y1, x2, y2)
                #dist = self.GetDistance(value, point)
                break
        if speed != 0:
            t = math.ceil(dist/speed) #+ 5
        else:
            t = dist
        return t
        
        
    def SwitchTrafficSignal(self):
        appLeg = None
        duration = time.time() - self.startTime 
        
        maxArivalTime = 0
        
        if (self.signalDuration - duration) > 0 and (self.signalDuration - duration) <= 2 and not self.startTime == 0.0 and not self.nextSchedulePerformed: # 5s to end of signal duration
            #Determine if there are vehicles within the region of intersections
            
            if len(self.trafficData) > 0:
                # Determine the next flow to be assigned the green wave
                
                flowsAndStopLines = None
                vehDistances = np.array([])
                flows = None
                maxDistance = 0
                maxQueueLength = 0
                vehicleSpeeds = []
                
                #Determine the vehicle with max waiting time
                #scheduleIdx = self.trafficData.loc[self.trafficData['arrivaltime'].idxmin()]
                scheduleIdx = self.trafficData['arrivaltime'].idxmin()
                maxWaitingTime = self.trafficData.loc[scheduleIdx]['arrivaltime'] #Get the max waiting time
                
                #get approach leg to be scheduled - having the vehicle with the longest waiting time
                appLeg = self.trafficData.loc[scheduleIdx]['approachleg']
                
                #print('self.nextFlow: ', self.nextFlow)
                #print('appLeg', appLeg)
                
                #check to see if the next chosen flow to be assigned green wave is the same as the current flow, which has the green signal
                if appLeg == self.nextFlow:
                    altAppLeg = None
                    if appLeg == "NS":
                        altAppLeg = 'SN'
                    elif appLeg == "SN":
                        altAppLeg = 'NS'
                    elif appLeg == "WE":
                        altAppLeg = 'EW'
                    elif appLeg == "EW":
                        altAppLeg = 'WE'
                     
                    print('appLeg: ', appLeg)
                    #check to see if there is a vehicle waiting at any the intersection on the other flows
                    #the is to avoid denial of service for other flows
                    tmpTfData = self.trafficData[~((self.trafficData['approachleg'].str.contains(appLeg)) | (self.trafficData['approachleg'].str.contains(altAppLeg)))]
                    print('Traffic Data', tmpTfData)
                    if len(tmpTfData) > 0:
                        appLeg = tmpTfData['approachleg'].iloc[0] #set the approach leg to the first element in the temp trafficData
                        maxWaitingTime = tmpTfData['arrivaltime'].iloc[0] # Reset the waiting to the waiting time of the chosen vehicle
                print('New appLeg: ', appLeg)        
                
                #get compatible flows (other approach legs) that may be scheduled to utilize the intersection 
                #without (or reduced) risk of collision
                flows = self.GetCompatibleFlows(appLeg)
                
                for flow in flows:
                    #Retrieve vehicles on the same flow as the vehicle with highest waiting time
                    vehicles = self.trafficData.loc[self.trafficData['approachleg']== flow]
                    if len(vehicles) > maxQueueLength:
                        maxQueueLength = len(vehicles)
                    
                    #determine the furthest vehicle from their stop line on the flow
                    if len(vehicles) > 0:
                        for idx, vehicle in vehicles.iterrows():
                            dist = self.DistanceFromStopLine(vehicle['approachleg'], vehicle['point'])
                            vehicleSpeeds.append(vehicle['speed'])
                            if dist > maxDistance:
                                maxDistance = dist
                   
                #wTime, qLength, speed, distance
                
                meanSpeed = 0
                vehicleSpeeds = np.array(vehicleSpeeds)
                if np.all(vehicleSpeeds > 0):
                    meanSpeed = hmean(vehicleSpeeds)
                else:
                    meanSpeed = max(vehicleSpeeds)
                    
                maxWaitingTime = time.time() - maxWaitingTime
                self.nextSignalDuration, self.nextRecommendedSpeed = self.fiscontroller.EvaluateFis(maxWaitingTime, maxQueueLength, meanSpeed, maxDistance)
                self.nextFlow = flows
                #print('Next Flow: ', self.nextFlow, ' Wait Time: ', maxArivalTime, ' Queue Len: ', maxQueueLength, ' Phase Dur: ', self.nextSignalDuration)
            else:
                #print('len(self.trafficData) <= 0')
                self.nextRecommendedSpeed = random.randint(1, 4)
                self.nextSignalDuration = 5
                
        elif (self.signalDuration - duration) <= 0:  #Switch signals to the next signal duration and next recommended speed 
            #print(' elif (self.signalDuration - duration) <= 0')
            if self.nextSignalDuration == 5:
                #print('self.nextSignalDuration == 5: Restarting From Initial')
                #create yellow traffic lights for a random flow
                self.StartFromInitial()
                self.TrafficLights(self.nextFlow,'yellow')
            else:
                self.TrafficLights(self.nextFlow,'green')
                
            self.signalDuration = math.floor(self.nextSignalDuration)
            self.recommendedSpeed = self.nextRecommendedSpeed
            self.nextSchedulePerformed = False
            self.tlsPaths = self.nextFlow
            #set traffic lights systems
            
            
            self.startTime = time.time()
            self.trafficLightPub.publish(self.tlsBulbsSettings)
        elif  self.startTime == 0.0:
            #Just starting system
            #print('(Re)Starting Traffic Lights')
            self.StartFromInitial()
        #print('Executing TLSPublisher')
        #print('Remaining: ', self.signalDuration - duration)
        self.TLSPublisher()
        
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
    def DeleteVehicleFromIntersection(self, vehicleid, approachleg):
        self.trafficData = self.trafficData[~((self.trafficData['vehicleid'] == vehicleid) & (self.trafficData['approachleg'] == approachleg))]
        

    def RecordTrafficData(self, msg): 
        """
            This function receives a DSRC Message from vehicl(s), checks if the vehicle already exist in trafficData for the present intersection
            If the vehicle has already been added, it updates location/point, speed, distancetostopline
        """
        #print('VehicleID: ', msg.vehicleid)
        idx = None 
        #print('Before', self.trafficData)
        #check if self.trafficData is not empty
        if len(self.trafficData) > 0: #There is a record in it
            try:
                #try to retrieve the vehicle record nat the current intersection
                idx = self.trafficData[((self.trafficData['vehicleid'] == msg.vehicleid) & (self.trafficData['approachleg'] == msg.approachleg))].index[0]
                
                if msg.distfromstopline > -self.MINSTOPLINEDIST/3 : #vehicle is yet past the intersection, thus, we update its data
                    #update disttostoline, point, and speed
                    pointTuple = tuple(msg.point)
                    #print('Tuple Value: ', pointTuple)

                    # Assign values to 'point' and 'speed' columns separately
                    self.trafficData.at[idx, 'point'] = pointTuple
                    self.trafficData.at[idx, 'speed'] = msg.speed
                    self.trafficData.at[idx, 'distfromstopline'] = msg.distfromstopline
                else: #Vehicle has gone past the intersection, thus we remove it from the record
                    #delete vehicle record from dataframe
                    #print('Deleting: ',msg.vehicleid)
                    #print(self.trafficData)
                    self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
                    #print('After Deleting: ',msg.vehicleid)
                    #print(self.trafficData)
                    
            except IndexError as e:
                if idx is None: #Just to confirm that generated the error that hindered updates, which means vehicle is not in the dataframe
                    #When it fails to retrieve idx, it means record for the vehicle at the current intersection does not exist.
                    #We add it as a new record
                    if msg.distfromstopline > -self.MINSTOPLINEDIST/2.5: 
                        self.InsertNewRecord(msg)
                    else:
                        self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
        else: #this is the first record to be inserted  
            if msg.distfromstopline > -self.MINSTOPLINEDIST/2.5:
                self.InsertNewRecord(msg)
            else:
                self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
                
        #print('Before', self.trafficData)
        
def main(args=None):
    rclpy.init(args=args)
    print("Hybrid FIS-Based CIM and Traffic Lights System Node")
    tls = FISBasedOneCIMTLS()
    rclpy.spin(tls)
    
    tls.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()
