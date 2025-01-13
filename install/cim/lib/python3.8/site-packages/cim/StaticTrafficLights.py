import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray

import pandas as pd
import time
import math

#Import DSRC Message Package
from dsrcmsg.msg import TrafficLightsMessage

class StaticTrafficController(Node):
    """
        
    """
    def __init__(self):
        super().__init__('StaticTrafficController')
        self.trafficLightPub = self.create_publisher(MarkerArray, '/tlsbulbs', 10)
        self.timer = self.create_timer(0.1, self.SwitchTrafficSignal) 
        self.startTime = 0.0
        self.switch = False
        self.idx = None
        self.signalDuration = 25.0
        self.tlsPub = self.create_publisher(TrafficLightsMessage, '/tls', 10)
        self.tlsBulbsSettings = None
        self.tlsmsgIdx = 0 #Used for debugging synchronization between tls and agent
    
    def TLSPublisher(self):
        print('self.tlsmsgIdx: ', self.tlsmsgIdx)
        tlsmsg = TrafficLightsMessage()
        tlsmsg.pathids = self.tlsPaths
        tlsmsg.starttime = self.startTime
        tlsmsg.duration = self.signalDuration
        
        print('Green Flow: ', self.tlsPaths, ' StartTime: ', self.startTime, ' Duration: ', self.signalDuration)
        self.tlsPub.publish(tlsmsg)
        self.tlsmsgIdx += 1
        
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
        #self.tlsPaths = appLeg #Path to be assigned green wave
        
        if 'NSJ' in appLeg or 'SNJ' in appLeg:
            greenPoints = [(4.0, -0.85), (14.7, -0.85), (15.7, 6), (4.95, 6)]
            redPoints = [(4.5,6.5),  (4.5, -0.25), (15.3, -1.25), (15.3, 5.55)]
            scheFlows = ['SNJ1', 'SNJ2', 'NSJ3', 'NSJ4']
            self.switch = False
            for point in greenPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NSJ', (0.0, 1.0, 0.0)))
            for point in redPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WEJ', (1.0, 0.0, 0.0)))
        elif 'WEJ' in appLeg or 'EWJ' in appLeg:
            redPoints = [(4.0, -0.85), (14.7, -0.85), (15.7, 6), (4.95, 6)]
            greenPoints = [(4.5,6.5),  (4.5, -0.25), (15.3, -1.25), (15.3, 5.55)]
            scheFlows = ['WEJ1', 'EWJ2', 'EWJ3', 'WEJ4']
            self.switch = True
            for point in greenPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'WEJ', (0.0, 1.0, 0.0)))
            for point in redPoints:
                marker_array.markers.append(self.CreateTrafficLightBulb(point, 'NSJ', (1.0, 0.0, 0.0)))
        self.tlsPaths = scheFlows
        self.tlsBulbsSettings = marker_array
        

    def SwitchTrafficSignal(self):
        
        if self.startTime == 0.0:
            self.TrafficLights(appLeg = 'NSJ')
            self.startTime = time.time()
            
        duration = time.time() - self.startTime 
        if not self.switch and duration >= self.signalDuration :
            self.TrafficLights(appLeg = 'WEJ')
            
            self.startTime = time.time()
            #print('WEJ', duration)
        elif self.switch and duration >= self.signalDuration :
            
            self.TrafficLights(appLeg = 'NSJ')
            self.startTime = time.time() 
            #print('NSJ', duration)
        self.TLSPublisher()
        self.trafficLightPub.publish(self.tlsBulbsSettings)
        
def main(args=None):
    rclpy.init(args=args)
    print("Traffic Lights System Node")
    tls = StaticTrafficController()
    rclpy.spin(tls)
    
    tls.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()
