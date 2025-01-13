
import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray

import pandas as pd
import time

#Import Traffic Record Action Package
from trafficrecord.action import VehWaitTime

from rclpy.action import ActionServer

class TrafficRecordingAnalysis(Node):
    """
        This ros2 Action Server for Traffic Information Recording receives goals from action clients (vehicles),
        records the info and then perform basic analysis at the end of the set simulation time.
    """
    def __init__(self):
        super().__init__('trafficanalysis')
        self._action_server = ActionServer(
            self,
            VehWaitTime,
            'vehwaittime',
            self.RecordWaitingTimeData)
        self.waitingTimeData = pd.DataFrame(data={}, columns=['approachLeg', 'waitTime'])
        self.timer = self.create_timer(1, self.EndTrafficAnalysis) 
        self.startTime = time.time()
        
    def RecordWaitingTimeData(self,vehTrafficRec):
        #if new approach leg, append the leg to Traffic Data
        appleg = vehTrafficRec.request.approachleg
        waitTime = vehTrafficRec.request.waittime
        print(appleg)
        #if appleg not in self.waitingTimeData['approachLeg'].values:
        self.waitingTimeData.loc[len(self.waitingTimeData)] = {'approachLeg': appleg, 'waitTime': waitTime}

        
        
        #self.waitingTimeData.loc[self.waitingTimeData['approachLeg'] == appleg, 'waitTime'] = waitTime
        print('Approach Leg', appleg, ' wait time: ', waitTime)
        
        vehTrafficRec.succeed()
        result = VehWaitTime.Result()
        result.recorded = True
        return result
            
    def EndTrafficAnalysis(self):
        diff = time.time() - self.startTime 
        print('EndTrafficAnalysis:', diff)
        
        #60s * numMinutes
        if diff >= 900: #60 * 15 min = 900 seconds
            #Compute network and junction-based avarage waiting times
            allAveWaitTime = self.waitingTimeData['waitTime'].mean()
            j1AveWaitTime = self.waitingTimeData[self.waitingTimeData['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
            j2AveWaitTime = self.waitingTimeData[self.waitingTimeData['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
            j3AveWaitTime = self.waitingTimeData[self.waitingTimeData['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
            j4AveWaitTime = self.waitingTimeData[self.waitingTimeData['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()
            
            print('J1Ave: ', j1AveWaitTime)
            print('J2Ave: ', j2AveWaitTime)
            print('J3Av: ', j3AveWaitTime)
            print('J4Ave: ', j4AveWaitTime)
            print('NetAve: ', allAveWaitTime)
            
            name = 'trafficInfo' + str(time.time()) + '.csv'
            
            path = self.waitingTimeData.to_csv(name)
            
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

