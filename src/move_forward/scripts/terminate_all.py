#!/usr/bin/env python
# import rospy
import os, os.path, sys
import time

def findPIDfromNode(val):
    # print(val)
    items = val.split(" ")
    pid = ""
    i = 0
    for item in items:
        if i is 0 or item is '':
            i = i + 1
            continue
        else:
            pid = item
            break
    return pid


node_names = [
    # ## cameras
    # 'kinect_driver.launch',
    # 'camera_driver/kinect_driver',
    # 'camera_driver/kinect_server',
    # 'tf/static_transform_publisher',

    ## AGV
    'laser.launch',
    'laserscan_multi_merger.launch',
    'demo.launch',
    'map_server/map_server',
    'amcl_omni.launch',
    'laser_scan_amcl.launch',
    'move_base.launch',
    'kinova_robot.launch',

    'openni2_tracker/openni2_tracker',
    'avoid_person_node/avoid_person_node',    
    'soccer_maxon/soccer_maxon_node',
   # 'velocity_smooth/velocity_smooth',
    'tofinal_service/tofinal_service',
    'jrc_move2/jrc_move2_initialpose',
    'jrc_move2/jrc_move2',


    # ## UR
    # 'ur_pick_srv_v3/ur_pick_srv_v3_node',
    # 'ur10_bringup.launch',

    # ## EE
    # 'ur_ee_server/ur_ee_server_node',

    # ## DECTET
    # 'detect_server/script/ssd_main_show.py',
    # ## POSE
    # 'pose_server/pose',
    # 'pose_server/pose_center_normal',

    # ## JRC_MAIN
    # 'jrc_main/jrc_status',
    # 'jrc_main/jrc_multi_robot'
    # #'jrc_main/scripts/process_kill_monitor.py'

]

sh_names = [
    # '6_start_uree_server.sh',
    # '5_start_ur_server.sh',
    # '4_start_pose_server.sh',
    # '3_start_detect_server.sh',
    # '2_start_camera_driver.sh',
    # '1_start_agv_server.sh',
    # 'start_ur.sh',
    # 'start_agv.sh',
    # 'start_vision.sh',
    # 'start_camera.sh',
    # 'start_camera_driver_launch.sh',
    # 'start_move2.sh'
    'start_agv_and_kinova.sh'
]


for sh_name in sh_names:
    print(sh_name)
    shs = os.popen('ps -ef|grep ' + sh_name + '|grep -v grep').read()
    shs = shs.split("\n")

    for sh in shs:
        if(sh != ""):
            sh_pid = findPIDfromNode(sh)
            os.system("kill " + sh_pid)
            print("killing " + sh_pid + " " + sh)


for node_name in node_names:
    print(node_name)
    vals = os.popen('ps -ef|grep ' + node_name + '|grep -v grep').read()
    vals = vals.split("\n")
    for val in vals:
        if val != "":
            val_pid = findPIDfromNode(val)
            os.system("kill " + val_pid)
            print("killing " + val_pid + " " + val)


# alias sourcedev='source devel/setup.bash'
