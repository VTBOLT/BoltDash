cmake_minimum_required(VERSION 2.8.3)
project(telemetry)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  )

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS} ~/dash/catkin_ws/devel/include/)

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
#add_dependencies(talker
#  )

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

