#include "cannode.h"

CanNode::CanNode()
{
    return;
}

void CanNode::run()
{
    struct canfd_frame message;

    char* argv2[2];
    argv2[0] = " ";
    argv2[1] = "can0";

    while (1)
    {
        //std::cout << "calling canreceive" << std::endl;
        message = canreceive(2, argv2);

        switch (message.can_id)
        {
        case 0xA0:
        {
            // TEMP MOD A
            if ((message.data[1] << 8 | message.data[0]) > max_rinehart_temp)
                max_rinehart_temp = (message.data[1] << 8 | message.data[0]);
            // TEMP MOD B
            else if ((message.data[3] << 8 | message.data[2]) > max_rinehart_temp)
                max_rinehart_temp =  (message.data[3] << 8 | message.data[2]);
            // TEMP MOD C
            else if ((message.data[5] << 8 | message.data[4]) > max_rinehart_temp)
                max_rinehart_temp =  (message.data[5] << 8 | message.data[4]);
            // TEMP GATE DRIVER BOARD
            else if ((message.data[7] << 8 | message.data[6]) > max_rinehart_temp)
                max_rinehart_temp =  (message.data[5] << 8 | message.data[4]);

            emit updateControllerTemp(max_rinehart_temp);
            break;
        }
        case 0xA1:
        {
            // TEMP CONTROL BOARD
            if ((message.data[1] << 8 | message.data[0]) > max_rinehart_temp)
                max_rinehart_temp = (message.data[1] << 8 | message.data[0]);

            emit updateControllerTemp(max_rinehart_temp);
            break;
        }
        case 0xA2:
        {
            // MOTOR TEMP
            emit updateMotorTemp((message.data[5] << 8 | message.data[4]));
            break;
        }
        case 0xA4:
        {
            // REGEN DISABLE
            //message.data[3]);
            break;
        }
        case 0xA5:
        {
            // MOTOR ANGLE
            // (message.data[1] << 8 | message.data[0]));
            // MOTOR SPEED
            emit updateRPM((message.data[3] << 8 | message.data[2]));
            emit updateRPM(QVariant(message.data[3] << 8 | message.data[2]));
            // RESOLVER ANGLE
            //(message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xA6:
        {
            // DC BUS CURRENT
            emit updateDcCurrent((message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xA7:
        {
            // DC BUS VOLTAGE
            //parseAndPubCAN(message.can_id, "DC_BUS_VOLTAGE", DC_BUS_VOLTAGE, (message.data[1] << 8 | message.data[0]));
            // OUTPUT VOLTAGE
            emit updateOutputVolts((message.data[3] << 8 | message.data[2]));
            // PHASE AB VOLTAGE
            //parseAndPubCAN(message.can_id, "PHASE_AB_VOLTAGE", PHASE_AB_VOLTAGE, (message.data[5] << 8 | message.data[4]));
            // PHASE BC VOLTAGE
            //parseAndPubCAN(message.can_id, "PHASE_BC_VOLTAGE", PHASE_BC_VOLTAGE, (message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xA8:
        {
            // ID FEEDBACK
            //parseAndPubCAN(message.can_id, "ID_FEEDBACK", ID_FEEDBACK, (message.data[5] << 8 | message.data[4]));
            // IQ FEEDBACK
            //parseAndPubCAN(message.can_id, "IQ_FEEDBACK", IQ_FEEDBACK, (message.data[7] << 8 | message.data[6]));
            break;
        }
        case 0xAA:
        {
            // VSM STATE
            emit updateRMSVSM((message.data[0] | message.data[1] << 8));
            // INVERTER STATE
            emit updateInverter(message.data[2]);
            break;
        }
        case 0xAB:
        {
            // FAULT MESSAGE
            //std::string fault = can_fault_code_fsm(message);
            break;
        }
        case 0xAC:
        {
            // COMMAND TORQUE
            //parseAndPubCAN(message.can_id, "COMMAND_TORQUE", COMMAND_TORQUE, (message.data[0] | message.data[1] << 8));
            // COMMAND FEEDBACK
            //parseAndPubCAN(message.can_id, "TORQUE_FEEDBACK", TORQUE_FEEDBACK, (message.data[3] | message.data[2] << 8));
            break;
        }
        case 0xAD:
        {
            // FLUX WEAK OUT
            //parseAndPubCAN(message.can_id, "FLUX_WEAK_OUT", FLUX_WEAK_OUT, (message.data[3] | message.data[2] << 8));
            break;
        }
        case 0xC0:
        {
            // SPEED CMD
            //parseAndPubCAN(message.can_id, "SPEED_CMD", SPEED_CMD, (message.data[3] | message.data[2] << 8));
            break;
        }
        // BMS MESSAGES
        case 0x183:
        {
            // PACK CCL
            //parseAndPubCAN(message.can_id, "PACK_CCL", PACK_CCL, (message.data[1] | message.data[0] << 8));
            // PACK DCL
            emit updatePackDCL((message.data[3] | message.data[2] << 8));
            // PACK SOC
            emit updateSOC((message.data[5] | message.data[4] << 8));
            emit updateSOC(int((message.data[5] | message.data[4] << 8)));
            // PACK CURRENT
            emit updatePackCurrent((message.data[7] | message.data[6] << 8));
            break;
        }
        case 0x181:
        {
            // PACK TEMP HIGH ID
            //parseAndPubCAN(message.can_id, "PACK_TEMP_HIGH_ID", PACK_TEMP_HIGH_ID, message.data[0]);
            // PACK TEMP HIGH
            emit updatePackTempHigh((message.data[2] | message.data[1] << 8));
            // PACK TEMP LOW ID
            //parseAndPubCAN(message.can_id, "PACK_TEMP_LOW_ID", PACK_TEMP_LOW_ID, message.data[3]);
            // PACK TEMP LOW
            //parseAndPubCAN(message.can_id, "PACK_TEMP_LOW", PACK_TEMP_LOW, (message.data[5] | message.data[4] << 8));
            // BMS TEMP
            //parseAndPubCAN(message.can_id, "BMS_TEMP", BMS_TEMP, (message.data[7] | message.data[6] << 8));
            break;
        }
        case 0x180:
        {
            // CELL VOLT HIGH ID
            emit updateCellVoltHighID(message.data[0]);
            // CELL VOLT HIGH
            emit updateCellVoltHigh((message.data[2] | message.data[1] << 8));
            // CELL VOLT LOW ID
            emit updateCellVoltLowID(message.data[3]);
            // CELL VOLT LOW
            emit updateCellVoltLow((message.data[5] | message.data[4] << 8));
            // PACK INST VOLTAGE
            emit updatePackVolts((message.data[7] | message.data[6] << 8));
            break;
        }
        }
    }
}
