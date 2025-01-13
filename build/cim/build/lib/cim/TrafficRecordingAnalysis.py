
import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray

import pandas as pd
import time

#Import DSRC Message Package
from dsrcmsg.msg import DSRCMessage

class TrafficRecordingAnalysis(Node):
    """
        Node that listens on dsrcmsg messages to compute waiting at intersections.
        Waiting time of a vehicle at an intersection is computed as the difference between
        dsrcmsg.initialtime and dsrcmsg.currenttime or time.time() when the 
        dsrcmsg.distfromstopline is less than -1 (negative 1).
    """
    def __init__(self):
        super().__init__('trafficanalysis')
        self.dsrcmsSub = self.create_subscription(DSRCMessage, '/dsrcmsg', self.RecordTrafficData, 10)
        self.trafficData = pd.DataFrame(data={}, columns=['approachLeg', 'waitTime'])
        self.timer = self.create_timer(1, self.EndTrafficAnalysis) 
        self.startTime = time.time()
        
    def RecordTrafficData(self,dsrcmsg):
        #if new approach leg, append the leg to Traffic Data
        if dsrcmsg.approachleg not in self.trafficData['approachLeg'].values:
            #self.trafficData.append({'approachLeg': dsrcmsg.approachleg, 'waitTime': 0.0}, ignore_index=True)
            self.trafficData.loc[len(self.trafficData)] = {'approachLeg': dsrcmsg.approachleg, 'waitTime': 0.0}

            
        #if approach leg already exist and dsrcmsg.distfromstopline is less than 1 then record the waiting time for the vehicle
        if dsrcmsg.distfromstopline < -0.9 and dsrcmsg.distfromstopline > -1.0:
            waitTime = dsrcmsg.currenttime - dsrcmsg.initialtime
            self.trafficData.loc[self.trafficData['approachLeg'] == dsrcmsg.approachleg, 'waitTime'] += waitTime
            print(dsrcmsg.vehicleid, ' wait time: ', waitTime)
            
    def EndTrafficAnalysis(self):
        diff = time.time() - self.startTime 
        print('EndTrafficAnalysis:', diff)
        
        #60s * numMinutes
        if diff >= 1800: #60 * 15 min = 900 seconds
            #Compute network and junction-based avarage waiting times
            allAveWaitTime = self.trafficData['waitTime'].mean()
            j1AveWaitTime = self.trafficData[self.trafficData['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
            j2AveWaitTime = self.trafficData[self.trafficData['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
            j3AveWaitTime = self.trafficData[self.trafficData['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
            j4AveWaitTime = self.trafficData[self.trafficData['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()
            print('NetAve: ', allAveWaitTime)
            print('J1Ave: ', j1AveWaitTime)
            print('J2Ave: ', j2AveWaitTime)
            print('J3Av: ', j3AveWaitTime)
            print('J4Ave: ', j4AveWaitTime)
            
            rclpy.shutdown()
            

def main(args=None):
    rclpy.init(args=args)
    print("Traffic Recording and Analysis Node")
    traffRecAnalysis = TrafficRecordingAnalysis()
    rclpy.spin(traffRecAnalysis)
    
    traffRecAnalysis.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

