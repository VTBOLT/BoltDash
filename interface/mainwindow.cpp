
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
    connect(this, SIGNAL( updateState()), this, SLOT(getState()));
    connect(ros_process, SIGNAL(updateIGNOK(int)), this, SLOT(setIGNOK(int)));
    connect(ros_process, SIGNAL(updateIMD(int)), this, SLOT(setIMD(int)));
    connect(ros_process, SIGNAL(updatePRESSURE(int)), this, SLOT(setPRESSURE(int)));
    connect(ros_process, SIGNAL(updateBMSDE(int)), this, SLOT(setBMSDE(int)));
    connect(ros_process, SIGNAL(updateRMSVSM(int)), this, SLOT(setRMSVSM(int)));
    connect(ros_process, SIGNAL(updateInverter(int)), this, SLOT(setInverter(int)));
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

void MainWindow::showStartupFour()
{
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_4.png)0 0 0 0 stretch stretch; background-repeat: none");
}

// Set Methods

void MainWindow::setIGNOK(int state){
    if(state == 0 || state == 1){
        gpio_value.IGNOK = state;
        // qCout << "set ignok: " << gpio_value.IGNOK << endl;
        emit updateState();
    } else{
        // qCout << "fault ignok: " << state << endl;
    }
}
void MainWindow::setIMD(int state){
    if(state == 0 || state == 1){
        gpio_value.IMD = state;
        // qCout << "set imd: " << gpio_value.IMD << endl;
        emit updateState();    
    } else{
        // qCout << "fault imd: " << state << endl;
    }
    
}
void MainWindow::setPRESSURE(int state){
    if(state == 0 || state == 1){
        gpio_value.PRESSURE = state;
        // qCout << "set pressure: " << gpio_value.PRESSURE << endl;
        emit updateState();
    } else{
        // qCout << "fault pressure: " << state << endl;
    }
}
void MainWindow::setBMSDE(int state){
    if(state == 0 || state == 1){
        gpio_value.BMSDE = state;
        // qCout << "set bmsde: " << gpio_value.BMSDE << endl;
        emit updateState();
    } else{
        // qCout << "fault bmsde: " << state << endl;
    }
}

void MainWindow::setRMSVSM(int value){
        rms_vsm_state = value;
        // qCout << "set RMS VSM State: " << rms_vsm_state << endl;
        emit updateState();
}

void MainWindow::setInverter(int value){
    rms_inverter_state = value;
    emit updateState();
}

void MainWindow::setState(int set_state, int fault_value){

    if(state != set_state){
       qCout << "State Changed To: " << state << endl; 
    }
    if(fault != fault_value){
        qCout << "Fault Changed to: " << fault_value << endl;
    }
    state = set_state;

switch(state)
    {
        case (state_option::fault):
            //Show fault screen
            MainWindow::getFAULT();
            //Determine what to do next
            break;
        case (state_option::off):
            qCout << "Battery Connected" << endl;
            // Show BOLT Logo Briefly
            MainWindow::showStartupZero();
            break;
        case (state_option::aux):
            // Show Turn On ACC
            MainWindow::showStartupOne();
            break;
        case (state_option::acc):
            // Show Turn on Ign
            MainWindow::showStartupTwo();
            break;
        case (state_option::ign):
            // RMS is powered, waiting for precharge
            MainWindow::showStartupThree();
            break;
        case (state_option::precharge):
            // Precharging
            MainWindow::showStartupThree();
            break;
        case (state_option::start):
            // Precharge complete, ready for power
            // Show Press Start Button
            MainWindow::showStartupFour();
            break;
        case(state_option::throttle):
            // Throttle is active, ask user what to do
            MainWindow::toRaceView();
            break;
        default:
            break;
    }
    emit stateSet();
}

void MainWindow::setFAULT(int value){
    qCout << "FAULT SET " << value << endl;
    fault_code = value;
    emit updateState();
}

// Get Methods

int MainWindow::getIGNOK(){
    // qCout << "ignok: " << gpio_value.IGNOK << endl;
    return gpio_value.IGNOK;
}
int MainWindow::getIMD(){
    // qCout << "imd: " << gpio_value.IMD << endl;
    return gpio_value.IMD;
}
int MainWindow::getPRESSURE(){
    // qCout << "pressure: " << gpio_value.PRESSURE << endl;
    return gpio_value.PRESSURE;
}
int MainWindow::getBMSDE(){
    // qCout << "bmsde: " << gpio_value.BMSDE << endl;
    return gpio_value.BMSDE;
}

int MainWindow::getState(){

    // AUX
    if(gpio_value.IMD && !gpio_value.IGNOK && gpio_value.BMSDE && !gpio_value.PRESSURE){
        MainWindow::setState(state_option::aux);
    }

    //ACC
    if(gpio_value.IMD && !gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE){
        MainWindow::setState(state_option::acc);
    }

    //IGN
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE){
        MainWindow::setState(state_option::ign);
    }

    //Precharge
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_inverter_state == 0 || rms_inverter_state == 1 || rms_inverter_state == 2 || rms_inverter_state == 3)){
        MainWindow::setState(state_option::precharge);
    }

    //Start
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_inverter_state == 4 || rms_inverter_state == 5)){
        MainWindow::setState(state_option::start);
    }

    //Throttle
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && rms_inverter_state == 6){
        MainWindow::setState(state_option::throttle);
    }

    // qCout << "State is " << state << endl;
    return state;
}

int MainWindow::getFAULT(){
    return fault;
}

int MainWindow::getRMSVSM(){
    return rms_vsm_state;
}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}
