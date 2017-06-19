# I had to run this before it would work...
# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/mcghee/Qt/5.8/gcc_64/lib

cmake_minimum_required(VERSION 2.8.3)
project(dash_gui)

if("$ENV{ROS_DISTRO}" STRGREATER "jade")
  set(USE_QT5 true)
else()
  set(USE_QT5 false)
endif()

find_package(catkin REQUIRED COMPONENTS roscpp rqt_gui rqt_gui_cpp
  std_msgs
  genmsg 
  message_generation
)



## Declare ROS messages and services
#add_message_files(
#  DIRECTORY
#  msg
#  FILES
#  can_msg.msg
#  fault_msg.msg
#  gpio_msg.msg
#)

## Generate added messages and services
#generate_messages(
#  DEPENDENCIES
#  std_msgs
#  dash_gui
#)

#file(GLOB hdr "msg/*.h" can/*.h)

if(${USE_QT5})
  # Autogenerate the MOC files
  set(CMAKE_AUTOMOC ON)
  set(CMAKE_AUTOINC ON)
  # Tell catkin where to look for the moc files
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
  # Get the Qt components
  find_package(Qt5 COMPONENTS Core Widgets Qml Quick QuickWidgets REQUIRED)
  #find_package(Qt5 COMPONENTS Widgets REQUIRED)
  message("Using QT5")
  set(QT_LIBRARIES Qt5::Widgets Qt5::Qml Qt5::Quick Qt5::QuickWidgets)
  #set(QT_LIBRARIES Qt5::Widgets)
else()
  message ("Using QT4")
  find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
  include(${QT_USE_FILE})
endif()

set(dash_gui_SRCS
  src/dash_gui.cpp
  src/data_node.cpp
)

set(dash_gui_HDRS
  include/dash_gui.h
  include/data_node.h
)

set(dash_gui_UIS
  resource/dash_gui.ui
)

set(dash_gui_INCLUDE_DIRECTORIES
  include
  ${CMAKE_CURRENT_BINARY_DIR}
)

catkin_package(
  INCLUDE_DIRS include ${dash_gui_INCLUDE_DIRECTORIES}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp rqt_gui rqt_gui_cpp std_msgs
)

include_directories(include)

if(${USE_QT5})
  qt5_wrap_cpp(dash_gui_MOCS ${dash_gui_HDRS})
  qt5_wrap_ui(dash_gui_UIS_H ${dash_gui_UIS})
  qt5_add_resources(dash_gui_RESOURCE resource/resources.qrc)
  include_directories(include 
    ${catkin_INCLUDE_DIRS}
    ${dash_gui_INCLUDE_DIRECTORIES}
    ${catkin_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDES}
    ${Qt5Quick_INCLUDES}
    ${Qt5Qml_INCLUDES}
    ${OpenCV_INCLUDE_DIRS})
  add_definitions(${Qt5Widgets_DEFINITIONS})
else()
  qt4_wrap_cpp(dash_gui_MOCS ${dash_gui_HDRS})
  qt4_wrap_ui(dash_gui_UIS_H ${dash_gui_UIS})
  qt4_add_resources(dash_gui_RESOURCE resource/resources.qrc)
  include_directories(
    ${dash_gui_INCLUDE_DIRECTORIES}
    ${catkin_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS})
endif()

add_library(
  ${PROJECT_NAME}
  ${dash_gui_SRCS}
  ${dash_gui_MOCS}
  ${dash_gui_UIS_H}
  ${dash_gui_RESOURCE}
)


if(${USE_QT5})

  target_link_libraries(
    ${PROJECT_NAME}
    ${catkin_LIBRARIES}
    ${QT_QTCORE_LIBRARY}
    ${QT_LIBRARIES}
    ${OpenCV_LIBRARIES})
else()
  target_link_libraries(
    ${PROJECT_NAME}
    ${catkin_LIBRARIES}
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
    ${OpenCV_LIBRARIES})
endif()

#add_dependencies(dash_gui)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS} include)

find_package(class_loader)
class_loader_hide_library_symbols(${PROJECT_NAME}) 

find_package(catkin REQUIRED COMPONENTS dash_gui)
include_directories(include 
  ${catkin_INCLUDE_DIRS}
  ${CATKIN_DEVEL_PREFIX}/include/can_to_qt_bolt3/
  ${CATKIN_DEVEL_PREFIX}/../../
)

install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

set_target_properties(
  dash_gui
    PROPERTIES
    COMPILE_FLAGS
      "-std=c++11")
