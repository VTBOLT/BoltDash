cmake_minimum_required(VERSION 2.8.3)
project(can_to_qt_bolt3)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
  message_generation
  )

## Declare ROS messages and services
add_message_files(
  DIRECTORY
  msg
  FILES
  can_msg.msg
  fault_msg.msg
  gpio_msg.msg
  )
## Generate added messages and services
generate_messages(
  DEPENDENCIES
  std_msgs
  can_to_qt_bolt3
  )

file(GLOB shared_hdr "../../../*.h")
file(GLOB hdr "msg/*.h" can/*.h)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS} can/ msg/ ~/dash/catkin_ws/devel/include/can_to_qt_bolt3/ ~/dash/)
add_executable(can_talker_bolt3 src/can_talker_bolt3.cpp ${shared_hdr} ${hdr})
target_link_libraries(can_talker_bolt3 ${catkin_LIBRARIES})
add_dependencies(can_talker_bolt3
  can/canreceive.cpp
  can/interfacecan.cpp
  can/can_fault_code_fsm.cpp
  ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
  )
add_dependencies(can_talker_bolt3 can_to_qt_bolt3_generate_messages_cpp)


add_executable(can_listener_bolt3 src/can_listener_bolt3.cpp ${shared_hdr} ${hdr})
target_link_libraries(can_listener_bolt3 ${catkin_LIBRARIES})
add_dependencies(can_listener_bolt3 can_to_qt_bolt3_generate_messages_cpp include)
  
#add_executable(can_listener_bolt3_debug src/can_listener_bolt3_debug.cpp)
#target_link_libraries(can_listener_bolt3_debug ${catkin_LIBRARIES})
#add_dependencies(can_listener_bolt3_debug can_to_qt_bolt3_generate_messages_cpp)
