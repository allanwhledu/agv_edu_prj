# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "agv_udp: 2 messages, 1 services")

set(MSG_I_FLAGS "-Iagv_udp:/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(agv_udp_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg" NAME_WE)
add_custom_target(_agv_udp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "agv_udp" "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg" ""
)

get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg" NAME_WE)
add_custom_target(_agv_udp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "agv_udp" "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg" ""
)

get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv" NAME_WE)
add_custom_target(_agv_udp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "agv_udp" "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/agv_udp
)
_generate_msg_cpp(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/agv_udp
)

### Generating Services
_generate_srv_cpp(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/agv_udp
)

### Generating Module File
_generate_module_cpp(agv_udp
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/agv_udp
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(agv_udp_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(agv_udp_generate_messages agv_udp_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_cpp _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_cpp _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv" NAME_WE)
add_dependencies(agv_udp_generate_messages_cpp _agv_udp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(agv_udp_gencpp)
add_dependencies(agv_udp_gencpp agv_udp_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS agv_udp_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/agv_udp
)
_generate_msg_eus(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/agv_udp
)

### Generating Services
_generate_srv_eus(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/agv_udp
)

### Generating Module File
_generate_module_eus(agv_udp
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/agv_udp
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(agv_udp_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(agv_udp_generate_messages agv_udp_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_eus _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_eus _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv" NAME_WE)
add_dependencies(agv_udp_generate_messages_eus _agv_udp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(agv_udp_geneus)
add_dependencies(agv_udp_geneus agv_udp_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS agv_udp_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/agv_udp
)
_generate_msg_lisp(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/agv_udp
)

### Generating Services
_generate_srv_lisp(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/agv_udp
)

### Generating Module File
_generate_module_lisp(agv_udp
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/agv_udp
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(agv_udp_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(agv_udp_generate_messages agv_udp_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_lisp _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_lisp _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv" NAME_WE)
add_dependencies(agv_udp_generate_messages_lisp _agv_udp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(agv_udp_genlisp)
add_dependencies(agv_udp_genlisp agv_udp_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS agv_udp_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/agv_udp
)
_generate_msg_nodejs(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/agv_udp
)

### Generating Services
_generate_srv_nodejs(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/agv_udp
)

### Generating Module File
_generate_module_nodejs(agv_udp
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/agv_udp
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(agv_udp_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(agv_udp_generate_messages agv_udp_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_nodejs _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_nodejs _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv" NAME_WE)
add_dependencies(agv_udp_generate_messages_nodejs _agv_udp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(agv_udp_gennodejs)
add_dependencies(agv_udp_gennodejs agv_udp_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS agv_udp_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/agv_udp
)
_generate_msg_py(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/agv_udp
)

### Generating Services
_generate_srv_py(agv_udp
  "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/agv_udp
)

### Generating Module File
_generate_module_py(agv_udp
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/agv_udp
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(agv_udp_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(agv_udp_generate_messages agv_udp_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/CenterCmd.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_py _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg/ReserveArea.msg" NAME_WE)
add_dependencies(agv_udp_generate_messages_py _agv_udp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/srv/Replan.srv" NAME_WE)
add_dependencies(agv_udp_generate_messages_py _agv_udp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(agv_udp_genpy)
add_dependencies(agv_udp_genpy agv_udp_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS agv_udp_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/agv_udp)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/agv_udp
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(agv_udp_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/agv_udp)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/agv_udp
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(agv_udp_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/agv_udp)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/agv_udp
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(agv_udp_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/agv_udp)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/agv_udp
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(agv_udp_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/agv_udp)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/agv_udp\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/agv_udp
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(agv_udp_generate_messages_py std_msgs_generate_messages_py)
endif()
