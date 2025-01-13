import os
from glob import glob
from setuptools import setup

package_name = 'cim'

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
            'cimnode = cim.cimnode:main',
            'playde = cim.DisparityExtenderObstacleAvoidance:main',
            'playpp = cim.PurePursuit:main',
            'snagent = cim.snagent:main',
            'ewagent = cim.ewagent:main',
            'dsrcsimplecim = cim.DsrcBasedSimpleCIM:main',
            'recanalysis = cim.TrafficRecordingAnalysis:main',
            'recanalysisserver = cim.TrafficRecordingAnalysisServer:main',
            'statictls = cim.StaticTrafficLights:main',
            'stlssnagent = cim.stlssnagent:main',
            'stlsewagent = cim.stlsewagent:main',
            'plotpoint = cim.plotPoint:main',
            'fiscim = cim.FISCentralizedIntersectionController:main',
            'fissnagent = cim.fisnsagent:main',
            'fisewagent = cim.fisewagent:main',
            'test = cim.testStop:main',
            'debugewagent = cim.debugewagent:main',
            'fhcim = cim.FISBasedCIM:main',
            'tlssnagent = cim.tlssnagent:main',
            'tlsewagent = cim.tlsewagent:main',
            'debugdsrcmsg = cim.debugdsrcmsg:main',
            
        ],
    },
)
