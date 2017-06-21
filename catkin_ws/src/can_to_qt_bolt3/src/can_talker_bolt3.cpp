#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Int16.h"

#include "canreceive.cpp"
#include "shared_messages.h"

//ROS topic message declerations
#include "can_msg.h"
#include "fault_msg.h"
#include "can_fault_code_fsm.cpp"

#include <iostream>
#include <string>

// !!! Moving these here could have caused scope issues, need to test !!!
ros::NodeHandle n;
ros::Publisher topic_can_msg = n.advertise<can_to_qt_bolt3::can_msg>("can_msg", 1000);
ros::Publisher topic_fault_msg = n.advertise<can_to_qt_bolt3::fault_msg>("fault_msg", 1000);

void parseAndPubCAN(short id, std::string name, short define, short data)
{
    // build the can_msg 
    can_to_qt_bolt3::can_msg can_msg;

    can_msg.can_id   = id;
    can_msg.name     = name;
    can_msg.define   = define;
    can_msg.can_data = data;

    // Publish
    topic_can_msg.publish(can_msg);
    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "can_talker_bolt3");

    ros::Rate loop_rate(1000);
    struct canfd_frame message;
    char* argv2[2];

    argv2[0] = " ";
    argv2[1] = "can0";
    int count = 0;

    while (ros::ok())
    {
        // std::cout << "while loop" << std::endl;
        std::string name;
        std::string data_s;
        signed short data = 0;
        std::string fault;

        can_to_qt_bolt3::can_msg can_msg;
        can_to_qt_bolt3::fault_msg fault_msg;

        //std::cout << "calling canreceive" << std::endl;
        message = canreceive(2, argv2, std::cin);

        switch (message.can_id)
        {
        case 0xA0:
        {
            parseAndPubCAN(message.can_id, "TEMP_MOD_A", TEMP_MOD_A, (message.data[1] << 8 | message.data[0]));
            parseAndPubCAN(message.can_id, "TEMP_MOD_B", TEMP_MOD_B, (message.data[3] << 8 | message.data[2]));
            parseAndPubCAN(message.can_id, "TEMP_MOD_C", TEMP_MOD_C, (message.data[5] << 8 | message.data[4]));
            parseAndPubCAN(message.can_id, "TEMP_GATE_DRIVER_BOARD", TEMP_GATE_DRIVER_BOARD, (message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xA1:
        {
            parseAndPubCAN(message.can_id, "TEMP_CONTROL_BOARD", TEMP_CONTROL_BOARD, (message.data[1] << 8 | message.data[0]));
            break;
        }
        case 0xA2:
        {
            parseAndPubCAN(message.can_id, "MOTOR_TEMP", MOTOR_TEMP, (message.data[5] << 8 | message.data[4]));
            break;
        }
        case 0xA4:
        {
            parseAndPubCAN(message.can_id, "REGEN_DISABLE", REGEN_DISABLE, message.data[3]);
            break;
        }
        case 0xA5:
        {
            parseAndPubCAN(message.can_id, "MOTOR_ANGLE", MOTOR_ANGLE, (message.data[1] << 8 | message.data[0]));
            parseAndPubCAN(message.can_id, "MOTOR_SPEED", MOTOR_SPEED, (message.data[3] << 8 | message.data[2]));
            parseAndPubCAN(message.can_id, "RESOLVER_ANGLE", RESOLVER_ANGLE, (message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xA6:
        {
            parseAndPubCAN(message.can_id, "DC_BUS_CURRENT", DC_BUS_CURRENT, (message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xA7:
        {
            parseAndPubCAN(message.can_id, "DC_BUS_VOLTAGE", DC_BUS_VOLTAGE, (message.data[1] << 8 | message.data[0]));
            parseAndPubCAN(message.can_id, "OUTPUT_VOLTAGE", OUTPUT_VOLTAGE, (message.data[3] << 8 | message.data[2]));
            parseAndPubCAN(message.can_id, "PHASE_AB_VOLTAGE", PHASE_AB_VOLTAGE, (message.data[5] << 8 | message.data[4]));
            parseAndPubCAN(message.can_id, "PHASE_BC_VOLTAGE", PHASE_BC_VOLTAGE, (message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xA8:
        {
            parseAndPubCAN(message.can_id, "ID_FEEDBACK", ID_FEEDBACK, (message.data[5] << 8 | message.data[4]));
            parseAndPubCAN(message.can_id, "IQ_FEEDBACK", IQ_FEEDBACK, (message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xAA:
        {
            parseAndPubCAN(message.can_id, "VSM_STATE", VSM_STATE, (message.data[0] | message.data[1] << 8));
            parseAndPubCAN(message.can_id, "INVERTER_STATE", INVERTER_STATE, message.data[2]);
            break;
        }
        case 0xAB:
        {
            // FAULT MESSAGE
            fault_msg.can_id = message.can_id;
            std::string fault = can_fault_code_fsm(message);
            fault_msg.msg_data = fault;
            topic_can_msg.publish(can_msg);
            ROS_INFO("FAULT name: %s, can_id [%i], fault: %s", can_msg.name.c_str(), can_msg.can_id, fault.c_str());
            break;
        }
        case 0xAC:
        {
            parseAndPubCAN(message.can_id, "COMMAND_TORQUE", COMMAND_TORQUE, (message.data[0] | message.data[1] << 8));
            parseAndPubCAN(message.can_id, "TORQUE_FEEDBACK", TORQUE_FEEDBACK, (message.data[3] | message.data[2] << 8));
            break;
        }
        case 0xAD:
        {
            parseAndPubCAN(message.can_id, "FLUX_WEAK_OUT", FLUX_WEAK_OUT, (message.data[3] | message.data[2] << 8));
            break;
        }
        case 0xC0:
        {
            parseAndPubCAN(message.can_id, "SPEED_CMD", SPEED_CMD, (message.data[3] | message.data[2] << 8));
            break;
        }
        // BMS MESSAGES
        case 0x183:
        {
            parseAndPubCAN(message.can_id, "PACK_CCL", PACK_CCL, (message.data[1] | message.data[0] << 8));
            parseAndPubCAN(message.can_id, "PACK_DCL", PACK_DCL, (message.data[3] | message.data[2] << 8));
            parseAndPubCAN(message.can_id, "PACK_SOC", PACK_SOC, (message.data[5] | message.data[4] << 8));
            parseAndPubCAN(message.can_id, "PACK_CURRENT", PACK_CURRENT, (message.data[7] | message.data[6] << 8));
            break;
        }
        case 0x181:
        {
            parseAndPubCAN(message.can_id, "PACK_TEMP_HIGH_ID", PACK_TEMP_HIGH_ID, message.data[0]);
            parseAndPubCAN(message.can_id, "PACK_TEMP_HIGH", PACK_TEMP_HIGH, (message.data[2] | message.data[1] << 8));
            parseAndPubCAN(message.can_id, "PACK_TEMP_LOW_ID", PACK_TEMP_LOW_ID, message.data[3]);
            parseAndPubCAN(message.can_id, "PACK_TEMP_LOW", PACK_TEMP_LOW, (message.data[5] | message.data[4] << 8));
            parseAndPubCAN(message.can_id, "BMS_TEMP", BMS_TEMP, (message.data[7] | message.data[6] << 8));
            break;
        }
        case 0x180:
        {
            parseAndPubCAN(message.can_id, "CELL_VOLT_HIGH_ID", CELL_VOLT_HIGH_ID, message.data[0]);
            parseAndPubCAN(message.can_id, "CELL_VOLT_HIGH", CELL_VOLT_HIGH, (message.data[2] | message.data[1] << 8));
            parseAndPubCAN(message.can_id, "CELL_VOLT_LOW_ID", CELL_VOLT_LOW_ID, message.data[3]);
            parseAndPubCAN(message.can_id, "CELL_VOLT_LOW", CELL_VOLT_LOW, (message.data[5] | message.data[4] << 8));
            parseAndPubCAN(message.can_id, "PACK_INST_VOLTAGE", PACK_INST_VOLTAGE, (message.data[7] | message.data[6] << 8));
            break;
        }
        }

        /* #### OLD CODE #### */
        // case 0x03B:
        // {
        //  can_msg.can_id = message.can_id;
        //  data = (message.data[0]);
        //  can_msg.name = "PACK_CURRENT";
        //  can_msg.can_data = data;
        //  can_msg.define = PACK_CURRENT;
        //  topic_can_msg.publish(can_msg);
        //  ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);
        //  data = (message.data[2]);
        //  can_msg.name = "PACK_INST_VOLTAGE";
        //  can_msg.can_data = data;
        //  can_msg.define = PACK_INST_VOLTAGE;
        //  topic_can_msg.publish(can_msg);
        //  ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);
        //  break;
        // }
        // case 0x3CB:
        // {
        //  can_msg.can_id = message.can_id;
        //  data = (message.data[4]);
        //  can_msg.name = "PACK_TEMP_HIGH";
        //  can_msg.can_data = data;
        //  can_msg.define = PACK_TEMP_HIGH;
        //  topic_can_msg.publish(can_msg);
        //  ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);

        //  data = (message.data[5]);
        //  can_msg.name = "PACK_TEMP_LOW";
        //  can_msg.can_data = data;
        //  can_msg.define = PACK_TEMP_LOW;
        //  topic_can_msg.publish(can_msg);
        //  ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);
        //  break;
        // }
        // case 0x6B2:
        // {
        //  can_msg.can_id = message.can_id;
        //  data = (message.data[1]);
        //  can_msg.name = "PACK_SOC";
        //  can_msg.can_data = data;
        //  can_msg.define = PACK_SOC;
        //  topic_can_msg.publish(can_msg);
        //  ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);
        //  break;
        // }
        // case 0x123:
        // {
        //  can_msg.can_id = message.can_id;
        //  data = (message.data[1]);
        //  can_msg.name = "GORDON_TEST";
        //  can_msg.can_data = data;
        //  can_msg.define = PACK_SOC;
        //  topic_can_msg.publish(can_msg);
        //  ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);
        //  break;
        // }
        // case 0x36:
        // {
        //  can_msg.can_id = message.can_id;
        //  data = (message.data[1]);
        //  can_msg.name = "Cell Voltage";
        //  can_msg.can_data = data;
        //  can_msg.define = PACK_SOC;
        //  topic_can_msg.publish(can_msg);
        //  ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name.c_str(), can_msg.can_id, can_msg.can_data);
        //  break;
        // }
        // }

        // if (count > 10000){
        //  exit(0);
        // }
        // else{
        //  count++;
        // }

        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}
