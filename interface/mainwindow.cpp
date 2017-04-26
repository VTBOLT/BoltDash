
#include "mainwindow.h"
#include "ui_mainwindow.h"

QTextStream qCout(stdout);

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
    args << "can_to_qt_bolt3" << "can_listener_bolt3";
    ros_process = new RosProcess(path,args);

    // connect can signals to debug view
    connectDebugSlots();
    // connect 'clicked' signals to button actions
    connectNavSlots();
    // connect signals from can to race view
    connectRaceSlots();
    // connect strtup slots
    connectStartupSlots();

    startup();
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
    connect(ros_process, SIGNAL( updateSOC(double)), ui->lcdSOC, SLOT(display(double)));
    connect(ros_process, SIGNAL( updateDelta(double)), ui->lcdDelta_2, SLOT(display(double)));
    connect(ros_process, SIGNAL( updateControllerTemp(double)), ui->lcdControllerTemp, SLOT(display(double)));
    connect(ros_process, SIGNAL( updateRmsCurrent(double)), ui->lcdRmsCurrent, SLOT(display(double)));
    connect(ros_process, SIGNAL( updateFieldWeakening(double)), ui->lcdFieldWeakening, SLOT(display(double)));
}

void MainWindow::connectRaceSlots()
{
    connect(ros_process, SIGNAL(updateRPM(QVariant)), this, SLOT(setRPM(QVariant)));
    connect(ros_process, SIGNAL(updateSOC(QVariant)), this, SLOT(setBatteryPercent(QVariant)));
}

void MainWindow::connectStartupSlots()
{
    connect(ros_process, SIGNAL(updateIGNOK(int)), this, SLOT(setIGNOK(int)));
    connect(ros_process, SIGNAL(updateIMD(int)), this, SLOT(setIMD(int)));
    connect(ros_process, SIGNAL(updatePRESSURE(int)), this, SLOT(setPRESSURE(int)));
    connect(ros_process, SIGNAL(updateBMSDE(int)), this, SLOT(setBMSDE(int)));
    connect(ui->step1, SIGNAL(clicked(int)), this, SLOT(showStartupOne()));
    connect(ui->step2, SIGNAL(clicked(int)), this, SLOT(showStartupTwo()));
    connect(ui->step3, SIGNAL(clicked(int)), this, SLOT(showStartupThree()));
    connect(ui->step4, SIGNAL(clicked(int)), this, SLOT(showStartupFour()));
    connect(ui->step0, SIGNAL(clicked(int)), this, SLOT(showStartupZero()));
    connect(ui->startupToRace, SIGNAL(clicked(int)), this, SLOT(toRaceView()));
    connect(ui->startupToDebug, SIGNAL(clicked(int)), this, SLOT(toDebugView()));

    connect(this, SIGNAL( stateSet()), this, SLOT(startup()));
    connect(ros_process, SIGNAL( updateRMSVSM(int)), this, SLOT(setRMSVSM(int)));
    connect(ros_process, SIGNAL( updateInverter(int)), this, SLOT(setInverter(int)));
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
    //connect(ui->toDebugButton,SIGNAL(clicked(int)),this,SLOT(toDebugView()));
    connect(qmlObject, SIGNAL(toDebugSignal()), this, SLOT(toDebugView()));
    connect(ui->toRaceButton,SIGNAL(clicked(int)),this,SLOT(toRaceView()));
    connect(ui->toDebugButton,SIGNAL(clicked(int)),this,SLOT(toDebugView()));
    connect(ui->toVoltageButton,SIGNAL(clicked(int)),this,SLOT(toVoltageView()));
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

void MainWindow::showStartupFour()
{
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_4.png)0 0 0 0 stretch stretch; background-repeat: none");
}

// Set Methods

void MainWindow::setIGNOK(int state){
    if(state == 0 || state == 1){
        gpio.IGNOK = state;
        qCout << "set ignok: " << gpio.IGNOK << endl;
        MainWindow::startup();
    } else{
        qCout << "fault ignok: " << state << endl;
    }
}
void MainWindow::setIMD(int state){
    if(state == 0 || state == 1){
        gpio.IMD = state;
        qCout << "set imd: " << gpio.IMD << endl;
        MainWindow::startup();    
    } else{
        qCout << "fault imd: " << state << endl;
    }
    
}
void MainWindow::setPRESSURE(int state){
    if(state == 0 || state == 1){
        gpio.PRESSURE = state;
        qCout << "set pressure: " << gpio.PRESSURE << endl;
        MainWindow::startup();
    } else{
        qCout << "fault pressure: " << state << endl;
    }
}
void MainWindow::setBMSDE(int state){
    if(state == 0 || state == 1){
        gpio.BMSDE = state;
        qCout << "set bmsde: " << gpio.BMSDE << endl;
        MainWindow::startup();
    } else{
        qCout << "fault bmsde: " << state << endl;
    }
}

void MainWindow::setRMSVSM(int value){
    if(state == 0 || state == 1){
        rms_vsm_state = value;
        qCout << "set RMS VSM State: " << rms_vsm_state << endl;
        MainWindow::startup();
    }
}

void MainWindow::setInverter(int value){
    rms_inverter_state = value;
    MainWindow::startup();
}

void MainWindow::setState(int set_state, int fault_value){
    state = set_state;
    // if(state == -1){
    //     MainWindow::setFAULT(fault_value);
    // }
    emit stateSet();
}

void MainWindow::setFAULT(int value){
    qCout << "FAULT SET " << value << endl;
    fault_code = value;
    MainWindow::startup();
}

// Get Methods

int MainWindow::getIGNOK(){
    qCout << "ignok: " << gpio.IGNOK << endl;
    return gpio.IGNOK;
}
int MainWindow::getIMD(){
    qCout << "imd: " << gpio.IMD << endl;
    return gpio.IMD;
}
int MainWindow::getPRESSURE(){
    qCout << "pressure: " << gpio.PRESSURE << endl;
    return gpio.PRESSURE;
}
int MainWindow::getBMSDE(){
    qCout << "bmsde: " << gpio.BMSDE << endl;
    return gpio.BMSDE;
}

int MainWindow::getState(){
    qCout << "State is " << state << endl;
    qCout << "RMSVSM is " << MainWindow::getRMSVSM() << endl;
    return state;
}

int MainWindow::getFAULT(){
    return fault;
}

int MainWindow::getRMSVSM(){
    return rms_vsm_state;
}


void MainWindow::startup(){
    // Possibly need to change this from a switch into a bunch of signals and slots
    // Easier to establish entire state machine at first test this way
    switch(getState())
    {
        case (state_option::fault):
            //Show fault screen
            MainWindow::getFAULT();
            //Determine what to do next
            break;
        case (state_option::off):
            // Show BOLT Logo
            MainWindow::showStartupZero();
            // Check CAN BMS State, no fault
            if(fault_code == 0){
                // set state bms
                MainWindow::setState(state_option::bms);
            }
            break;
        case (state_option::bms):
            // Show Turn On ACC
            MainWindow::showStartupOne();
            // Check PRESSURE && IMD
            if(MainWindow::getPRESSURE() == 1 && MainWindow::getIMD() == 1){
                // Show Turn on ACC
                MainWindow::showStartupTwo();
                MainWindow::setState(state_option::acc);
            }
            break;
        case (state_option::acc):
            // Check IGN && CAN RMS On
            if(MainWindow::getIGNOK() == 1 && MainWindow::getRMSVSM() > 1){
                // Set State RMS
                MainWindow::setState(state_option::rms);
            } else if(MainWindow::getRMSVSM() != 0 || MainWindow::getRMSVSM() !=1){
                qCout << "RMS VSM State: " << MainWindow::getRMSVSM() << endl;
            }                
            break;
        case (state_option::rms):
            // check rms vsm message. bytes 0 and 1. for precharge started
            if(MainWindow::getRMSVSM() >= 2){
                // Show Precharging
                MainWindow::showStartupThree();
            }            
            break;
        case (state_option::precharging):
            // Check CAN RMS VSM State Byte 0 and 1 of CAN Message for complete
            if(MainWindow::getRMSVSM() == 5){
                // Show Press Start when complete
                MainWindow::showStartupFour();
            }
            break;
        case (state_option::motor):
            MainWindow::toRaceView();
            // Check CAN RMS VSM State Byte 0 and 1, for when motor ready
//            if(MainWindow::ready){
                // Show Select Debug or Race when motor is on
                // MainWindow::showSelection();
//            }
            break;
        default:
            break;
    }
}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}
