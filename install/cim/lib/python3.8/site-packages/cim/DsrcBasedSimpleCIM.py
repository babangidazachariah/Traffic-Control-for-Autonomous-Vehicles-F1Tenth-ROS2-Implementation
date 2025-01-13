import time
import numpy as np
import scipy.interpolate as interp
import math
import random as rnd

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import Pose, PoseStamped
from visualization_msgs.msg import Marker, MarkerArray
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

#Import DSRC Message Package
from dsrcmsg.msg import DSRCMessage, MySpeed

#Import others
from cim.GeneralFunctions import CIMGeneralFunctions
from cim.ewagent import CIMAutonomousVehicle


class DsrcBasedSimpleCIM(Node):
    """
        This node retrieves location of the vehicle, determines its proximity to a junction, 
        makes decision is the vehcile should continue moving or should stop for other vehicle(s).
        The decision is published as the SPEED of the vehicle. Thus, 
        0 means the vehicle should stop and otherwise, the vehicle should move accordingly.
        
        The other node(s) such as PurePursuit, DisparityExtenderObstacleAvoidance, etc. may use 
        this published speed while controlling the steering.
    """
    def __init__(self):
        super().__init__('DSRCBasedSimpleCIM')
        
        #Create DSRCMessage subscriber
        self.dsrcSubscriber = self.create_subscription(DSRCMessage, '/dsrcmsg', self.ScheduleTraffic,10) # qos_profile=rclpy.qos.qos_profile_system_default)
        #Create MySpeed publisher: topic could be the plate number to ensure it is unique
        self.speedPublisher = self.create_publisher(MySpeed, '/wespeed', 10) # qos_profile=rclpy.qos.qos_profile_system_default)
        
        self.agentPath = 'WE'
        self.vehicleID = 'EW1' #North-South or South-North Number: SN1, SN2, ... NS1, NS2, ... Could be plate Number
        
        self.MINSTOPLINEDIST = 3.0
        self.approachLeg = None
        self.initialTime = None
        self.absDistStopLine = 1000.
        self.speed = 1.0
        
        self.genFuncs = CIMGeneralFunctions()
        self.ewagent = CIMAutonomousVehicle()
    
    def PublishVehicleSpeed(self, speed):
        ##Given an instatiated publisher, publish the desired speed or vehicle
        vehSpeed = MySpeed()
        vehSpeed.vehicleid = vehID
        vehSpeed.speed = speed
        self.speedPublisher.publish(vehSpeed)


    def ScheduleTraffic(self, dsrcmsg):
        """
            Consider waiting vehicles at the current intersection the vehicle seeks to utilize.
            This function assumes that vehicle has arrived at the stop line before this function is executed.
        """
        self.initialTime, self.absDistStopLine, self.approachLeg = self.ewagent.GetParameters()
        print('DSRC-Based: ', dsrcmsg.approachleg, ' :: ', self.approachLeg)
        if dsrcmsg.initialtime is not None  and dsrcmsg.speed is not None and self.initialTime:
            if dsrcmsg.vehicleid != self.vehicleID: #Check to ensure the received DRSC message is not from the vehicle
                #print(dsrcmsg.vehicleid)
                
                if dsrcmsg.approachleg[-2:] == self.approachLeg[-2:] : #Both vehicles are approaching the same intersection
                    
                    if dsrcmsg.initialtime > self.initialTime or dsrcmsg.speed > self.speed : #the other vehicle arrived before or has higher speed than this vehicle
                        #check if this vehicle is at the stop line threshold
                        if (self.absDistStopLine <= 1 or self.absDistStopLine > -1) and dsrcmsg.distfromstopline > -self.MINSTOPLINEDIST:
                            print('West-East Agent at stop line')
                            self.speed = 0.
                    elif self.initialTime > dsrcmsg.initialtime or self.speed > dsrcmsg.speed: # this vehicle arrive first or has higher speed 
                        self.speed = 3.0
                    else: #When vehicle arrived at the same time, we use speed to determine who goes first
                        #increment the initialTime by a random number so that one vehicle may be schedule.
                        self.initialTime += rnd.uniform(0, 1)
            else:
                self.speed = 3.0
                
            if dsrcmsg.distfromstopline < -self.MINSTOPLINEDIST:
                self.speed = 3.0
            self.genFuncs.PublishVehicleSpeed(self.speedPublisher, self.speed)    
            
   

def main(args=None):
    rclpy.init(args=args)
    print("DSRC Simple CIM Node")
    dsrcSimpleCim = DsrcBasedSimpleCIM()
    rclpy.spin(dsrcSimpleCim)
    
    dsrcSimpleCim.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

