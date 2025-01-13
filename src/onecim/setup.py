import os
from glob import glob
from setuptools import setup

package_name = 'onecim'

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
    maintainer_email='babangida@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'onecimtls = onecim.onecimtls:main',
            'fisonecimtls = onecim.FISBasedOneCIMTLS:main',
            'onecimlooptls = onecim.onecimlooptls:main',
            'rronecimlooptls = onecim.RoundRobinOneCIMLoopTLS:main',
            'onecimloopstatictls = onecim.onecimloopstatictls:main',
            'fisonecimlooptls = onecim.FISBasedCIMLoopTls:main',
            'rrfisonecimlooptls = onecim.RoundRobinFISBasedOneCIMLoopTLS:main',
            'benchmark = onecim.benchmarkcontroller:main',
            
            'onecimsn = onecim.oneintersectionsnagent:main',
            'onecimew = onecim.oneintersectionewagent:main',
            
            'onecimloopsn = onecim.onecimloopsnagent:main',
            'onecimloopew = onecim.onecimloopewagent:main',
            
            'snfiscim = onecim.snagentFISCIM:main',
            'ewfiscim = onecim.ewagentFISCIM:main',
            
            'playde = onecim.DisparityExtenderObstacleAvoidance:main',
            'playpp = onecim.PurePursuit:main',
            'simspeed = onecim.simSpeed:main',
            'wypts = onecim.simpleWaypoints:main',
            
            'veh = onecim.generateMultipleVehicles:main',
            'genveh = onecim.generateVehicles:main',
            'timegenveh = onecim.timedVehicleGeneration:main',
            
            'rectraffic = onecim.trafficRecordingNode:main',
            'srectraffic = onecim.southTrafficRecordingNode:main',
            'nrectraffic = onecim.northTrafficRecordingNode:main',
            'erectraffic = onecim.eastTrafficRecordingNode:main',
            'wrectraffic = onecim.westTrafficRecordingNode:main',
            'trafficrec = onecim.IntegrateTrafficRecords:main',
            
            'speed = onecim.measureSpeed:main',
        ],
    },
)
