import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry

import math
import time
import numpy as np


class LeftWallFollowing(Node):
    
    def __init__(self):
        super().__init__('leftwallfollowing')
        self.publisher = self.create_publisher(AckermannDriveStamped, '/drive', 5)
        self.subscription = self.create_subscription(LaserScan, '/scan', self.scan_callback, 5)
        self.subscription_odom = self.create_subscription(Odometry, 'ego_racecar/odom', self.odom_callback, 5)
        self.safety_threshold = 0.3  # Adjust as needed
        self.speed = None
        self.ranges = None
        
        self.Kp = 10  # Proportional gain
        self.Ki = 0.0  # Integral gain
        self.Kd = 0.09  # Derivative gain
        
        self.errorsum = 0
        self.previous_error = 0
        self.previous_time = 0
        
        self.angle_min = 0
        self.angle_increment = 0
        

    def scan_callback(self, scan_msg):
        
        #time.sleep(1)
        # Extract relevant scan data for processing
        self.ranges = scan_msg.ranges
        self.angle_min = scan_msg.angle_min
        self.angle_increment = scan_msg.angle_increment
        
        #calculate angle_increment
        scan_len= len(scan_msg.ranges)
        ang_min = scan_msg.angle_min
        ang_max = scan_msg.angle_max
        self.angle_increment = (ang_max - ang_min) / (scan_len - 1)
        
        
        #self.get_logger().info('Angle Min: %.2f' % self.angle_min)
        #self.get_logger().info('Angle Incr: %.5f' % self.angle_increment)
        #self.get_logger().info('Angle Max: %.2f' % scan_msg.angle_max)
        #for distance in scan_msg.ranges:
        #    self.get_logger().info('Scan Data: %.2f' % distance)

        # Calculate the lateral distance from the track boundary
        lateral_distance = self.calculate_lateral_distance(self.ranges, self.angle_min, self.angle_increment)
       
            
        #ranges_str = ', '.join([f'{r:.2f}' for r in ranges])
        #self.get_logger().info(f'Scan_Callback Executed: Ranges = {ranges_str}')
        #self.get_logger().info('Scan_Callback Executed: Lateral Distance= "%.2f"'% lateral_distance)
        
        if (lateral_distance < self.safety_threshold):
            # Vehicle is deviating too far from the track, trigger emergency braking
            self.emergency_braking()
            #self.get_logger().info('Scan_Callback Executed: Emergency Break Engaged.')
        else:
            # Vehicle is within the safe lateral distance, resume normal operation
            self.resume_normal_operation()
            #self.get_logger().info('Scan_Callback Executed: Normal Vehicle Running.')

    def calculate_lateral_distance(self, ranges, angle_min, angle_increment):
        # Calculate the index of the closest point to the front of the vehicle
        closest_index = ranges.index(min(ranges))

        # Calculate the angle of the closest point
        closest_angle = angle_min + (closest_index * angle_increment)

        # Calculate the lateral distance by using trigonometry
        lateral_distance = ranges[closest_index] * abs(math.sin(closest_angle))
        return lateral_distance

    def emergency_braking(self):
    
        steer_angle, speed = self.steering()
        # Apply emergency braking by setting speed to zero
        drive_msg = AckermannDriveStamped()
        
        drive_msg.drive.speed = 0.0
        drive_msg.drive.steering_angle = steer_angle
        self.publisher.publish(drive_msg)

    def steering(self):
        
        #Set steering angle to zero: No turning
        steering_angle = 0.0
        speed = 1.0
        
        left_side_angle_range = (math.radians(-90), math.radians(-45))  # Define the angle range for left-side points
        right_side_angle_range = (math.radians(45), math.radians(90))  # Define the angle range for right-side points
        
        # Control Algorithm: Adjust the steering angle based on the TTC
        desired_speed = 1.5  # Modify as needed
        desired_ttc = 10.0  # Modify as needed
        ttc = 5.0
        cur_time = time.time()  # Get the current time
        
        # Select points within the defined left-side angle range
        left_side_points = []
        right_side_points = []
        
        # Calculate angles for each range measurement
        left_angles = [self.angle_min + i * self.angle_increment for i in range(len(self.ranges))]
        right_angles = [self.angle_min + i * self.angle_increment for i in range(len(self.ranges))]
        
        
        #for distance in self.ranges:
        #    self.get_logger().info('Ranges Data: %.2f' % distance)

        #self.get_logger().info('Length of Ranges: %.2f' % len(self.ranges))
        
        # Process angles and distances together
        for angle, distance in zip(left_angles, self.ranges):
        #for angle, distance in self.ranges:
            
            if left_side_angle_range[0] <= angle <= left_side_angle_range[1]:
                left_side_points.append((angle, distance))
                #self.get_logger().info('Left Point Angle: "%.3f"' % angle)
                
        for angle, distance in zip(right_angles, self.ranges):
        #for angle, distance in self.ranges:
            
            if right_side_angle_range[0] <= angle <= right_side_angle_range[1]:
                right_side_points.append((angle, distance))
                #self.get_logger().info('Right Point Angle: "%.3f"' % angle)
        
        #self.get_logger().info('points on right side: "%.2f"' % len(right_side_points))
        #self.get_logger().info('points on left side: "%.2f"' % len(left_side_points))
        
         # Calculate the wall-following command based on left-side points
        if len(left_side_points) > 0:
            # Calculate the average distance of left-side points 
            distance_from_left = np.mean([distance for _, distance in left_side_points])
            distance_from_right = np.mean([distance for _, distance in right_side_points])
            
            distance_from = max(distance_from_right, distance_from_left)
            
            # Apply control action to avoid collision
            safety_distance = desired_speed * ttc
            
            ttc = distance_from / self.speed if (self.speed is not None and distance_from is not None and self.speed != 0) else float('inf')

            # Compute the error as the difference between the average distance and desired distance
            error = distance_from - safety_distance #I can also change average to minimum distance
            self.errorsum += error
            
            if ((ttc < desired_ttc) or (distance_from < desired_ttc)):
                # Proportional control law
                self.get_logger().info('Error: "%.2f"' %error)
                if distance_from_right > distance_from_left:
                    error = -error
                
                
                steering_angle = ((self.Kp * (error)) + (self.Ki * (self.errorsum)) + (self.Kd * ((error - self.previous_error)/(cur_time - self.previous_time)))) 
                #Change speed based on steering_angle
                if(0 < abs(steering_angle) < 10):
                    speed = 1.5
                elif (10 <= abs(steering_angle) < 20):
                    speed = 1.0
                else:
                    speed = 0.7
        
        self.previous_time = cur_time
        self.previous_error = error 
        
        self.get_logger().info('Steering Angle: "%.2f"' %steering_angle)
        self.get_logger().info('Speed: "%.2f"' %speed)
        
        return [steering_angle, speed]
        
        
    def odom_callback(self, odom_msg):
        
        # Extract the speed from the Odometry message
        self.speed = odom_msg.twist.twist.linear.x
        #self.get_logger().info('Odom_Callback Executed: Odometry values retrieved ')

        
    def resume_normal_operation(self):
        
        steer_angle, speed = self.steering()
        # Resume normal operation by setting desired speed and steering angle
        drive_msg = AckermannDriveStamped()
        drive_msg.drive.speed = speed  # Adjust desired speed as needed
        
        drive_msg.drive.steering_angle = steer_angle
            
        self.publisher.publish(drive_msg)

def main(args=None):
    rclpy.init(args=args)
    leftwallfollowing = LeftWallFollowing()
    rclpy.spin(leftwallfollowing)
    leftwallfollowing.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
