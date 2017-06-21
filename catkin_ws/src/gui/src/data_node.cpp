// previously rosprocess.cpp

#include "data_node.h"
#include "shared_messages.h"

QTextStream qRCout(stdout);

DataNode::DataNode()
{
    int argc = 0;
    char ** argv = 0;

  	ros::init(argc, argv, "dash_gui");

    listener = n.advertise<std_msgs::String>("listen", 100);

  	sub1 = n.subscribe("/can_msg", 1000, &DataNode::chatterCallback_can_msg, this);
    sub2 = n.subscribe("/fault_msg", 1000, &DataNode::chatterCallback_fault_msg, this);
  	gpio = n.subscribe("/gpio/all", 100, &DataNode::gpio_callback, this);

  	// ros::MultiThreadedSpinner spinner(); // Use number of threads as number of cores
	 
  return;
}

void DataNode::run()
{
    qRCout << ">>> Run" << endl; 
    while(ros::ok())
    {
      qRCout << "OK" << endl;
      ros::spin(); // spin() will not return until the node has been shutdown
    }
    qRCout << "No more OK" << endl;
    return;
}

void DataNode::chatterCallback_can_msg(const can_to_qt_bolt3::can_msg::ConstPtr& msg)
{
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
            break;
        case PACK_CCL:
          break;
        case PACK_DCL:
            break;
        case BMS_TEMP:
            break;
        case CELL_VOLT_HIGH_ID:
            break;  
        case CELL_VOLT_HIGH:
            break;
        case CELL_VOLT_LOW_ID:
            break;
        case CELL_VOLT_LOW:
            break;
        case REGEN_DISABLE:
            break;
        case DC_BUS_CURRENT:
            break;
        case DC_BUS_VOLTAGE:
            break;
    }
}

void DataNode::chatterCallback_fault_msg(const can_to_qt_bolt3::fault_msg::ConstPtr& msg)
{
  
}

void DataNode::gpio_callback(const can_to_qt_bolt3::gpio_msg::ConstPtr& msg)
{
  emit updateIGNOK((int)msg->IGNOK);
  emit updateIMD((int)msg->IMD);
  emit updatePRESSURE((int)msg->PRESSURE);
  emit updateBMSDE((int)msg->BMSDE);
}

