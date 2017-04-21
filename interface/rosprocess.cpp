#include "rosprocess.h"


#include "../shared_messages.h"

/*
 * GOAL:::
 *  Instantiate the QProcess pointing at the ROS executable
 *  When data become available from the process's stdout
 *  - or - when an error comes from the stderr, we want to
 *  interpret the message subject and value, then set a variable,
 *  and finally emit a signal from this thread to the main UI thread
 *
 *
 *  I made this a little complicated... we are starting a Qprocess from
 *  within a QThread. We are doing this because you cannot emit Qt signals
 *  from ROS code. This allows is to pull data from the ROS process then
 *  send that data to the UI itself.
*/


/*
 * DATA PARSING SCHEME :::
 *  normal CAN data to be sent out of the ROS process via
 *  stdout (...cout).
 *  format CAN stdout messages as: <CAN ID>;<CAN DATA>
 *
 *  CAN error messages to be sent over stderr from
 *  the ROS process. These are collected and parsed by
 *  a separate function.
 *  format CAN stderr messages as <ERROR ID>;<ERROR DATA>;<ERROR MESSAGE>
*/

RosProcess::RosProcess(QString path, QStringList args)
{
    m_processObj = new QProcess();
    m_processObj->setProgram(path);
    m_processObj->setArguments(args);

    // when data become available on stdout of the process, get the data
    connect(m_processObj,SIGNAL(readyReadStandardOutput()),this,SLOT(readData()));

    // look for info passed on stderr
    connect(m_processObj,SIGNAL(readyReadStandardError()),this,SLOT(readError()));

    m_processObj->start();
}


void RosProcess::readData()
{
    QByteArray data = m_processObj->readAllStandardOutput();
    // Now we parse the data and emit a signal ...
    parseData(data);
}

void RosProcess::readError()
{
    QByteArray data = m_processObj->readAllStandardError();
    // parse the data and take an action based on the error code...
}

void RosProcess::parseData(QByteArray data)
{

    QString allData = data;
    allData = allData.remove('\n');

    QStringList splitData = QString(allData).split(';');

    QString s_id = splitData.at(0);
    QString s_data = splitData.at(1);

    bool * ok = new bool;
    int ID = s_id.toInt(ok, 10); // CAN MESSAGE ID
    int can_data = s_data.toInt(ok, 10);

    // emit a signal based on the can id
    switch (ID)
    {
    case (TEMP_MOD_A):
        break;
    case (TEMP_MOD_B):
        break;
    case (TEMP_MOD_C):
        break;
    case (TEMP_GATE_DRIVER_BOARD):
        break;
    case(TEMP_CONTROL_BOARD):
        emit updateControllerTemp(can_data);
        break;
    case (MOTOR_TEMP):
        emit updateMotorTemp(can_data);
        break;
    case (REGEN_SIGNAL):
        break;
    case (MOTOR_ANGLE):
        break;
    case (MOTOR_SPEED):
        // convert to RPM, multiply by 60 seconds and divide by 2pi radians
        rpm = float(can_data) * (60.0 / 6.28);
        emit updateRPM(rpm);
        emit updateRPM(QVariant(rpm));
        break;
    case (RESOLVER_ANGLE):
        break;
    case (DC_CURRENT):
        emit updateDcCurrent(can_data);
        break;
    case (DC_VOLTAGE):
        break;
    case (OUTPUT_VOLTAGE):
        emit updateOutputVolts(can_data);
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
        break;
    case (INVERTER_STATE):
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
        emit updatePackCurrent(can_data);
        break;
    case (PACK_INST_VOLTAGE):
        emit updatePackVolts(can_data);
        break;
    case (PACK_TEMP_HIGH):
        emit updatePackTempHigh(can_data);
        break;
    case (PACK_TEMP_LOW):
        break;
    case (PACK_SOC):
        emit updateSOC(can_data);
        emit updateSOC(QVariant(can_data));
        break;
    // GPIO BELOW HERE
    case (gpio_IGNOK):
        emit updateIGNOK(can_data)
        break;
    case (gpio_IMD):
        emit updateIMD(can_data)
        break;
    case (gpio_PRESSURE):
        emit updatePRESSURE(can_data)
        break;
    case (gpio_BMSDE):
        emit updateBMSDE(can_data)
        break;
    default:
        break;
    }
}

void RosProcess::parseError()
{
    // For data coming in over stderr
}

