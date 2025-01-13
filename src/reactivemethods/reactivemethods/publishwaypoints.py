import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from visualization_msgs.msg import MarkerArray

class MarkerArrayPublisher(Node):

    def __init__(self):
        super().__init__('marker_array_publisher')
        self.publisher_ = self.create_publisher(MarkerArray, 'waypoints', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        marker_array = MarkerArray()

        # Create a red cube marker
        marker1 = Marker()
        marker1.header.frame_id = "path_waypoints"
        marker1.header.stamp = self.get_clock().now().to_msg()
        marker1.id = 0
        marker1.type = Marker.CUBE
        marker1.action = Marker.ADD
        marker1.pose.position.x = 0.0
        marker1.pose.position.y = 0.0
        marker1.pose.position.z = 0.0
        marker1.pose.orientation.x = 0.0
        marker1.pose.orientation.y = 0.0
        marker1.pose.orientation.z = 0.0
        marker1.pose.orientation.w = 1.0
        marker1.scale.x = 0.5
        marker1.scale.y = 0.5
        marker1.scale.z = 0.5
        marker1.color.a = 1.0
        marker1.color.r = 1.0
        marker1.color.g = 0.0
        marker1.color.b = 0.0

        # Create a green sphere marker
        marker2 = Marker()
        marker2.header.frame_id = "map"
        marker2.header.stamp = self.get_clock().now().to_msg()
        marker2.id = 1
        marker2.type = Marker.SPHERE
        marker2.action = Marker.ADD
        marker2.pose.position.x = 1.0
        marker2.pose.position.y = 0.0
        marker2.pose.position.z = 0.0
        marker2.pose.orientation.x = 0.0
        marker2.pose.orientation.y = 0.0
        marker2.pose.orientation.z = 0.0
        marker2.pose.orientation.w = 1.0
        marker2.scale.x = 0.5
        marker2.scale.y = 0.5
        marker2.scale.z = 0.5
        marker2.color.a = 1.0
        marker2.color.r = 0.0
        marker2.color.g = 1.0
        marker2.color.b = 0.0

        # Add the markers to the array and publish it
        marker_array.markers.append(marker1)
        marker_array.markers.append(marker2)
        
        self.publisher_.publish(marker_array)

def main(args=None):
    rclpy.init(args=args)

    node = MarkerArrayPublisher()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
