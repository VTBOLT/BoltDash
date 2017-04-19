#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"

#include "can_msg.h"
#include "fault_msg.h"

#include <iostream>

#include "shared_messages.h"


void chatterCallback_can_msg(const can_to_qt_bolt3::can_msg::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << msg->define << ";" << msg->data << std::endl;
}

void chatterCallback_fault_msg(const can_to_qt_bolt3::fault_msg::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << msg->define << ";" << msg->data << std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "can_listner_bolt3");

  ros::NodeHandle n;

  ros::Subscriber sub1 = n.subscribe("can_msg", 1000, chatterCallback_can_msg);
  ros::Subscriber sub2 = n.subscribe("faul_msg", 1000, chatterCallback_fault_msg);
	
  ros::spin();

  return 0;
}
