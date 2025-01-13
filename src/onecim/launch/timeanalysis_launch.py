from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='onecim',
            executable='onecimlooptls',
            name='onecimlooptls'
        ),
        Node(
            package='onecim',
            executable='veh',
            name='veh'
        ),
      
    ])
