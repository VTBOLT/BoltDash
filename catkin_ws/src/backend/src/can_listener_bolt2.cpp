#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"

#include "rpm_msg.h"
#include "RMS_current_msg.h"
#include "DC_voltage_msg.h"

#include "batterytemp_msg.h"
#include "HS_temp_msg.h"
#include "motor_temp_msg.h"
#include "voltage_angle_msg.h"
#include "current_msg.h"
#include "emcy6_msg.h"
#include "emcy7_msg.h"
#include "drive7_msg.h"

#include <iostream>

#define RPM         0
#define BATT_TEMP   1
#define RMS_CURRENT 2
#define DC_VOLTS    3
#define HS_TEMP     4
#define MOTOR_TEMP  5
#define VOLT_ANGLE  6
#define IQ_CURRENT  7
#define EMCY6       8
#define EMCY7       9
#define D6_STAT     10
#define D7_STAT     11

void chatterCallback_rpm(const backend::rpm_msg::ConstPtr& msg){
  //ROS_INFO("motor [can_id]: [%i] rpm: %i ", msg->can_id, msg->rpm);
  std::cout << RPM << ";" << msg->data << std::endl;
}
void chatterCallback_RMS_current(const backend::RMS_current_msg::ConstPtr& msg){
  //ROS_INFO("motor [can_id]: [%i] RMS_current: %i", msg->can_id, msg->RMS_current);
  std::cout << RMS_CURRENT << ";" << msg->data << std::endl;
}
void chatterCallback_DC_voltage(const backend::DC_voltage_msg::ConstPtr& msg){
  //ROS_INFO("motor [can_id]: [%i] DC_voltage: %i", msg->can_id, msg->DC_voltage);
  std::cout << DC_VOLTS << ";" << msg->data << std::endl;
}
void chatterCallback_batterytemp(const backend::batterytemp_msg::ConstPtr& msg)
{
  //ROS_INFO("batterytemp [can_id]: [%i] batterytemp: %i", msg->can_id, msg->data);
  std::cout << BATT_TEMP << ";" << msg->data << std::endl;
}
void chatterCallback_HS_temp(const backend::HS_temp_msg::ConstPtr& msg){
   //ROS_INFO("temp [can_id]: [%i], HS_temp: %i ", msg->can_id, msg->HS_temp);
  std::cout <<  HS_TEMP << ";" << msg->data << std::endl;
}
void chatterCallback_motor_temp(const backend::motor_temp_msg::ConstPtr& msg){
    //ROS_INFO("temp [can_id]: [%i],motor_temp: %i ", msg->can_id, msg->motor_temp);
  std::cout << MOTOR_TEMP << ";" << msg->data  << std::endl;
}
void chatterCallback_voltage_angle(const backend::voltage_angle_msg::ConstPtr& msg){
    //ROS_INFO("temp [can_id]: [%i],voltage_angle: %i", msg->can_id, msg->voltage_angle);
  std::cout << VOLT_ANGLE << ";" << msg->data << std::endl;
}

void chatterCallback_current(const backend::current_msg::ConstPtr& msg)
{
  //ROS_INFO("current [can_id]: [%i], IQ_current: %i", msg->can_id, msg->data);
  std::cout << IQ_CURRENT << ";" << msg->data << std::endl;
}

void chatterCallback_emcy6(const backend::emcy6_msg::ConstPtr& msg)
{
  //ROS_INFO("EMCY6 [can_id]: [%i], emcy6: %i", msg->can_id, msg->data);
  std::cout << EMCY6 << ";" << msg->data << std::endl;
}

void chatterCallback_emcy7(const backend::emcy7_msg::ConstPtr& msg)
{
  //ROS_INFO("EMCY7 [can_id]: [%i], emcy7: %i", msg->can_id, msg->data);
  std::cout << EMCY7 << ";" << msg->data << std::endl;
}

void chatterCallback_drive7(const backend::drive7_msg::ConstPtr& msg)
{
  //ROS_INFO("drive7 [can_id]: [%i], drive7: %i", msg->can_id, msg->data);
  std::cout << D7_STAT  << ";" << msg->data << std::endl;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "can_listner_bolt2");

  ros::NodeHandle n;

  ros::Subscriber sub1 = n.subscribe("chatter_rpm", 1000, chatterCallback_rpm);
  ros::Subscriber sub2 = n.subscribe("chatter_RMS_current", 1000, chatterCallback_RMS_current);
  ros::Subscriber sub3 = n.subscribe("chatter_DC_voltage", 1000, chatterCallback_DC_voltage);
  ros::Subscriber sub4 = n.subscribe("chatter_batterytemp", 1000, chatterCallback_batterytemp);
  ros::Subscriber sub5 = n.subscribe("chatter_HS_temp", 1000, chatterCallback_HS_temp);
  ros::Subscriber sub6 = n.subscribe("chatter_motor_temp", 1000, chatterCallback_motor_temp);
  ros::Subscriber sub7 = n.subscribe("chatter_voltage_angle", 1000, chatterCallback_voltage_angle);
  ros::Subscriber sub8 = n.subscribe("chatter_current", 1000, chatterCallback_current);
  ros::Subscriber sub9 = n.subscribe("chatter_emcy6", 1000, chatterCallback_emcy6);
  ros::Subscriber sub10 = n.subscribe("chatter_emcy7", 1000, chatterCallback_emcy7);
  ros::Subscriber sub11 = n.subscribe("chatter_drive7", 1000, chatterCallback_drive7);
	
  ros::spin();

  return 0;
}
