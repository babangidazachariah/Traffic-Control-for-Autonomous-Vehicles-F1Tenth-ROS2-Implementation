from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='reactivemethods',
            executable='northsouthagent',
            name='northsouthagent'
        ),
        Node(
            package='reactivemethods',
            executable='westeastagent',
            name='westeastagent'
        ),
    ])
