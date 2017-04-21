
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
    int getState();

    enum state(fault = -1, off, bms, acc, rms, precharge, motor);

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
    void on_exitButton_clicked();
};

#endif // MAINWINDOW_H
