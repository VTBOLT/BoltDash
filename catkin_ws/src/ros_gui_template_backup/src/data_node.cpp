// previously rosprocess.cpp

#include "data_node.h"

DataNode::DataNode()
{
  int argc = 0;
  char * argv = 0;

	ros::init(argc, &argv, "can_listener_bolt");
	ros::NodeHandle n;

	ros::Publisher listener = n.advertise<std_msgs::String>("listen", 100);
  // TODO :: getting compile error here -- non static member function
	ros::Subscriber sub1 = n.subscribe("/can_msg", 1000, chatterCallback_can_msg);
	ros::Subscriber sub2 = n.subscribe("/fault_msg", 1000, chatterCallback_fault_msg);
	ros::Subscriber gpio = n.subscribe("/gpio/all", 100, gpio_callback);

	// ros::MultiThreadedSpinner spinner(); // Use number of threads as number of cores
	 
  return;
}

void DataNode::run()
{ 
  while(ros::ok())
  {
    ros::spin(); // spin() will not return until the node has been shutdown
  }
  return;
}

void DataNode::chatterCallback_can_msg(const dash_gui::can_msg::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  // std::cout << msg->define << ";" << msg->can_data << std::endl;
  // listen_message.data = msg->define + ";" + msg->can_data + '\n';
  // listener.publish(listen_message);
}

void DataNode::chatterCallback_fault_msg(const dash_gui::fault_msg::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  // std::cout << msg->define << ";" << msg->msg_data << std::endl;
  // listen_message.data = msg->define + ";" + msg->msg_data + '\n';
  // listener.publish(listen_message);
}

void DataNode::gpio_callback(const dash_gui::gpio_msg::ConstPtr& msg)
{
  // std::cout << gpio_IGNOK << ";" << (int)msg->IGNOK <<std::endl;
  // std::cout << gpio_IMD << ";" << (int)msg->IMD <<std::endl;
  // std::cout << gpio_PRESSURE << ";" << (int)msg->PRESSURE <<std::endl;
  // std::cout << gpio_BMSDE << ";" << (int)msg->BMSDE <<std::endl;

  // listen_message.data = (int)msg->IGNOK + (int)msg->IMD + (int)msg->PRESSURE + (int)msg->BMSDE + '\n';
  // listener.publish(listen_message);
}



// Old fxns from rosprocess

void DataNode::parseData(QByteArray data)
{
	return;
}

void DataNode::parseError()
{
	return;
}

void DataNode::readData()
{
    return;
}

void DataNode::readError()
{
    return;
}
