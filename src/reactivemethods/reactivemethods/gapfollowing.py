import rclpy
from rclpy.node import Node

import numpy as np

from sensor_msgs.msg import LaserScan

from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive

class GapFollow(Node):
    """ 
    Implement an optimzed Safety Gap Following on the car
    This is just a template, you are free to implement your own node!
    """
    def __init__(self): 
        """" Initialize the topics, publishers and subscribers
        """
        super().__init__("gapfollow")
        self.radPerElem = 0;
        laserScanTopic = "/scan"
        driveTopic = "/drive"
        self.laserScanSubs = self.create_subscription(
                            LaserScan,
                            laserScanTopic,
                            self.LaserScanCallback,
                            10
                        )
                        
        self.drivePubs = self.create_publisher(
                            AckermannDriveStamped,
                            driveTopic,
                            10
                        )
                        
     
    def PlaceSafetyBubble(self, scan):
        """"
        "This function places a safety bubble on scan for all values less than or equal 1
        "The neighbours of the point/element in scan where safety bubble is placed are all converted to zero (0)
        "It returns the bubbled lidar scan made of zeros (0's) and non-zero elements (free-spaces)
        """
        #print(scan)
        #scan[np.where(scan <= 1)] = 0 # Update the elements that are less than 1.1 to zero(0)
        #bubIndices = np.where(scan < 1) # Retrieve elements of scans where safety buble is being placed.
        #print(bubIndices)
        #convert neighbouring elements of safety bubble to zero too
        
        
        for i in range(0, len(scan)):
            if scan[i] <= 0.9:
                #Set value at i to zero
                scan[i] = 0
                
                #set five (5) neighbouring values to zero too
                for j in range(1, 21):
                    if ((i - j) >= 0):
                        scan[i - j] = 0
                        
                    if((i + j) < (len(scan)-1)):
                        scan[i+j] = 0
                
        return scan
        
    def GetLargestGap(self, bubScan):
        """"
        "This function receive a lidar scan, which safety bubble has been placed and its neighbours processed accordingly: See PlaceSafetyBubble(scan)
        "It returns the start and end indices of the longest free-space (non-zero lidar scan)
        """
        """
        maxGapStart = 0
        
        maxGapEnd = 0
        maxGapLength = 0
        currentGapStart = None
        currentGapLength = 0
        
        for i, sc in enumerate(bubScan):
            if sc > 0:
                if currentGapStart is None:
                    currentGapStart = i
                currentGapLength += 1
            else:
                if currentGapLength > maxGapLength:
                    maxGapStart = currentGapStart
                    maxGapEnd = i - 1
                    maxGapLength = currentGapLength
                currentGapStart = None
                currentGapLength = 0
        return maxGapStart, maxGapEnd
        """
        maxGapEnd = 0
        maxGapStart = 0
        maxLen = 0
        #Mask bubbles
        maskedBubScan = np.ma.masked_where(bubScan == 0, bubScan)
        
        #retrieve slices of unmasked elements
        slices = np.ma.notmasked_contiguous(maskedBubScan)
        if len(slices) > 0:
            #Get max gap
            maxLen = slices[0].stop - slices[0].start
            curSlice = slices[0]
            
            for sl in slices[1:]:
                slLen = sl.stop - sl.start
                if slLen > maxLen:
                    maxLen = slLen
                    curSlice = sl
            maxGapStart = curSlice.start
            maxGapEnd = curSlice.stop
            
        return maxGapStart, maxGapEnd


    def FindBestPoint(self, startI, endI, ranges):
        """Start_i & end_i are start and end indices of the max-gap range, respectively
        Return index of best point in ranges
        Naive: Choose the furthest point within ranges and go there
        """
        bestPoint = startI
        maxRange = 0.0
        
        for i in range(startI, endI ):
            if ranges[i] > maxRange:
                maxRange = ranges[i]
                bestPoint = i
        
        return bestPoint   

        
    def LaserScanCallback(self, data):
        #receive and convert lidar scan data into numpy array
        
        self.radPerElem = (2 * np.pi) / len(data.ranges)
        
        #use only lidar scan between 135 and -135
        lidarScan = np.array(data.ranges[135:-135])
        #print(len(lidarScan))
        bubLidarScan = self.PlaceSafetyBubble(lidarScan)
        #print(bubLidarScan)
        #Get largest Gap Start and End indices
        mxGStart, mxGEnd = self.GetLargestGap(bubLidarScan)
        
        #Get best point to steer vehicle to
        bestPoint = self.FindBestPoint(mxGStart, mxGEnd, bubLidarScan)
        
        #Calculate the steering angle
        steeringAngle = 0.0
        stBestPoint = mxGStart + bestPoint
        if (mxGStart >= 0) and (mxGStart < mxGEnd):
            if stBestPoint < (len(lidarScan)/2):
                #steeringAngle = - data.angle_increment * ((len(lidarScan)/2) - stBestPoint)
                steeringAngle = - self.radPerElem * ((len(lidarScan)/2) - ((mxGStart + mxGEnd)/2))
                
            else:
                #steeringAngle = data.angle_increment * ((len(lidarScan)/2) - stBestPoint)
                steeringAngle = self.radPerElem * ((len(lidarScan)/2) - ((mxGStart + mxGEnd)/2))
        
        steeringAngle = self.radPerElem * ((len(lidarScan)/2) - stBestPoint)    
        steeringAngle /= 2.0
        
        print("mxGapStart: ", mxGStart)
        print("mxGapEnd: ", mxGEnd)
        print("Steering Angle: ", steeringAngle)
        #Prepare parameters for driving the vehicle
        driveMsg = AckermannDriveStamped()
        driveMsg.header = data.header
        driveMsg.drive.steering_angle = steeringAngle
        driveMsg.drive.speed = 0.5
        self.drivePubs.publish(driveMsg)

def main(args=None):
    rclpy.init(args=args)
    print("Gap Following Algorithm")
    gapFollowNode = GapFollow()
    rclpy.spin(gapFollowNode)
    
    gapFollowNode.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()
