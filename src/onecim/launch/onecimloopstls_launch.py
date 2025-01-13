from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='onecim',
            executable='onecimloopstatictls',
            name='onecimloopstatictls'
        ),
        Node(
            package='onecim',
            executable='onecimloopsn',
            name='onecimloopsn'
        ),
        Node(
            package='onecim',
            executable='onecimloopew',
            name='onecimloopew'
        ),
      
    ])
