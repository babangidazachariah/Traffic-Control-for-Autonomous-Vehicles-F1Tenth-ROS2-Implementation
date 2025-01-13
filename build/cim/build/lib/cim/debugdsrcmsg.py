import rclpy
from rclpy.node import Node
from dsrcmsg.msg import IntersectionBSM  # Import the message type

class DSRCMessageSubscriber(Node):

    def __init__(self):
        super().__init__('dsrc_message_subscriber')
        self.subscription = self.create_subscription(
            IntersectionBSM,  # Specify the message type
            '/dsrcmsg',
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        self.get_logger().info('Received: %s' % msg)  # Log the received message

def main(args=None):
    rclpy.init(args=args)
    dsrc_message_subscriber = DSRCMessageSubscriber()
    rclpy.spin(dsrc_message_subscriber)
    dsrc_message_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
