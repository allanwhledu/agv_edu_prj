execute_process(COMMAND "/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/controller_manager_msgs/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/sjtuwhl/ROBOTLAB_WS/devel/ros_control-melodic-devel/controller_manager_msgs/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
