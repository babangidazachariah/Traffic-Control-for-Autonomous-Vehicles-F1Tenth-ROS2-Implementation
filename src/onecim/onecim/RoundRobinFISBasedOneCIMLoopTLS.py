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


from onecim.FISTrafficSignalOptimizer import FuzzyIntersectionManager

from rclpy.action import ActionServer

class RoundRobinFISOneCIMLoopTLS(Node):
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
        self.MINSTOPLINEDIST = 5.0
        
        self.signalDuration = 0
        self.durationCounter = 0
        self.nextSignalDuration = 5 #Set this value to serve as the initial condition in SwitchTrafficSignal()
        self.nextSchedulePerformed = False
        
        self.recommendedSpeed = 0
        self.nextRecommendedSpeed = 0
        self.nextFlows = None #A set of compatible flows to be assigned green wave in the next phase
        
        self.minPhaseDuration = 15 #Minimum phase duration assignable to a flow
        self.maxPhaseDuration = 30 #Maximum phase duration assignable to a flow
        
        self.scheduledFlows = None #Holds list of flows that have been scheduled to utilize the intersection
        
        self.tlsPub = self.create_publisher(OneCIMTlsMsg, '/tls', 10)
        self.tlsBulbsSettings = None
        
        
        self.trafficData = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime'])
        
        self.scheduledTime = None
        self.nextScheduleTime = None
        
        self.waitingTime = 0.0
        self.waitingTimeCounter = 0
        self.fiscontroller = FuzzyIntersectionManager()
        
        #OneCIM notable points
        self.approachLegs = self.CreateApproachKeyPoints() #{'EW': (5.67632, -4.22149), 'SN': (1.01726, -0.787557), 'WE': (4.04208, 3.99244), 'NS':(9.7611, 0.740437) }
        self.departLegs = self.CreateDepartKeyPoints() #{'EW':(6.11296, 3.86962), 'SN': (9.48962, -0.8483), 'WE': (4.03338, -4.06445), 'NS': (1.03482, 1.0365)}
        
        self.waitTimeRecord = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime'])
        self.phasePointer = 0 #It is inceremented before reference in SwitchTrafficSignal
        self.phaseSequence = ['SW0','SN1','ES0','EW1']
        self.waitTimeRecord = pd.DataFrame(data={}, columns=['vehicleid', 'junctionid', 'approachleg', 'departleg', 'distfromstopline', 'point', 'arrivaltime', 'speed', 'priority', 'stoppedtime', 'waitingtime'])
        self.recieveTime = pd.DataFrame(data={}, columns=['vehicleid', 'recievetime']) 
        self.compTime = pd.DataFrame(data={}, columns=['starttime', 'endtime','phaseDuration']) 
        self.simStartTime = time.time()
        self.timer = self.create_timer(1, self.StopRecordingReceiveTime)
        self.simDuration = 900
        
        #Benchmark Model Parameters
        self.curPhase = None
        self.nextPhase = None
        
        
    def StopRecordingReceiveTime(self):
        diff = time.time() - self.simStartTime 
        #print('Sim Duration:', diff)
        
        if diff >= self.simDuration: #
            path = self.recieveTime.to_csv('thirtyVehSTLsReceiveTime.csv') #write recorded waitTime to CSV file for analysis
            #print('Waiting Times file path: ',path)
            path = self.compTime.to_csv('thirtyVehSTLsCompTime.csv')
            
            
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
        
    def TLSPublisher(self):
        #print('Publishing tls')
        #print('self.signalDuration: ', self.signalDuration)
        dur = time.time() - self.startTime
        if dur <= 3:
            tlsmsg = OneCIMTlsMsg(pathids = ['ALL-RED'], starttime = self.startTime, duration = float(self.signalDuration),
                                approachpoints=self.approachLegs, departpoints=self.departLegs)
        else:
            tlsmsg = OneCIMTlsMsg(pathids = self.tlsPaths, starttime = self.startTime, duration = float(self.signalDuration),
                                approachpoints=self.approachLegs, departpoints=self.departLegs)
        
        #tlsmsg = OneCIMTlsMsg(pathids = self.tlsPaths, starttime = self.startTime, duration = float(self.signalDuration),
        #                        approachpoints=self.approachLegs, departpoints=self.departLegs)
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
        marker.scale.y = 1.5
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
            marker.pose.orientation.z = 0.707
            marker.pose.orientation.w = 0.707
        elif  leg[0] == 'N' or leg[0] == 'S':
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 1.0
        
        return marker
        
    def TrafficLights(self, appLegs, color='green'):
        marker_array = MarkerArray()
        colorCode = None
        redColorCode = (1.0, 0.0, 0.0)
        self.idx = 0
        
        if color == 'yellow':
            colorCode = (1.0, 1.0, 0.0)
        elif color == 'green':
            colorCode = (0.0, 1.0, 0.0)
        elif color == 'red':
            colorCode = (1.0, 0.0, 0.0)
        
        #print('appLegs: ', appLegs) 
        
        for pt in self.approachLegs:
            if pt.key in appLegs:
                x1, y1 = pt.x, pt.y
                marker_array.markers.append(self.CreateTrafficLightBulb((pt.x, pt.y), pt.key, colorCode))
            else:
                marker_array.markers.append(self.CreateTrafficLightBulb((pt.x, pt.y), pt.key, redColorCode))
        
        self.tlsBulbsSettings = marker_array
        
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
        
        
        
    def GetDistance(self, point1, point2):
        return np.sqrt((point2[0] - point1[0]) ** 2 + (point2[1] - point1[1]) ** 2)
    
    
    def StartFromInitial(self):
        #Assigns yellow phase to a random set of compatible flows: signal phase
        appLeg = None
        deptLeg = None
        nxtLeg = None
        rndNum = random.randint(1, 4)
        if rndNum == 1:
            appLeg = 'SW0'
            #nxtLeg = 'SE1'
        elif rndNum == 2:
            appLeg = 'ES0'
            #nxtLeg = 'EN1'
        elif rndNum == 3:
            appLeg = 'EW1'
            #nxtLeg = 'SW0'
        else:
            appLeg = 'SN1'
            #nxtLeg = 'ES0'
            
        deptLeg = appLeg
        self.nextSignalDuration = self.minPhaseDuration
        self.nextRecommendedSpeed = random.randint(1, 4)
        self.nextFlows = self.GetConcurrentFlows(appLeg, deptLeg)
        #self.curPhase = self.nextFlows
        #self.nextPhase = self.GetConcurrentFlows(nxtLeg, nxtLeg)
        #print('Next Phase::: ', self.nextPhase)
        
    
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
        
        #print('Duration: ', (self.signalDuration - duration))
        
        if (self.signalDuration - duration) > 0 and (self.signalDuration - duration) < 1 and not self.startTime == 0.0 and not self.nextSchedulePerformed: # 5s to end of signal duration
            
            self.nextSchedulePerformed = True
            start = time.time()
            
            
            # Determine the next flow to be assigned the green wave
            self.nextFlows = self.GetConcurrentFlows(self.phaseSequence[self.phasePointer],self.phaseSequence[self.phasePointer])
            
            print('Switched Traffic Lights to ', self.nextFlows)
            
            rdy = False
            #while not rdy: #Comment if not sure that traffic data will be available and uncomment if sure
            try:
                self.trafficData = pd.read_csv('src/onecim/trafficData/trafficData.csv')
                rdy = True
            except Exception as e:
                print("Traffic Data Read Error")
                self.startTime = 0.0 #Restarting the system if traffic data could not be read
            
            #Get vehicles on the approaches to be scheduled
            tmpTFData = None
            maxQueueLength = 0
            maxDistance = 0
            maxWaitingTime =0
            meanSpeed = 0
            print('Traffic Data: ', len(self.trafficData))
            if len(self.trafficData) > 0:
                for appLeg in self.nextFlows:
                    vehs = self.trafficData[self.trafficData['approachleg'] == appLeg]
                    if len(vehs) > maxQueueLength:
                        maxQueueLength = len(vehs)
                        
                    if tmpTFData is None:
                        tmpTFData = vehs.copy()
                    else:
                        tmpTFData = pd.concat([tmpTFData, vehs], ignore_index=True)
                if len(tmpTFData) > 0:
                    curTime = time.time()
                    
                    maxWaitingTime = curTime - (tmpTFData[curTime - tmpTFData['stoppedtime'] > 0].min()['stoppedtime'])
                    maxDistance = tmpTFData['distfromstopline'].max()
                    
                    vehicleSpeeds = np.array(tmpTFData['speed'])
                    if np.all(vehicleSpeeds > 0):
                        meanSpeed = hmean(vehicleSpeeds)
                    else:
                        meanSpeed = max(vehicleSpeeds)
                    
            
            self.nextSignalDuration, self.nextRecommendedSpeed = self.fiscontroller.EvaluateFis(maxWaitingTime, maxQueueLength, meanSpeed, maxDistance)
            self.nextSignalDuration += 2 #Adding the red clearance phase
            
            
            self.phasePointer += 1
            if self.phasePointer > 3:
                self.phasePointer = 0
            
            end = time.time()
            self.compTime.loc[len(self.compTime)] = {'starttime': start, 
                                                    'endtime': end, 
                                                    'phaseDuration':self.nextSignalDuration
                                                } 
           
        elif (((self.signalDuration - duration) > 3 ) and ((self.signalDuration - duration) <= 7)): #change green light to yellow
            #print('We are Setting traffic lights to Yellow for ', self.nextFlows)
            self.TrafficLights(self.nextFlows,'yellow')
        elif (((self.signalDuration - duration) > 0 ) and ((self.signalDuration - duration) <= 3)): #Change traffic lights to RED-CLEARANCE (All-Red) Phase
            #print('Setting traffic lights to Red for ', self.nextFlows)
            self.TrafficLights(self.nextFlows,'red')
        elif (self.signalDuration - duration) <= 0:  #Switch signals to the next signal duration and next recommended speed 
            #print(' elif (self.signalDuration - duration) <= 0')
            self.nextSchedulePerformed = False
            if self.nextSignalDuration == 7 or self.nextFlows is None:
                #print('self.nextSignalDuration == 5: Restarting From Initial')
                #create yellow traffic lights for a random flow
                self.StartFromInitial()
                self.TrafficLights(self.nextFlows,'yellow')
                print('Setting TLS to Yellow for ', self.nextFlows)
            else:
                self.TrafficLights(self.nextFlows,'green')
                print('Setting TLS to Green for ', self.nextFlows)
            
            self.signalDuration = math.floor(self.nextSignalDuration)
            self.recommendedSpeed = self.nextRecommendedSpeed
            self.nextSchedulePerformed = False
            self.tlsPaths = self.nextFlows
            #set traffic lights systems
            #print('TLS Paths Set')
            
            self.startTime = time.time()
            
        elif  self.startTime == 0.0:
            #Just starting system
            print('(Re)Starting Traffic Lights')
            self.StartFromInitial()
        #print('Executing TLSPublisher')
        #print('Remaining: ', self.signalDuration - duration)
        self.trafficLightPub.publish(self.tlsBulbsSettings)
            
        #print('Running TLS Publisher')
        self.TLSPublisher()
        
    def InsertNewRecord(self, msg):
        """
            Insert new traffic data of a given vehicle
        """
        #Delete instance of this vehicle that exist for a different flow
        self.trafficData = self.trafficData[~((self.trafficData['vehicleid'] == msg.vehicleid) & (self.trafficData['approachleg'] != msg.approachleg))]
        
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
        #print('Deleting Veh: ', vehicleid, ' on approach: ', approachleg)
        #Get the vehicle to be deleted and compute the delay in the system
        #tmpTFData = self.trafficData[((self.trafficData['vehicleid'] == vehicleid) & (self.trafficData['approachleg'] == approachleg))]
        
        #Delete the vehicle
        self.trafficData = self.trafficData[~((self.trafficData['vehicleid'] == vehicleid) & (self.trafficData['approachleg'] == approachleg))]
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
        self.recieveTime.loc[len(self.recieveTime)] = {'vehicleid': msg.vehicleid, 
                                                        'recievetime': time.time() 
                                                    }
        idx = None 
        
        #print('VehicleID: ', msg.vehicleid)
        #print('Before: ', self.trafficData)
               
        #check if self.trafficData is not empty
        if len(self.trafficData) > 0: #There is a record in it
            try:
                #try to retrieve the vehicle record nat the current intersection
                idx = self.trafficData[((self.trafficData['vehicleid'] == msg.vehicleid) & (self.trafficData['approachleg'] == msg.approachleg))].index[0]
                
                if msg.distfromstopline > -self.MINSTOPLINEDIST/3 : #vehicle is yet past the intersection, thus, we update its data
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
                    if msg.distfromstopline > -self.MINSTOPLINEDIST/3.0: 
                        self.InsertNewRecord(msg)
                    else:
                        self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
        else: #this is the first record to be inserted  
            if msg.distfromstopline > -self.MINSTOPLINEDIST/3.0:
                self.InsertNewRecord(msg)
            else:
                self.DeleteVehicleFromIntersection(msg.vehicleid, msg.approachleg)
                
        #print('After: ', self.trafficData)
        
def main(args=None):
    rclpy.init(args=args)
    print("Round-Robin Based FIS for Traffic Lights System")
    tls = RoundRobinFISOneCIMLoopTLS()
    rclpy.spin(tls)
    
    tls.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()
