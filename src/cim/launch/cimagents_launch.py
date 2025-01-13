from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cim',
            executable='snagent',
            name='snagent'
        ),
        Node(
            package='cim',
            executable='ewagent',
            name='ewagent'
        ),
      
    ])
