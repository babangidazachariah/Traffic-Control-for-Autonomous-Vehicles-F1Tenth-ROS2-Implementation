import rclpy
from rclpy.node import Node

import numpy as np
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive

class ReactiveFollowGap(Node):
    """ 
    Implement Wall Following on the car
    This is just a template, you are free to implement your own node!
    """
    def __init__(self):
        super().__init__('reactive_node')
        # Topics & Subs, Pubs
        lidarscan_topic = '/scan'
        drive_topic = '/drive'

        # Subscribe to LIDAR
        self.lidar_sub = self.create_subscription(
            LaserScan,
            lidarscan_topic,
            self.lidar_callback,
            10
        )
        
        # Publish to drive
        self.drive_pub = self.create_publisher(
            AckermannDriveStamped,
            drive_topic,
            10
        )

    def preprocess_lidar(self, ranges):
        """ Preprocess the LiDAR scan array. Expert implementation includes:
            1.Setting each value to the mean over some window
            2.Rejecting high values (eg. > 3m)
        """
        proc_ranges = np.array(ranges)
        # Set each value to the mean over some window (e.g., 5)
        window_size = 10
        proc_ranges = np.convolve(proc_ranges, np.ones(window_size)/window_size, mode='same')
        # Reject high values (> 3m)
        proc_ranges[proc_ranges > 3.0] = 0.0
        return proc_ranges.tolist()

    def find_max_gap(self, free_space_ranges):
        """ Return the start index & end index of the max gap in free_space_ranges
        """
        max_gap_start = 0
        max_gap_end = 0
        max_gap_length = 0
        current_gap_start = None
        current_gap_length = 0
        
        for i, r in enumerate(free_space_ranges):
            if r > 0:
                if current_gap_start is None:
                    current_gap_start = i
                current_gap_length += 1
            else:
                if current_gap_length > max_gap_length:
                    max_gap_start = current_gap_start
                    max_gap_end = i - 1
                    max_gap_length = current_gap_length
                current_gap_start = None
                current_gap_length = 0
        
        return max_gap_start, max_gap_end

    def find_best_point(self, start_i, end_i, ranges):
        """Start_i & end_i are start and end indices of the max-gap range, respectively
        Return index of best point in ranges
        Naive: Choose the furthest point within ranges and go there
        """
        best_point_index = start_i
        max_range = 0.0
        
        for i in range(start_i, end_i + 1):
            if ranges[i] > max_range:
                max_range = ranges[i]
                best_point_index = i
        
        return best_point_index

    def lidar_callback(self, data):
        """ Process each LiDAR scan as per the Follow Gap algorithm & publish an AckermannDriveStamped Message
        """
        ranges = data.ranges
        print('size of ranges: ',len(ranges))
        proc_ranges = self.preprocess_lidar(ranges)
        
        print('Min Angle: ',data.angle_min)
        angle_increment = data.angle_increment
        print('Angle Inc: ',data.angle_increment)
        print('Max Angle: ',data.angle_max)
        
        # Find closest point to LiDAR
        closest_point_index = np.argmin(proc_ranges)
        
        # Convert proc_ranges to a NumPy array
        proc_ranges = np.array(proc_ranges)
        print('Proc Ranges: ',ranges)
        
        # Eliminate all points inside 'bubble' (set them to zero)
        bubble_radius = 0.25  # Example value, adjust as needed
        bubble_indices = np.abs(np.arange(len(proc_ranges)) - closest_point_index) < bubble_radius / data.angle_increment
        indices_to_zero = np.where(bubble_indices)[0]
        proc_ranges[indices_to_zero] = 0.0
        
        # Find max length gap
        max_gap_start, max_gap_end = self.find_max_gap(proc_ranges)
        print('max_gap_start: ',max_gap_start,' max_gap_end: ', max_gap_end)
        # Find the best point in the gap
        best_point_index = self.find_best_point(max_gap_start, max_gap_end, proc_ranges)
        print('best_point_index: ',best_point_index)
        # Calculate steering angle based on the best point index
        steering_angle = (best_point_index - len(proc_ranges) / 2) * data.angle_increment
        #print('steering_angle: ', steering_angle)
        self.get_logger().info('steering_angle: "%.2f"' % steering_angle)
        self.get_logger().info('best_point_index: "%.2f"' % best_point_index)
        # Publish Drive message
        drive_msg = AckermannDriveStamped()
        drive_msg.header = data.header
        drive_msg.drive.steering_angle = steering_angle
        drive_msg.drive.speed = proc_ranges[best_point_index]  # Example speed, adjust as needed
        self.drive_pub.publish(drive_msg)


def main(args=None):
    rclpy.init(args=args)
    print("WallFollow Initialized")
    reactive_node = ReactiveFollowGap()
    rclpy.spin(reactive_node)

    reactive_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
