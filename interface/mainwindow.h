
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 'page' numbers
#define STARTUP 0
#define RACE    1
#define DEBUG   2
#define VOLTAGE 3

#include <QMainWindow>
#include <QWidget>
#include <QUrl>
#include <QQuickItem>
#include <QTextStream>

#include "rosprocess.h"
#include "../shared_messages.h"

struct gpio_values{
    bool BMSDE;
    bool ACC;
    bool RMS;
    bool PRECHARGE;
    bool MOTOR;
    bool IGNOK;
    bool IMD;
    bool PRESSURE;
};



namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    gpio_values gpio;

    enum state_option{
        fault = -1,
        off,
        bms,
        acc,
        rms,
        precharging,
        motor
    };


    Ui::MainWindow *ui;
    RosProcess * ros_process;

    void loadQML();

    void connectDebugSlots();
    void connectRaceSlots();
    void connectNavSlots();
    void connectStartupSlots();
    void startup();
    int getState();
    void setState(int value, int fault_state=0);
    bool getIGNOK();
    bool getIMD();
    bool getPRESSURE();
    bool getBMSDE();
    int getRMSVSM();
    int getFAULT();

    int state = 0;
    // this was recently renamed, check refactor for rename
    int fault_code = 0;

    // rms_vsm_state
    // 0 VSM Start State
    // 1 pre-charge init State
    // 2 pre-charge active state
    // 3 pre-charge complete state
    // 4 vsm wait state
    // 5 vsm ready state
    // 6 motor running state
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

private slots:
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
    void setIGNOK(bool value);
    void setIMD(bool value);
    void setPRESSURE(bool value);
    void setBMSDE(bool value);
    void setFAULT(int value);
    void setRMSVSM(int value);

    void on_exitButton_clicked();

signals:
    void stateSet();
};

#endif // MAINWINDOW_H
