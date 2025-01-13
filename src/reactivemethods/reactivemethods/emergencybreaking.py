import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive

import numpy as np

class EmergencyBreaking(Node):
    def __init__(self):
        super().__init__('emergency_breaking')
        scanTopic = "/scan"
        driveTopic = "/drive"
        
        #subcribe to lidar laser scan topic
        self.lidarScan  = self.create_subscription(
                                LaserScan,
                                scanTopic,
                                self.LidarScanCallBack,
                                10
                            )
                            
        #create publisher
        self.drivePubs = self.create_publisher(
                                AckermannDriveStamped,
                                driveTopic,
                                10
                            )
                                
                                

    def LidarScanCallBack(self, data):
        #Initialize variables
        speed = 1.0 #speed of the vehicle
        
        
        #receive lidar scan data (ranges) and convert to array
        scan = np.array(data.ranges)
        """
        f = open("scan.txt", "a")
        for i in range(0, 1080):
            f.write(np.array2string(scan[i]) + "  ")
        f.write("================================Sub Scan=================================")
        f.close()
        """
        #Take a subset of the lidar signals for decision making:
        #Take the subset between 135 and -135 degrees: That is, 90 degrees field of view in from of the vehicle
        subScan = scan[135:-135]
        #print(scan)
        """
        f = open("subscan.txt", "a")
        for i in range(0,810):
            f.write(np.array2string(subScan[i]) + "  ")
        f.write("================================Sub Scan=================================")
        f.close()
        """
        #print("================================Sub Scan=================================")
        #print(subScan)
        obsSubScan = np.where(subScan <= 0.5, True, False)
        #print(obsSubScan)
        if np.any(obsSubScan): #if there is any lidar ray that is less than or equal to 1, it implies an obstancle, thus we break 
            speed = 0.0
        
        
        #print(obsSubScan)
        driveMsg = AckermannDriveStamped() #drive command variable 
        driveMsg.header = data.header
        driveMsg.drive.speed = speed
        self.drivePubs.publish(driveMsg)
        
def main(args=None):
    #initialize the rclpy
    rclpy.init(args=args)
    
    #create instance of the node
    emgcBreak = EmergencyBreaking()
    print("EmergencyBreaking Node Initialized and Starting")
    rclpy.spin(emgcBreak)
    
    emgcBreak.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
