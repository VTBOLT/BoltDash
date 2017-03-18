/* AUTO GENERATED FILE  - has been updated*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

//QTextStream qCout(stdout);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // show start up steps here ???

    // ??

    // instantiate the UI defined in Qt Creator
    ui->setupUi(this);
    // load QML for race view from source
    loadQML();
    // instantiate the can thread
    QString path = "rosrun";
    QStringList args;
    args << "backend" << "listener2";
    ros_process = new RosProcess(path,args);
    //ros_process->start();
    // connect can signals to debug view
    connectDebugSlots();
    // connect 'clicked' signals to button actions
    connectNavSlots();
    // connect signals from can to race view
    connectRaceSlots();
    // spin off the can thread
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadQML()
{
    ui->qmlRace->setSource(QUrl("../interface/Race_view.qml"));
}

void MainWindow::connectDebugSlots()
{
    // signals comes in from 'can' object, calls slot implemented in UI
    connect(ros_process, SIGNAL( updateRPM(double)), ui->rpm_lcd,SLOT(display(double)));
    connect(ros_process, SIGNAL( updateBatteryTemp(int)), ui->battTemp_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( updateRMScurr(int)), ui->rms_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( updateDCvolt(double)), ui->dc_lcd,SLOT(display(double)));
    connect(ros_process, SIGNAL( updateHStemp(int)), ui->hs_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( updateMotorTemp(int)), ui->motorTemp_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( updateVoltAngle(int)), ui->angle_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( updateIQcurr(int)), ui->iq_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( sendEMCY6(int)), ui->emcy6_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( sendEMCY7(int)), ui->emcy7_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( sendD6stat(int)), ui->drive6_lcd,SLOT(display(int)));
    connect(ros_process, SIGNAL( sendD7stat(int)), ui->drive7_lcd,SLOT(display(int)));
}

void MainWindow::connectRaceSlots()
{
    //QObject * qmlObject = ui->qmlRace->rootObject();
    //connect(can, SIGNAL(updateRPM_QVar(QVariant)), qmlObject, SLOT(qmlSlot(QVariant)));
    // set text for testing purposes only
    connect(ros_process, SIGNAL(updateRPM_QVar(QVariant)), this, SLOT(setRPM(QVariant)));
    connect(ros_process, SIGNAL(updateDCVolt_QVar(QVariant)), this, SLOT(setBatteryPercent(QVariant)));
}

void MainWindow::setRPM(QVariant rpm)
{
    QObject * rootObject = ui->qmlRace->rootObject();
    float angle = rpm.toFloat() * (180.0/8000.0);
    rootObject->setProperty("myRot", QVariant(angle));
}

void MainWindow::setBatteryPercent(QVariant value)
{
    QObject * rootObject = ui->qmlRace->rootObject();
    // convert value to a percentage of the rectangle's width...
    rootObject->setProperty("green_bar", QVariant(value));
}

void MainWindow::connectNavSlots()
{
    QObject * qmlObject = ui->qmlRace->rootObject();
    //connect(ui->toDebugButton,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(qmlObject, SIGNAL(toDebugSignal()), this, SLOT(toDebugView()));
    connect(ui->toRaceButton,SIGNAL(clicked(bool)),this,SLOT(toRaceView()));
}

void MainWindow::toDebugView()
{
    ui->views->setCurrentIndex(DEBUG);
}

void MainWindow::toRaceView()
{
    ui->views->setCurrentIndex(RACE);
}
