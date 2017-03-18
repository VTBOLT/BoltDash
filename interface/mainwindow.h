/* AUTO GENERATED FILE - has been modified */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 'page' numbers
#define RACE    0
#define DEBUG   1

#include <QMainWindow>
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

private slots:
    void setRPM(QVariant rpm);
    void toDebugView();
    void toRaceView();
    void setBatteryPercent(QVariant value);
};

#endif // MAINWINDOW_H
