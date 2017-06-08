// previously rosprocess.cpp

#include "data_node.h"
#include "../../../../shared_messages.h"

QTextStream qRCout(stdout);

DataNode::DataNode()
{
    int argc = 0;
    char * argv = 0;

  	ros::init(argc, &argv, "dash_gui");
  	ros::NodeHandle n;

  	ros::Publisher listener = n.advertise<std_msgs::String>("listen", 100);
    // TODO :: getting compile error here -- non static member function
  	ros::Subscriber sub1 = n.subscribe("/can_msg", 1000, &DataNode::chatterCallback_can_msg, this);
  	ros::Subscriber sub2 = n.subscribe("/fault_msg", 1000, &DataNode::chatterCallback_fault_msg, this);
  	ros::Subscriber gpio = n.subscribe("/gpio/all", 100, &DataNode::gpio_callback, this);

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
    // std::cout << msg->define << ";" << msg->msg->can_data << std::endl;
    // listen_message.data = msg->define + ";" + msg->msg->can_data + '\n';
    // listener.publish(listen_message);

    qRCout << "MSG:\t" << msg->define << "\t" << msg->can_data << endl;

    switch (msg->define)
    {
      case (TEMP_MOD_A):  // we take the same action on all of these
      case (TEMP_MOD_B):  // temp messages... so let the case all through,
      case (TEMP_MOD_C):  // only leaving one section of code that runs for each
      case (TEMP_GATE_DRIVER_BOARD): // case of temp
      case(TEMP_CONTROL_BOARD):
          if (msg->can_data > max_rinehart_temp)
          {
              max_rinehart_temp = msg->can_data;
              emit updateControllerTemp(max_rinehart_temp);
          }
          break;
      case (MOTOR_TEMP):
          emit updateMotorTemp(msg->can_data);
          break;
      case (REGEN_SIGNAL):
          break;
      case (MOTOR_ANGLE):
          break;
      case (MOTOR_SPEED):
          emit updateRPM(msg->can_data);
          emit updateRPM(QVariant(msg->can_data));
          break;
      case (RESOLVER_ANGLE):
          break;
      case (DC_CURRENT):
          emit updateDcCurrent(msg->can_data);
          break;
      case (DC_VOLTAGE):
          break;
      case (OUTPUT_VOLTAGE):
          emit updateOutputVolts(msg->can_data);
          break;
      case (PHASE_AB_VOLTAGE):
          break;
      case (PHASE_BC_VOLTAGE):
          break;
      case (IQ_FEEDBACK):
          break;
      case (ID_FEEDBACK):
          break;
      case (VSM_STATE):
         emit updateRMSVSM(msg->can_data);
         // qRCout << "VSM " << msg->can_data << endl;
         break;
     case (INVERTER_STATE):
         emit updateInverter(msg->can_data);
         break;
      case (FAULT):
          break;
      case (COMMAND_TORQUE):
          break;
      case (TORQUE_FEEDBACK):
          break;
      case (SPEED_CMD):
          break;
      case (PACK_CURRENT):
          emit updatePackCurrent(msg->can_data);
          break;
      case (PACK_INST_VOLTAGE):
          emit updatePackVolts(msg->can_data);
          break;
      case (PACK_TEMP_HIGH):
          emit updatePackTempHigh(msg->can_data);
          break;
      case (PACK_TEMP_LOW):
          break;
      case (PACK_SOC):
          emit updateSOC(msg->can_data);
          emit updateSOC(QVariant(msg->can_data));
          break;
    }
}

void DataNode::chatterCallback_fault_msg(const dash_gui::fault_msg::ConstPtr& msg)
{
  //ROS_INFO("motor [can_id]: [%i] rpm: %i RMS_currentL %i DC_voltage: %i drive6stat: %i", msg->can_id, msg->rpm, msg->RMS_current, msg->DC_voltage, msg->drive6stat);
  // std::cout << msg->define << ";" << msg->can_data << std::endl;
  // listen_message.data = msg->define + ";" + msg->can_data + '\n';
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

void DataNode::parseData(const dash_gui::can_msg::ConstPtr& msg)
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
