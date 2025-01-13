#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray

class PlotPoints(Node):
    def __init__(self):
        super().__init__('plot_points')
        self.publisher_ = self.create_publisher(MarkerArray, 'pnt', 10)

        # create two markers for two points [4.0, -0.85] [15.3, -1.25]
        marker1 = Marker()
        marker1.header.frame_id = "map"
        marker1.type = Marker.CUBE
        marker1.action = Marker.ADD
        marker1.pose.position.x = 2.3
        marker1.pose.position.y = -0.85
        marker1.pose.position.z = 0.0
        marker1.pose.orientation.x = 0.0
        marker1.pose.orientation.y = 0.0
        marker1.pose.orientation.z = 0.0
        marker1.pose.orientation.w = 1.0
        marker1.scale.x = 0.2
        marker1.scale.y = 0.2
        marker1.scale.z = 0.2
        marker1.color.a = 1.0
        marker1.color.r = 1.0
        marker1.color.g = 0.0
        marker1.color.b = 0.0
        marker1.id = 1

        marker2 = Marker()
        marker2.header.frame_id = "map"
        marker2.type = Marker.CUBE
        marker2.action = Marker.ADD
        marker2.pose.position.x = 2.0
        marker2.pose.position.y = -0.85
        marker2.pose.position.z = 0.0
        marker2.pose.orientation.x = 0.0
        marker2.pose.orientation.y = 0.0
        marker2.pose.orientation.z = 0.0
        marker2.pose.orientation.w = 1.0
        marker2.scale.x = 0.2
        marker2.scale.y = 0.2
        marker2.scale.z = 0.2
        marker2.color.a = 1.0
        marker2.color.r = 0.0
        marker2.color.g = 1.0
        marker2.color.b = 0.0
        marker2.id = 2

        # create a marker array and add the two markers
        marker_array = MarkerArray()
        marker_array.markers.append(marker1)
        marker_array.markers.append(marker2)

        # publish the marker array
        self.publisher_.publish(marker_array)
        print('Published')
        

def main(args=None):
    rclpy.init(args=args)
    plot_points = PlotPoints()
    rclpy.spin(plot_points)
    plot_points.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
