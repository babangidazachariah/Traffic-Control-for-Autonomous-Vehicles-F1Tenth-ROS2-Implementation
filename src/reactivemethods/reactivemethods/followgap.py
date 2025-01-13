###https://github.com/f1tenth/ESweek2021_educationclassA3/blob/main/01_Follow_The_Gap/drivers.py
import numpy as np

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan

from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive


class GapFollower(Node):
    BUBBLE_RADIUS = 160  # in cm
    PREPROCESS_CONV_SIZE = 3
    BEST_POINT_CONV_SIZE = 80
    MAX_LIDAR_DIST = 3000000    # =3m
    STRAIGHTS_SPEED =2.0
    CORNERS_SPEED = 0.60
    STRAIGHTS_STEERING_ANGLE = np.pi / 18  # 10 degrees

    def __init__(self):
        """" Initialize the topics, publishers and subscribers
        """
        super().__init__("gapfollow")
        lidarScanTopic = "/scan"
        driveTopic = "/drive"
        self.lidarScanSubs = self.create_subscription(
                            LaserScan,
                            lidarScanTopic,
                            self.LidarScanCallback,
                            10
                        )
                        
        self.drivePubs = self.create_publisher(
                            AckermannDriveStamped,
                            driveTopic,
                            10
                        )
                        
        # used when calculating the angles of the LiDAR data
        self.radians_per_elem = None

    def preprocess_lidar(self, ranges):
        """ Preprocess the LiDAR scan array. Expert implementation includes:
            1.Setting each value to the mean over some window
            2.Rejecting high values (eg. > 3m)
        """
        ranges = np.array(ranges)
        self.radians_per_elem = (2 * np.pi) / len(ranges)
        # we won't use the LiDAR data from directly behind us
        proc_ranges = ranges[135:-135]
        # sets each value to the mean over a given window
        proc_ranges = np.convolve(proc_ranges, np.ones(self.PREPROCESS_CONV_SIZE), 'same') / self.PREPROCESS_CONV_SIZE
        proc_ranges = np.clip(proc_ranges, 0, self.MAX_LIDAR_DIST)
        
        #print("135--135: ", len(proc_ranges))
        
        return proc_ranges

    def find_max_gap(self, free_space_ranges):
        """ Return the start index & end index of the max gap in free_space_ranges
            free_space_ranges: list of LiDAR data which contains a 'bubble' of zeros
        """
        print(len(free_space_ranges))
        
        # mask the bubble
        masked = np.ma.masked_where(free_space_ranges == 0, free_space_ranges)
        # get a slice for each contigous sequence of non-bubble data
        slices = np.ma.notmasked_contiguous(masked)
        max_len = slices[0].stop - slices[0].start
        chosen_slice = slices[0]
        # I think we will only ever have a maximum of 2 slices but will handle an
        # indefinitely sized list for portablility
        for sl in slices[1:]:
            sl_len = sl.stop - sl.start
            if sl_len > max_len:
                max_len = sl_len
                chosen_slice = sl
        return chosen_slice.start, chosen_slice.stop

    def find_best_point(self, start_i, end_i, ranges):
        """Start_i & end_i are start and end indices of max-gap range, respectively
        Return index of best point in ranges
        Naive: Choose the furthest point within ranges and go there
        """
        # do a sliding window average over the data in the max gap, this will
        # help the car to avoid hitting corners
        averaged_max_gap = np.convolve(ranges[start_i:end_i], np.ones(self.BEST_POINT_CONV_SIZE),
                                       'same') / self.BEST_POINT_CONV_SIZE
        return averaged_max_gap.argmax() + start_i

    def get_angle(self, range_index, range_len):
        """ Get the angle of a particular element in the LiDAR data and transform it into an appropriate steering angle
        """
        print(range_len)
        lidar_angle = (range_index - (range_len / 2)) * self.radians_per_elem
        steering_angle = lidar_angle / 2
        return steering_angle

    def LidarScanCallback(self, data):

        """
        This is the main function that is getting called from the simulation
        Process each LiDAR scan as per the Follow Gap algorithm & publish an AckermannDriveStamped Message
        """
        # Preprocess the Lidar Information
        print(len(data.ranges))
        proc_ranges = self.preprocess_lidar(data.ranges)
        # Find closest point to LiDAR
        closest = proc_ranges.argmin()

        # Eliminate all points inside 'bubble' (set them to zero)
        min_index = closest - self.BUBBLE_RADIUS
        max_index = closest + self.BUBBLE_RADIUS
        if min_index < 0: min_index = 0
        if max_index >= len(proc_ranges): max_index = len(proc_ranges) - 1
        proc_ranges[min_index:max_index] = 0

        # Find max length gap
        gap_start, gap_end = self.find_max_gap(proc_ranges)

        # Find the best point in the gap
        best = self.find_best_point(gap_start, gap_end, proc_ranges)

        # Get the final steering angle and speed value
        steering_angle = self.get_angle(best, len(proc_ranges))
        if abs(steering_angle) > self.STRAIGHTS_STEERING_ANGLE:
            speed = self.CORNERS_SPEED
        else:
            speed = self.STRAIGHTS_SPEED

        # Send back the speed and steering angle to the simulation
        #return speed, steering_angle
        #Prepare parameters for driving the vehicle
        driveMsg = AckermannDriveStamped()
        driveMsg.header = data.header
        driveMsg.drive.steering_angle = steering_angle
        driveMsg.drive.speed = speed
        self.drivePubs.publish(driveMsg)

def main(args=None):
    rclpy.init(args=args)
    print("Gap Following Algorithm")
    gapFollowNode = GapFollower()
    rclpy.spin(gapFollowNode)
    
    gapFollowNode.destroy_node()
    rclpy.shutdown()
    
if __name__ == "main":
    main()

