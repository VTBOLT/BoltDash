cmake_minimum_required(VERSION 2.8.3)
project(backend)

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
  rpm_msg.msg
  RMS_current_msg.msg
  DC_voltage_msg.msg
  drive6stat_msg.msg
  batterytemp_msg.msg
  HS_temp_msg.msg
  motor_temp_msg.msg
  voltage_angle_msg.msg
  current_msg.msg
  emcy6_msg.msg
  emcy7_msg.msg
  drive7_msg.msg
  )
## Generate added messages and services
generate_messages(
  DEPENDENCIES
  std_msgs
  backend
  )

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS} can/ msg/ ~/dash/catkin_ws/devel/include/backend/)

add_executable(can_talker_bolt2 src/can_talker_bolt2.cpp)
target_link_libraries(can_talker_bolt2 ${catkin_LIBRARIES})
add_dependencies(can_talker_bolt2
  can/canrecieve.cpp
  can/interfacecan.cpp
  )
add_dependencies(can_talker_bolt2 backend_generate_messages_cpp)

add_executable(can_listener_bolt2 src/can_listener_bolt2.cpp)
target_link_libraries(can_listener_bolt2 ${catkin_LIBRARIES})
add_dependencies(can_listener_bolt2 backend_generate_messages_cpp)


add_executable(can_listener_bolt2_debug src/can_listener_bolt2_debug.cpp)
target_link_libraries(can_listener_bolt2_debug ${catkin_LIBRARIES})
add_dependencies(can_listener_bolt2_debug backend_generate_messages_cpp)




