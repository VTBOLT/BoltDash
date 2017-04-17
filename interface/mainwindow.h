/* AUTO GENERATED FILE - has been modified */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 'page' numbers
#define STARTUP 0
#define RACE    1
#define DEBUG   2

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

private slots:
    void setRPM(QVariant rpm);
    void toDebugView();
    void toRaceView();
    void toStartupScreen();
    void setBatteryPercent(QVariant value);
    void showStartupZero();
    void showStartupOne();
    void showStartupTwo();
    void showStartupThree();
    void on_exitButton_clicked();
    void activateRedAlertScreen();
};

#endif // MAINWINDOW_H
