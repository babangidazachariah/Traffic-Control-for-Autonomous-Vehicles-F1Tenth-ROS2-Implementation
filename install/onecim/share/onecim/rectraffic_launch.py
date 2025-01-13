from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='onecim',
            executable='nrectraffic',
            name='nrectraffic'
        ),
        Node(
            package='onecim',
            executable='srectraffic',
            name='srectraffic'
        ),
        Node(
            package='onecim',
            executable='erectraffic',
            name='erectraffic'
        ),
        Node(
            package='onecim',
            executable='wrectraffic',
            name='wrectraffic'
        ),
      
    ])
