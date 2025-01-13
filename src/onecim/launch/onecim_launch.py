from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='onecim',
            executable='onecimtls',
            name='onecimtls'
        ),
        Node(
            package='onecim',
            executable='onecimsn',
            name='onecimsn'
        ),
        Node(
            package='onecim',
            executable='onecimew',
            name='onecimew'
        ),
      
    ])
