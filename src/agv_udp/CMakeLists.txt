cmake_minimum_required(VERSION 2.8.3)
project(agv_udp)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  message_generation
)

add_message_files(
  FILES
  ReserveArea.msg
  CenterCmd.msg
)
 add_service_files(
  FILES
  Replan.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(  CATKIN_DEPENDS message_runtime)

include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)



add_executable(udp_sender_node src/udp_sender.cpp)

target_link_libraries(udp_sender_node
  ${catkin_LIBRARIES}
)

add_executable(udp_receiver_node src/udp_receiver.cpp)

target_link_libraries(udp_receiver_node
  ${catkin_LIBRARIES}
)


add_executable(udp_server_node src/udp_server.cpp)

target_link_libraries(udp_server_node
  ${catkin_LIBRARIES}
)

add_executable(udp_client_node src/udp_client.cpp)

target_link_libraries(udp_client_node
  ${catkin_LIBRARIES}
)


add_executable(udp_server_multi_robot src/udp_server_multi_robot.cpp)

target_link_libraries(udp_server_multi_robot
  ${catkin_LIBRARIES}
)


add_executable(udp_server_v2 src/udp_server_v2.cpp)

target_link_libraries(udp_server_v2
  ${catkin_LIBRARIES}
)


add_executable(test_udp_server_v3 src/test_udp_server_v3.cpp  src/udp_server_v3.cpp)

target_link_libraries(test_udp_server_v3
  ${catkin_LIBRARIES})


add_executable(test_udp_move src/test_udp_move.cpp)

target_link_libraries(test_udp_move
  ${catkin_LIBRARIES}
)
add_executable(test_udp_move_robot_2 src/test_udp_move_robot_2.cpp)

target_link_libraries(test_udp_move_robot_2
  ${catkin_LIBRARIES}
)



add_executable(test_rev_path_point_move src/test_rev_path_point_move.cpp  src/receive_path_point_move.cpp)

target_link_libraries(test_rev_path_point_move
  ${catkin_LIBRARIES})



add_executable(test_simulation_server src/test_simulation_server.cpp  src/simulation_server.cpp)

target_link_libraries(test_simulation_server
  ${catkin_LIBRARIES})


add_executable(test_distributed_reserve_area src/test_distributed_reserve_area.cpp  src/distributed_reserve_area.cpp  src/Astar.cpp)

target_link_libraries(test_distributed_reserve_area
  ${catkin_LIBRARIES})


add_executable(center_control src/center_control.cpp)

target_link_libraries(center_control
  ${catkin_LIBRARIES})

add_executable(replan_server src/replan_server.cpp)

target_link_libraries(replan_server
  ${catkin_LIBRARIES})

