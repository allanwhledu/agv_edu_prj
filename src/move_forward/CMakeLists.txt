cmake_minimum_required(VERSION 2.8.3)
project(move_forward)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  rospy
  tf
  message_generation
)

add_service_files(
  FILES
  agv_call.srv
)


generate_messages(DEPENDENCIES  std_msgs)

catkin_package(
CATKIN_DEPENDS message_runtime
)




include_directories(${catkin_INCLUDE_DIRS}
../../../devel/include
)


add_executable(move_forward_one_meter src/move_forward_one_meter.cpp)
target_link_libraries(move_forward_one_meter ${catkin_LIBRARIES} )

add_executable(record_data src/record_data.cpp)
target_link_libraries(record_data ${catkin_LIBRARIES} )


add_executable(jrc_move2_initialpose src/jrc_move2_initialpose.cpp)
target_link_libraries(jrc_move2_initialpose ${catkin_LIBRARIES} )


add_executable(move_and_avoid_dynamic_object src/move_and_avoid_dynamic_object.cpp)
target_link_libraries(move_and_avoid_dynamic_object ${catkin_LIBRARIES} )



