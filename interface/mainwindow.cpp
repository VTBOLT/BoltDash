
#include "mainwindow.h"
#include "ui_mainwindow.h"

//QTextStream qCout(stdout);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // instantiate the UI defined in Qt Creator
    ui->setupUi(this);
    // load QML for race view from source
    loadQML();

    // instantiate the can thread
    QString path = "rosrun";
    QStringList args;
    args << "backend" << "can_listener_bolt2";
    ros_process = new RosProcess(path,args);

    // connect can signals to debug view
    connectDebugSlots();
    // connect 'clicked' signals to button actions
    connectNavSlots();
    // connect signals from can to race view
    connectRaceSlots();
    // connect strtup slots
    connectStartupSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadQML()
{
    ui->qmlRace->setSource(QUrl("qrc:///Race_view.qml"));
}

void MainWindow::connectDebugSlots()
{
    // signals comes in from 'ros_process' object, calls slot implemented in UI
    connect(ros_process, SIGNAL( updateRPM(double)), ui->lcdRPM, SLOT(display(double)));
    connect(ros_process, SIGNAL( updateMotorTemp(double)), ui->lcdMotorTemp, SLOT(display(double)));
    connect(ros_process, SIGNAL( updatePackVolts(double)), ui->lcdPackVoltage, SLOT(display(double)));
    connect(ros_process, SIGNAL( updateOutputVolts(double)), ui->lcdOutputVoltage, SLOT(display(double)));
    connect(ros_process, SIGNAL( updateDcCurrent(double)), ui->lcdDCCurrent, SLOT(display(double)));
    connect(ros_process, SIGNAL( updatePackCurrent(double)), ui->lcdPackCurrent, SLOT(display(double)));
    connect(ros_process, SIGNAL( updatePackTempHigh(double)), ui->lcdPackTempHigh, SLOT(display(double)));
}

void MainWindow::connectRaceSlots()
{
    connect(ros_process, SIGNAL(updateRPM(QVariant)), this, SLOT(setRPM(QVariant)));
    connect(ros_process, SIGNAL(updateSOC(QVariant)), this, SLOT(setBatteryPercent(QVariant)));
}

void MainWindow::connectStartupSlots()
{
    connect(ui->step1, SIGNAL(clicked(bool)), this, SLOT(showStartupOne()));
    connect(ui->step2, SIGNAL(clicked(bool)), this, SLOT(showStartupTwo()));
    connect(ui->step3, SIGNAL(clicked(bool)), this, SLOT(showStartupThree()));
    connect(ui->step0, SIGNAL(clicked(bool)), this, SLOT(showStartupZero()));
    connect(ui->startupToRace, SIGNAL(clicked(bool)), this, SLOT(toRaceView()));
    connect(ui->startupToDebug, SIGNAL(clicked(bool)), this, SLOT(toDebugView()));
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
    connect(ui->toDebugButton,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(ui->toVoltageButton,SIGNAL(clicked(bool)),this,SLOT(toVoltageView()));
}

void MainWindow::toDebugView()
{
    ui->views->setCurrentIndex(DEBUG);
}

void MainWindow::toRaceView()
{
    ui->views->setCurrentIndex(RACE);
}

void MainWindow::toVoltageView()
{
    ui->views->setCurrentIndex(VOLTAGE);
}

void MainWindow::toStartupScreen()
{
    ui->views->setCurrentIndex(STARTUP);
}

void MainWindow::showStartupZero()
{

    ui->startupFrame->setStyleSheet("QWidget {border-image:url(:/images/startup_0.png)0 0 0 stretch stretch; background-repeat: none;}" );
}

void MainWindow::showStartupOne()
{
    ui->startupFrame->setStyleSheet("QWidget{ border-image:url(:/images/startup_1.png) 0 0 0 0 stretch stretch; background-repeat: none;}");
}

void MainWindow::showStartupTwo()
{
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_2.png)0 0 0 0 stretch stretch; background-repeat: none");
}

void MainWindow::showStartupThree()
{
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_3.png)0 0 0 0 stretch stretch; background-repeat: none");

}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}
