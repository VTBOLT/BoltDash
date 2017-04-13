#include "rosprocess.h"

#include <QTextStream>
QTextStream qCout (stdout);

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

// MESSAGE ID's --- consider putting these into a shared header file
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
// END ID's

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
    QStringList splitData = QString(data).split(';');
    QString s_id = splitData.at(0);
    QString s_data = splitData.at(1);

    bool * ok = 0;
    int ID = s_id.toInt(ok, 10); // CAN MESSAGE ID
    int can_data = s_data.toInt(ok, 10);

    qCout << "DATA: " << s_data << endl;

    switch (ID)
    {
    case (RPM):
        emit updateRPM(can_data);
        emit updateRPM_QVar( QVariant(can_data) );
        break;
    case (BATT_TEMP):
        emit updateBatteryTemp(can_data);
        break;
    case (RMS_CURRENT):
        emit updateRMScurr(can_data);
        break;
    case (DC_VOLTS):
        emit updateDCvolt(can_data);
        emit updateDCVolt_QVar( QVariant(can_data) );
        break;
    case (HS_TEMP):
        emit updateHStemp(can_data);
        break;
    case (MOTOR_TEMP):
        emit updateMotorTemp(can_data);
        break;
    case (VOLT_ANGLE):
        emit updateVoltAngle(can_data);
        break;
    case (IQ_CURRENT):
        emit updateIQcurr(can_data);
        break;
    case (EMCY6):
        break;
    case (EMCY7):
        break;
    case (D6_STAT):
        break;
    case (D7_STAT):
        break;
    }

}

void RosProcess::parseError()
{
    // TODO
}

