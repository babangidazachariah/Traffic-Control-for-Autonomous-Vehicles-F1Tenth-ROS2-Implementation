
import time
import yaml
#import gym
import numpy as np
from argparse import Namespace
from numba import njit
from pyglet.gl import GL_POINTS

import math
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import Pose, PoseStamped
from visualization_msgs.msg import Marker, MarkerArray
import tf2_ros
import csv

#Import DSRC Message Package
from dsrcmsg.msg import DSRCMessage

from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener



import traceback
"""
Planner Helpers
"""

    
    
@njit(fastmath=False, cache=True)
def nearest_point_on_trajectory(point, trajectory):
    """
    Return the nearest point along the given piecewise linear trajectory.
    Same as nearest_point_on_line_segment, but vectorized. This method is quite fast, time constraints should
    not be an issue so long as trajectories are not insanely long.
        Order of magnitude: trajectory length: 1000 --> 0.0002 second computation (5000fps)
    point: size 2 numpy array
    trajectory: Nx2 matrix of (x,y) trajectory waypoints
        - these must be unique. If they are not unique, a divide by 0 error will destroy the world
    """
    diffs = trajectory[1:, :] - trajectory[:-1, :]
    l2s = diffs[:, 0] ** 2 + diffs[:, 1] ** 2
    # this is equivalent to the elementwise dot product
    # dots = np.sum((point - trajectory[:-1,:]) * diffs[:,:], axis=1)
    dots = np.empty((trajectory.shape[0] - 1,))
    for i in range(dots.shape[0]):
        dots[i] = np.dot((point - trajectory[i, :]), diffs[i, :])
    t = dots / l2s
    t[t < 0.0] = 0.0
    t[t > 1.0] = 1.0
    # t = np.clip(dots / l2s, 0.0, 1.0)
    projections = trajectory[:-1, :] + (t * diffs.T).T
    # dists = np.linalg.norm(point - projections, axis=1)
    dists = np.empty((projections.shape[0],))
    for i in range(dists.shape[0]):
        temp = point - projections[i]
        dists[i] = np.sqrt(np.sum(temp * temp))
    min_dist_segment = np.argmin(dists)
    return projections[min_dist_segment], dists[min_dist_segment], t[min_dist_segment], min_dist_segment


@njit(fastmath=False, cache=True)
def first_point_on_trajectory_intersecting_circle(point, radius, trajectory, t=0.0, wrap=False):
    """
    starts at beginning of trajectory, and find the first point one radius away from the given point along the trajectory.
    Assumes that the first segment passes within a single radius of the point
    http://codereview.stackexchange.com/questions/86421/line-segment-to-circle-collision-algorithm
    """
    start_i = int(t)
    start_t = t % 1.0
    first_t = None
    first_i = None
    first_p = None
    trajectory = np.ascontiguousarray(trajectory)
    for i in range(start_i, trajectory.shape[0] - 1):
        start = trajectory[i, :]
        end = trajectory[i + 1, :] + 1e-6
        V = np.ascontiguousarray(end - start)

        a = np.dot(V, V)
        b = 2.0 * np.dot(V, start - point)
        c = np.dot(start, start) + np.dot(point, point) - 2.0 * np.dot(start, point) - radius * radius
        discriminant = b * b - 4 * a * c

        if discriminant < 0:
            continue
        #   print "NO INTERSECTION"
        # else:
        # if discriminant >= 0.0:
        discriminant = np.sqrt(discriminant)
        t1 = (-b - discriminant) / (2.0 * a)
        t2 = (-b + discriminant) / (2.0 * a)
        if i == start_i:
            if t1 >= 0.0 and t1 <= 1.0 and t1 >= start_t:
                first_t = t1
                first_i = i
                first_p = start + t1 * V
                break
            if t2 >= 0.0 and t2 <= 1.0 and t2 >= start_t:
                first_t = t2
                first_i = i
                first_p = start + t2 * V
                break
        elif t1 >= 0.0 and t1 <= 1.0:
            first_t = t1
            first_i = i
            first_p = start + t1 * V
            break
        elif t2 >= 0.0 and t2 <= 1.0:
            first_t = t2
            first_i = i
            first_p = start + t2 * V
            break
    # wrap around to the beginning of the trajectory if no intersection is found1
    if wrap and first_p is None:
        for i in range(-1, start_i):
            start = trajectory[i % trajectory.shape[0], :]
            end = trajectory[(i + 1) % trajectory.shape[0], :] + 1e-6
            V = end - start

            a = np.dot(V, V)
            b = 2.0 * np.dot(V, start - point)
            c = np.dot(start, start) + np.dot(point, point) - 2.0 * np.dot(start, point) - radius * radius
            discriminant = b * b - 4 * a * c

            if discriminant < 0:
                continue
            discriminant = np.sqrt(discriminant)
            t1 = (-b - discriminant) / (2.0 * a)
            t2 = (-b + discriminant) / (2.0 * a)
            if t1 >= 0.0 and t1 <= 1.0:
                first_t = t1
                first_i = i
                first_p = start + t1 * V
                break
            elif t2 >= 0.0 and t2 <= 1.0:
                first_t = t2
                first_i = i
                first_p = start + t2 * V
                break

    return first_p, first_i, first_t


@njit(fastmath=False, cache=True)
def get_actuation(pose_theta, lookahead_point, position, lookahead_distance, wheelbase):
    """
    Returns actuation
    """
    # Extract the Waypoint information
    #print('pos: ',position)
    ref_point = lookahead_point[0:2] - position
    #print('Ref Point: ',ref_point)
    waypoint_y = np.dot(np.array([np.sin(-pose_theta), np.cos(-pose_theta)]), ref_point)
    speed = lookahead_point[2]
    if np.abs(waypoint_y) < 1e-6:
        return speed, 0.
    # Define the radius of the arc to follow
    radius = 1 / (2.0 * waypoint_y / lookahead_distance ** 2)

    # Calculate the steering angle based on the curvature of the arc to follow
    steering_angle = np.arctan(wheelbase / radius)

    return speed, steering_angle


class PurePursuitPlanner(Node):
    """
    Example Planner
    """

    def __init__(self, waypointFile, waypointPathTopic, nextPointTopic):
        super().__init__('pure_pursuit')
        self.wheelbase = 0.3302
        
        self.drawn_waypoints = []
        
                        
        self.path_pub = self.create_publisher(MarkerArray, waypointPathTopic, 10)
        self.waypoints = None 
        #'/home/babangida/ros_ws/northsouth2d.csv'   nsouthopttrajwptsconstvelocity   nsouthopttrajwpts
        #'/home/babangida/ros_ws/src/reactivemethods/Spielberg_raceline.csv'  
        #'/home/babangida/ros_ws/src/reactivemethods/Spielberg_centerline.csv'
        #'/home/babangida/ros_ws/src/reactivemethods/nsouthopttrajwptsconstvelocity.csv'
        self.load_waypoints(waypointFile)
        self.max_reacquire = 20.
        
        #Create DSRCMessage publisher
        self.dsrcPublisher = self.create_publisher(DSRCMessage, '/dsrcmsg', 10)
        self.initTime = None
        
        #self.timer = self.create_timer(0.1, self.timer_callback) 
        self.publish_path()
        

                        
    def process_lidar(self, data):
        pass
        
        
        
    def load_waypoints(self, path):
        """
        loads waypoints
        """
        self.waypoints = np.loadtxt(path, delimiter=';', skiprows=3) #Original line 
        self.publish_path()
        #print('published Waypoints')
        
        
                
    def publish_path(self):
        marker_array = MarkerArray()
       
        # Add markers to the MarkerArray
        
        for i in range(len(self.waypoints)):
            x = self.waypoints[i,1]
            y = self.waypoints[i,2]
            
            
            marker = Marker()
            marker.header.frame_id = 'map'
            marker.id = i
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            marker.pose.position.x = x
            marker.pose.position.y = y
            marker.pose.position.z = 0.0
            marker.scale.x = 0.1
            marker.scale.y = 0.1
            marker.scale.z = 0.1
            marker.color.a = 1.0
            marker.color.r = 0.0 
            marker.color.g = 1.0 
            marker.color.b = 0.0
            
            marker_array.markers.append(marker)
            
            #print("x: ", x , " y: ", y )

        self.path_pub.publish(marker_array)   

    def _get_current_waypoint(self, waypoints, lookahead_distance, position, theta):
        """
        gets the current waypoint to follow
        """
        wpts = np.vstack((self.waypoints[:, 1], self.waypoints[:, 2])).T
        nearest_point, nearest_dist, t, i = nearest_point_on_trajectory(position, wpts)
        if nearest_dist < lookahead_distance:
            lookahead_point, i2, t2 = first_point_on_trajectory_intersecting_circle(position, lookahead_distance, wpts,
                                                                                    i + t, wrap=True)
            if i2 == None:
                return None
            current_waypoint = np.empty((3,))
            # x, y
            current_waypoint[0:2] = wpts[i2, :]
            # speed
            current_waypoint[2] = waypoints[i, 5]
            return current_waypoint
        elif nearest_dist < self.max_reacquire:
            #print(i)
            return np.append(wpts[i, :], waypoints[i, 5])
        else:
            return None

    def transform_to_pose(self, transform):
        # Create a Pose object
        pose = Pose()
        # Copy the translation and rotation fields from the Transform object
        pose.position = transform.translation
        pose.orientation = transform.rotation
        # Return the Pose object
        return pose
        
        
    def pose_to_theta(self, pose):
        # Convert the quaternion to Euler angles
        x = pose.orientation.x
        y = pose.orientation.y
        z = pose.orientation.z
        w = pose.orientation.w
        roll = atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y))
        pitch = atan2(2 * (w * y - x * z), 1 - 2 * (y * y + z * z))
        yaw = atan2(2 * (w * z + x * y), 1 - 2 * (z * z + y * y))

        # Return the yaw angle as the theta angle
        return yaw
        
        
        
    def plan(self, pose_x, pose_y, pose_theta, lookahead_distance=0.8, vgain=0.5):
        """
        This function is entry point for other Nodes trying to use this PurePursuitPlanner class.
        The waypoints file is configured in the PurePursuit and the calling class only instatiates and provide
        the pose_x, pose_y and pose_theta of the vehicle at current time.
        returns actuation (speed and steering angle)given observation. However, if other functions call this, they optionally use the speed returned.
        """
        # Get the current Position of the car
        position = np.array([pose_x, pose_y])

        # Search for the next waypoint to track based on lookahead distance parameter
        lookahead_point = self._get_current_waypoint(self.waypoints, lookahead_distance, position, pose_theta)
        #print("Lookahead Point: ",lookahead_point)

        if lookahead_point is None:
            return 4.0, 0.0

        # Calculate the Actuation: Steering angle and speed
        speed, steering_angle = get_actuation(pose_theta, lookahead_point, position, lookahead_distance, self.wheelbase)
        speed = vgain * speed
        
        return speed, steering_angle

   
    def timer_callback(self):
        
        try:
            trans = self.tf_buffer.lookup_transform('map', 'ego_racecar/base_link', rclpy.time.Time()) 
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
            self.get_logger().error('TF2 exception') 
            return
        
        
        pose = trans.transform.translation 
        
        pose_theta = math.atan2(trans.transform.rotation.z, trans.transform.rotation.w) * 2.0 
        
        lookahead_distance = 0.8
        vgain = 0.5
        theta = 1.1
        
        """
        TO DO:
        Learn to use trajectory planning tools at:
        https://github.com/TUMFTM/global_racetrajectory_optimization/blob/master/Readme.md
        
        """
       
        speed, steering_angle = self.plan(pose.x, pose.y, pose_theta, lookahead_distance, vgain)
        #speed, steering_angle = plan(vehicle_pos.x, vehicle_pos.y, vehicle_yaw, lookahead_distance, vgain)
        now = self.get_clock().now()
        #Prepare parameters for driving the vehicle
        driveMsg = AckermannDriveStamped()
        
        driveMsg.drive.steering_angle = steering_angle
        driveMsg.drive.speed = speed
        self.drivePubs.publish(driveMsg)
        
       
        
def main(args=None):
    rclpy.init(args=args) 
    node = PurePursuitPlanner() 
    rclpy.spin(node) 
    rclpy.shutdown() 

if __name__ == '__main__':
    main() 


