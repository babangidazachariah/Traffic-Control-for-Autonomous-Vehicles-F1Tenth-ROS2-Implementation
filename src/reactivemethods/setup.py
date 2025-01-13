#from setuptools import setup
import os
from glob import glob
from setuptools import setup
package_name = 'reactivemethods'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*_launch.py')),
    ],
    
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='babangida',
    maintainer_email='babangida.zachariah@ontariotechu.net',
    description='A simple Reactive Autononomous Driving: Automatic Breaking, left-wall following, right-wall following, gap following, waypoint following (pure pursuit) ROS-based self-driven vehicle.',
    license='Ontario Tech University License',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'emergencybreaking = reactivemethods.emergencybreaking:main',
            'leftwallfollowing = reactivemethods.leftwallfollowing:main',
            'gapfollowing = reactivemethods.gapfollowing:main',
            'agapfollowing = reactivemethods.agapfollowing:main',
            'followgap = reactivemethods.followgap:main',
            'degapfollowing = reactivemethods.disparityextendergapfollowing:main',
            'purepursuit = reactivemethods.PurePursuit:main',
            'waypointfollow = reactivemethods.waypointfollow:main',
            'agent1purepursuit = reactivemethods.agent1purepursuit:main',
            'publishwaypoints = reactivemethods.publishwaypoints:main',
            'waypointsgenerator = reactivemethods.posebasewaypointgenerator:main',
            'wptflw = reactivemethods.simplewptflw:main',
            'northsouthagent = reactivemethods.northsouthagent:main',
            'westeastagent = reactivemethods.westeastagent:main',
            'play = reactivemethods.autotrafficplayground:main',
            
            
        ],
    },
)
