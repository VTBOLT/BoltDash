#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "temp_mod_a_msg.msg"
#include "temp_mod_b_msg.msg"
#include "temp_mod_c_msg.msg"
#include "temp_gate_driver_board_msg.msg"
#include "temp_control_board_msg.msg"
#include "motor_temp_msg.msg"
#include "regen_signal_msg.msg"
#include "motor_angle_msg.msg"
#include "motor_speed_msg.msg"
#include "resolver_angle_msg.msg"
#include "dc_current_msg.msg"
#include "dc_voltage_msg.msg"
#include "output_voltage_msg.msg"
#include "phase_ab_voltage_msg.msg"
#include "phase_bc_voltage_msg.msg"
#include "id_feedback_msg.msg"
#include "iq_feedback_msg.msg"
#include "vsm_state_msg.msg"
#include "inverter_state_msg.msg"
#include "fault_msg.msg"
#include "command_torque_msg.msg"
#include "torque_feedback_msg.msg"
#include <iostream>
#include "shared_messages.h"
void chatterCallback_temp_mod_a(const can_to_qt_bolt3:temp_mod_a::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_A << ";" << msg->data << std::endl;
}
void chatterCallback_temp_mod_b(const can_to_qt_bolt3:temp_mod_b::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_B << ";" << msg->data << std::endl;
}

void chatterCallback_tmep_mod_c(const can_to_qt_bolt3:temp_mod_c::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}
void chatterCallback_temp_gate_driver_board(const can_to_qt_bolt3:temp_gate_driver_board::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_GATE_DRIVER_BOARD << ";" << msg->data << std::endl;
}

void chatterCallback_temp_control_board(const can_to_qt_bolt3:temp_control_board::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_CONTROL_BOARD << ";" << msg->data << std::endl;
}

void chatterCallback_motor_temp(const can_to_qt_bolt3:motor_temp::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << MOTOR_TEMP << ";" << msg->data << std::endl;
}

void chatterCallback_regen_signal(const can_to_qt_bolt3:regen_signal::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << REGEN_SIGNAL << ";" << msg->data << std::endl;
}

void chatterCallback_motor_angle(const can_to_qt_bolt3:motor_angle::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << MOTOR_ANGLE << ";" << msg->data << std::endl;
}

void chatterCallback_motor_speed(const can_to_qt_bolt3:motor_speed::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << MOTOR_SPEED << ";" << msg->data << std::endl;
}

void chatterCallback_resolver_angle(const can_to_qt_bolt3:resolver_angle::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << RESOLVER_ANGLE << ";" << msg->data << std::endl;
}

void chatterCallback_dc_current(const can_to_qt_bolt3:dc_current::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << DC_CURRENT << ";" << msg->data << std::endl;
}

void chatterCallback_dc_voltage(const can_to_qt_bolt3:dc_voltage::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout <<  << ";" << msg->data << std::endl;
}

void chatterCallback_output_voltage(const can_to_qt_bolt3:output_voltage::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_phase_ab_voltage(const can_to_qt_bolt3:phase_ab_voltage::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_phase_bc_voltage(const can_to_qt_bolt3:phase_bc_voltage::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_id_feedback(const can_to_qt_bolt3:id_feedback::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_iq_feedback(const can_to_qt_bolt3:iq_feedback::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_vsm_state(const can_to_qt_bolt3:vsm_state::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_inverter_state(const can_to_qt_bolt3:inverter_state::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_fault(const can_to_qt_bolt3:fault::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_command_torque(const can_to_qt_bolt3:command_torque::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  std::cout << TEMP_MOD_C << ";" << msg->data << std::endl;
}

void chatterCallback_torque_feedback(const can_to_qt_bolt3::torque_feedback::ConstPtr& msg)
{
  //ROS_INFO("batterytemp [can_id]: [%i] batterytemp: %i", msg->can_id, msg->data);
  std::cout << TORQUE_FEEDBACK << ";" << msg->data << std::endl;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "can_listner_bolt3");

  ros::NodeHandle n;

  ros::Subscriber sub1 = n.subscribe("chatter_motor", 1000, chatterCallback_motor);
  ros::Subscriber sub2 = n.subscribe("chatter_batterytemp", 1000, chatterCallback_batterytemp);
  ros::Subscriber sub3 = n.subscribe("chatter_temp", 1000, chatterCallback_temp);
  ros::Subscriber sub4 = n.subscribe("chatter_current", 1000, chatterCallback_current);
  ros::Subscriber sub5 = n.subscribe("chatter_emcy6", 1000, chatterCallback_emcy6);
  ros::Subscriber sub6 = n.subscribe("chatter_emcy7", 1000, chatterCallback_emcy7);
  ros::Subscriber sub7 = n.subscribe("chatter_drive7", 1000, chatterCallback_drive7);
	
  ros::spin();

  return 0;
}
