# Install script for directory: /home/sjtuwhl/ROBOTLAB_WS/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.bash;/usr/local/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES
    "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/setup.bash"
    "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.sh;/usr/local/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES
    "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/setup.sh"
    "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.zsh;/usr/local/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES
    "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/setup.zsh"
    "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES "/home/sjtuwhl/ROBOTLAB_WS/devel/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/gtest/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/gazebo_ros_pkgs-melodic-devel/gazebo_dev/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/gazebo_ros_pkgs-melodic-devel/gazebo_ros_pkgs/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/move_forward/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/ros_control/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/rqt_controller_manager/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/scan_tools/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/controller_manager_msgs/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3-melodic-devel/turtlebot3/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3_msgs-melodic-devel/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3-melodic-devel/turtlebot3_navigation/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3_simulations-melodic-devel/turtlebot3_simulations/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/urg_c-master/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/agv_tcp_velocity/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/hardware_interface/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/combined_robot_hw/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/controller_interface/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/controller_manager/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/soccer_maxon/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/agv_udp/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/controller_manager_tests/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/combined_robot_hw_tests/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/gazebo_ros_pkgs-melodic-devel/gazebo_msgs/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/laser_proc-melodic-devel/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/laser_scan_sparsifier/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/laser_scan_splitter/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/gazebo_ros_pkgs-melodic-devel/gazebo_ros/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/handle_reflector/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/ncd_parser/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ira_laser_tools-master/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/laser_ortho_projector/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/laser_scan_matcher/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/polar_scan_matcher/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/scan_tools-indigo/scan_to_cloud_converter/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/test_tf/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/transmission_interface/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3-melodic-devel/turtlebot3_bringup/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3-melodic-devel/turtlebot3_example/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3_simulations-melodic-devel/turtlebot3_fake/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3_simulations-melodic-devel/turtlebot3_gazebo/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3-melodic-devel/turtlebot3_slam/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3-melodic-devel/turtlebot3_teleop/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/gazebo_ros_pkgs-melodic-devel/gazebo_plugins/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/joint_limits_interface/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/gazebo_ros_pkgs-melodic-devel/gazebo_ros_control/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/urg_node-indigo-devel/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/nav_car/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/mrobot_gazebo/cmake_install.cmake")
  include("/home/sjtuwhl/ROBOTLAB_WS/devel/turtlebot3-melodic-devel/turtlebot3_description/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/sjtuwhl/ROBOTLAB_WS/devel/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
