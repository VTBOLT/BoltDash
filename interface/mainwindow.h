
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
    Ui::MainWindow *ui;
    RosProcess * ros_process;

    void loadQML();

    void connectDebugSlots();
    void connectRaceSlots();
    void connectNavSlots();
    void connectStartupSlots();
    void startup();
    int getState();
    void setState(int);
    bool getIGNOK();
    bool getIMD();
    bool getPRESSURE();
    bool getBMSDE();
    


    enum state(fault = -1, off, bms, acc, rms, precharging, motor);
    struct gpio{
        bool BMSDE;
        bool ACC; 
        bool RMS;
        bool PRECHARGE;
        bool MOTOR;
        bool IGNOK;
        bool IMD;
        bool PRESSURE;
        
    };

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
    void setIGNOK(bool);
    void setIMD(bool);
    void setPRESSURE(bool);
    void setBMSDE(bool);


    void on_exitButton_clicked();
};

#endif // MAINWINDOW_H
