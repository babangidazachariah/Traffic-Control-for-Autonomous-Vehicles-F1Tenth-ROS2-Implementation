# Traffic-Control-for-Autonomous-Vehicles-F1Tenth-ROS2-Implementation

### Description
In this project, ROS2 implementation of Autonomous driving of F1Tenth vehicles based on known algorithms (Disparity Extender and Pure Pursuit) are provided. However, because the focus is on Intelligent Traffic Control, a simulated implementation of vehicles driven using the Geo-Coordinate points used in Pure Pursuit and also have integrated abilities to transmit and receive V2X communication are used to make the simulation in an F1Tenth Environment more realistic. To simulate the traffic control problem, Static Pre-timed Controllers are used as benchmarks compared to the proposed Fuzzy Logic Controllers.

The implementation of the ROS2-based project was done using Python programming language.

### Technologies Used
<ul>
  <li><a href="https://github.com/f1tenth/f1tenth_gym_ros">F1Tenth Gym Ros </a> for simulation and visualization of driving perfomance of autonomous vehicles (F1Tenth)</li>
  <li><a href="https://scikit-fuzzy.readthedocs.io/en/latest/api/skfuzzy.html">SKFuzzy</a> for implementation of Fuzzy Inference Systems and Matplotlib library for visualization of the fuzzy controller parameters while tunning the controller</li>
  <li><a href="https://docs.ros.org/en/foxy/index.html">ROS2 Foxy</a> for the autonomous driving task</li>
  <li>ROS2 Messages, Topic Publisher/Subscriber Protocol for the V2X Communication</li>
  
</ul>

