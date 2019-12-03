#!/bin/bash -e
sleep 2
roslaunch  agv_tcp_velocity laser.launch&
sleep 1
roslaunch ira_laser_tools laserscan_multi_merger.launch&
sleep 1
rosrun map_server map_server /home/sjtuwhl/ROBOTLAB_WS/src/map.yaml&
sleep 1
roslaunch laser_scan_matcher demo.launch&
sleep 1
roslaunch amcl amcl_omni.launch&
sleep 1
roslaunch agv_tcp_velocity move_base.launch&
sleep 5
sudo chmod 777 /dev/ttyUSB0
sleep 2
rosrun soccer_maxon soccer_maxon_node&
sleep 1

source /home/sjtuwhl/ROBOTLAB_WS/devel/setup.bash&

roslaunch move_forward move_and_avoid_dynamic_object.launch&
