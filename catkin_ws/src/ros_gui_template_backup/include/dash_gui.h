//
// dash_gui.h
//
// Created: 27 Feb 2017
// Author: Adam Plowcha

#ifndef __ROS_GUI_TEMPLATE_H__
#define __ROS_GUI_TEMPLATE_H__


#include <pluginlib/class_list_macros.h>
#include <rqt_gui_cpp/plugin.h>
#include <ui_dash_gui.h>

#include <QWidget>
#include <QStringList>
#include <QOpenGLWidget>
#include <QUrl>
#include <QQuickItem>
#include <QQuickWidget>
#include <QTextStream>

#include "data_node.h"


namespace dash_gui {
//constants can go here if needed

// 'page' numbers
#define STARTUP 0
#define RACE    1
#define DEBUG   2
#define VOLTAGE 3

struct gpio_values{
    int BMSDE = 0;
    int IGNOK = 0;
    int IMD = 0;
    int PRESSURE = 0;
};


class DashGui : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    DashGui();
    virtual ~DashGui();
    virtual void initPlugin(qt_gui_cpp::PluginContext &context);

Q_SIGNALS:
    void stateSet();
    void updateState();

private Q_SLOTS:
    void setRPM(QVariant rpm);
    void toDebugView();
    void toRaceView();
    void toVoltageView();
    void toStartupScreen();
    void setBatteryPercent(QVariant value);
    void showStartupZero();
    void showStartupOne();
    void showStartupTwo();
    void showStartupThree();
    void showStartupFour();
    void setIGNOK(int value);
    void setIMD(int value);
    void setPRESSURE(int value);
    void setBMSDE(int value);
    void setFAULT(int value);
    void setRMSVSM(int value);
    void setInverter(int value);
    int getState();

    void on_exitButton_clicked();

private:
    Ui::DashGuiWidget ui_;
    QWidget *widget_;
    DataNode * datanode;
    void testOut(const std_msgs::String::ConstPtr &msg);

    gpio_values gpio_value;

    enum state_option{
        fault = -1,
        off, // Default State before checking for faults
        aux, // If not faults exist, bms should be powered
        acc, // Pressure == 1, IMD == 1, 
        ign, // RMS == 0
        precharge, // precharging
        start, // Waiting for start
        throttle, // Throttle is active
    };
    
    void loadQML();
    void connectDebugSlots();
    void connectRaceSlots();
    void connectNavSlots();
    void connectStartupSlots();
    void setState(int value, int fault_state=0);
    int getIGNOK();
    int getIMD();
    int getPRESSURE();
    int getBMSDE();
    int getRMSVSM();
    int getFAULT();

    int state = -2;
    
    int fault_code = 0;

    // rms_vsm_state
    // 0 VSM Start State
    // 1 pre-charge init State
    // 2 pre-charge active state
    // 3 pre-charge complete state
    // 4 vsm wait state
    // 5 vsm ready state
    // 6 motor running state
    // 7 blink fault code state
    // 14 shutdown in process - in key switch mode 1, user has turned the key switch to off position
    // 15 recycle power state - user must recycle power when the unit is in this state (Believe that means restart)
    int rms_vsm_state = -1;

    //rms_inverter_state
    // 0 power on state
    // 1 stop state
    // 2 open loop state
    // 3 closed loop state
    // 4 wait state
    // 5, 6, 7 internal
    // 8 idle run state
    // 9 idle stop state
    // 10,11,12 internal
    int rms_inverter_state = -1;

    // Inverter Enable State
    // 0 Inverter is disabled
    // 1 Inverter is enabled
    int rms_inverter_enable = -1;

};
}

#endif /* __ROS_GUI_TEMPLATE_H__ */
