// previously rosprocess.h

#ifndef DATA_NODE_H
#define DATA_NODE_H

#include <QVariant>
#include <QThread>
#include <QTextStream>
#include <ros/ros.h>
#include <ros/master.h>
#include <ros/node_handle.h>

#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int16.h"

// TODO : Fix cmakelists so this works how it's supposed to
#include "can_msg.h"
#include "fault_msg.h"
#include "gpio_msg.h"


class DataNode : public QThread
{
    Q_OBJECT
public:
    DataNode();

private:
    ros::NodeHandle n;
    ros::Publisher listener;
    ros::Subscriber sub1;
    ros::Subscriber sub2;
    ros::Subscriber gpio;
    int cell_high = 0, cell_low = 0;
    int max_rinehart_temp = 0;
    
    void run();
    void chatterCallback_can_msg(const can_to_qt_bolt3::can_msg::ConstPtr& msg);
    void chatterCallback_fault_msg(const can_to_qt_bolt3::fault_msg::ConstPtr& msg);
    void gpio_callback(const can_to_qt_bolt3::gpio_msg::ConstPtr& msg);

Q_SIGNALS:
	void updateRPM(double rpm);
    void updateRPM(const QVariant & rpm);
    void updateSOC(double volt);
    void updateMotorTemp(double temp);
    void updateDcCurrent(double current);
    void updateOutputVolts(double volts);
    void updatePackVolts(double volts);
    void updatePackCurrent(double current);
    void updatePackTempHigh(double temp);
    void updateDelta(double delta);
    void updateControllerTemp(double temp);
    void updateRmsCurrent(double rms);
    void updateFieldWeakening(double angle);
    void updateIGNOK(int state);
    void updateIMD(int state);
    void updatePRESSURE(int state);
    void updateBMSDE(int state);
    void updateFAULT(int value);
    void updateRMSVSM(int value);
    void updateInverter(int value);
    void updateCellVoltHigh(int value);
    void updateCellVoltLow(int value);
    void updateCellVoltHighID(int value);
    void updateCellVoltLowID(int value);
    void updatePackDCL(int value);
};

#endif //DATA_NODE_H
