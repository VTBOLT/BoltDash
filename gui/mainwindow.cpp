#include "mainwindow.h"
#include "ui_mainwindow.h"

QTextStream qCout(stdout);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    loadQML();

    can_node = new CanNode();
//    can_node->start();
    gpio_node = new GpioNode();
//    gpio_node->start();

    connectStartupSlots();
    connectRaceSlots();
    connectNavSlots();
    connectDebugSlots();

    // TODO : replace with startup stuff
    //toStartupScreen();
    toDebugView();
    //toRaceView();
}

MainWindow::~MainWindow()
{
    delete ui;   connect(rootObject, SIGNAL(toDebugSignal()), this, SLOT(toDebugView()));

    connect(ui->toRaceButton,SIGNAL(clicked(bool)),this,SLOT(toRaceView()));
    connect(ui->toDebugButton,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(ui->toVoltageButton,SIGNAL(clicked(bool)),this,SLOT(toVoltageView()));
    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(on_exitButton_clicked()));
}

void MainWindow::loadQML()
{
//    ui->qmlRace->setSource(QUrl("qrc:///qml/race_view.qml"));
//    rootObject = ui->qmlRace->rootObject();
}

void MainWindow::connectDebugSlots()
{
    connect(can_node, SIGNAL( updateRPM(double)), ui->lcdRPM, SLOT(display(double)));
    connect(can_node, SIGNAL( updateMotorTemp(double)), ui->lcdMotorTemp, SLOT(display(double)));
    connect(can_node, SIGNAL( updatePackVolts(double)), ui->lcdPackVoltage, SLOT(display(double)));
    connect(can_node, SIGNAL( updateOutputVolts(double)), ui->lcdOutputVoltage, SLOT(display(double)));
    connect(can_node, SIGNAL( updateDcCurrent(double)), ui->lcdDCCurrent, SLOT(display(double)));
    connect(can_node, SIGNAL( updatePackCurrent(double)), ui->lcdPackCurrent, SLOT(display(double)));
    connect(can_node, SIGNAL( updatePackTempHigh(double)), ui->lcdPackTempHigh, SLOT(display(double)));
    connect(can_node, SIGNAL( updateSOC(double)), ui->lcdSOC, SLOT(display(double)));
    connect(can_node, SIGNAL( updateDelta(double)), ui->lcdDelta_2, SLOT(display(double)));
    connect(can_node, SIGNAL( updateControllerTemp(double)), ui->lcdControllerTemp, SLOT(display(double)));
    connect(can_node, SIGNAL( updateRmsCurrent(double)), ui->lcdRmsCurrent, SLOT(display(double)));
    connect(can_node, SIGNAL( updateFieldWeakening(double)), ui->lcdFieldWeakening, SLOT(display(double)));
}

void MainWindow::connectRaceSlots()
{
//    connect(can_node, SIGNAL(updateRPM(QVariant)), this, SLOT(setRPM(QVariant)));
//    connect(can_node, SIGNAL(updateSOC(double)), this, SLOT(setBatteryPercent(double)));
    connect(can_node, SIGNAL(updateRPM(double)), ui->rpm, SLOT(display(double)));
    connect(can_node, SIGNAL(updateSOC(int)), ui->soc, SLOT(setValue(int)));
}

void MainWindow::connectStartupSlots()
{
    connect(this, SIGNAL( updateState()), this, SLOT(getState()));
    connect(gpio_node, SIGNAL(updateIGNOK(int)), this, SLOT(setIGNOK(int)));
    connect(gpio_node, SIGNAL(updateIMD(int)), this, SLOT(setIMD(int)));
    connect(gpio_node, SIGNAL(updatePRESSURE(int)), this, SLOT(setPRESSURE(int)));
    connect(gpio_node, SIGNAL(updateBMSDE(int)), this, SLOT(setBMSDE(int)));
    connect(can_node, SIGNAL(updateRMSVSM(int)), this, SLOT(setRMSVSM(int)));
    connect(can_node, SIGNAL(updateInverter(int)), this, SLOT(setInverter(int)));
}

void MainWindow::connectVoltageSlots()
{
  connect(can_node, SIGNAL( updateCellVoltageHigh(double)), ui->lcdHighVoltage, SLOT(display(double)));
  connect(can_node, SIGNAL( updateCellVoltageLow(double)), ui->lcdLowVoltage, SLOT(display(double)));
  connect(can_node, SIGNAL( updateDelta(double)), ui->lcdDelta, SLOT(display(double)));
  connect(can_node, SIGNAL( updateCellVoltageHighID(double)), ui->lcdPackA, SLOT(display(double)));
  connect(can_node, SIGNAL( updateCellVoltageLowID(double)), ui->lcdPackB, SLOT(display(double)));
  connect(can_node, SIGNAL( updatePackDCL(double)), ui->lcdPackC, SLOT(display(double)));
  connect(can_node, SIGNAL( updatePackVolts(double)), ui->lcdPackD, SLOT(display(double)));
}

void MainWindow::setRPM(QVariant rpm)
{
//    float angle = rpm.toFloat() * (180.0/8000.0);
//    rootObject->setProperty("myRot", QVariant(angle));
}

void MainWindow::setBatteryPercent(double value)
{
//    double width = 512 * ( value/100.0 );
//    rootObject->setProperty("green_bar", QVariant(width));
}

void MainWindow::connectNavSlots()
{
//    connect(rootObject, SIGNAL(toDebugSignal()), this, SLOT(toDebugView()));

    connect(ui->toDeubug,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(ui->toRaceButton,SIGNAL(clicked(bool)),this,SLOT(toRaceView()));
    connect(ui->toDebugButton,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(ui->toVoltageButton,SIGNAL(clicked(bool)),this,SLOT(toVoltageView()));
    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(on_exitButton_clicked()));
}

void MainWindow::toDebugView()
{
    ui->views->setCurrentIndex(DEBUG);
    //ui->views->setCurrentIndex(STARTUP);
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
    qCout << "Display BOLT Logo" << endl;
    MainWindow::toStartupScreen();
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_0.png)0 0 0 0 stretch stretch; background-repeat: none" );
}

void MainWindow::showStartupOne()
{
    qCout << "Display Acc" << endl;
    MainWindow::toStartupScreen();
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_1.png)0 0 0 0 stretch stretch; background-repeat: none");
}

void MainWindow::showStartupTwo()
{
    qCout << "Display Ign" << endl;
    MainWindow::toStartupScreen();
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_2.png)0 0 0 0 stretch stretch; background-repeat: none");
}

void MainWindow::showStartupThree()
{
    qCout << "Display Precharge" << endl;
    MainWindow::toStartupScreen();
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_3.png)0 0 0 0 stretch stretch; background-repeat: none");

}

void MainWindow::showStartupFour()
{
    qCout << "Display Start" << endl;
    MainWindow::toStartupScreen();
    ui->startupFrame->setStyleSheet("border-image:url(:/images/startup_4.png)0 0 0 0 stretch stretch; background-repeat: none");
}

// Set Methods

void MainWindow::setIGNOK(int state)
{
    if(state == 0 || state == 1)
    {
        gpio_value.IGNOK = state;
        qCout << "set ignok: " << gpio_value.IGNOK << endl;
        emit updateState();
    }
    else
    {
        qCout << "fault ignok: " << state << endl;
    }
}

void MainWindow::setIMD(int state)
{
    if(state == 0 || state == 1)
    {
        gpio_value.IMD = state;
        qCout << "set imd: " << gpio_value.IMD << endl;
        emit updateState();
    }
    else
    {
        qCout << "fault imd: " << state << endl;
    }

}

void MainWindow::setPRESSURE(int state)
{
    if(state == 0 || state == 1)
    {
        gpio_value.PRESSURE = state;
        qCout << "set pressure: " << gpio_value.PRESSURE << endl;
        emit updateState();
    }
    else
    {
        qCout << "fault pressure: " << state << endl;
    }
}

void MainWindow::setBMSDE(int state)
{
    if(state == 0 || state == 1)
    {
        gpio_value.BMSDE = state;
        qCout << "set bmsde: " << gpio_value.BMSDE << endl;
        emit updateState();
    }
    else
    {
        qCout << "fault bmsde: " << state << endl;
    }
}

void MainWindow::setRMSVSM(int value){
        rms_vsm_state = value;
        qCout << "set RMS VSM State: " << rms_vsm_state <<  " window: " << ui->views->currentIndex() << endl;
        emit updateState();
}

void MainWindow::setInverter(int value){
    rms_inverter_state = value;
    emit updateState();
}

void MainWindow::setFAULT(int value)
{

}

void MainWindow::setState(int set_state, int fault_value){

    if(state != set_state){
       state = set_state;
       qCout << "State Changed To: " << state << endl;

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
               qCout << "AUX" << endl;
               MainWindow::showStartupOne();
               break;
           case (state_option::acc):
               // Show Turn on Ign
               qCout << "ACC" << endl;
               MainWindow::showStartupTwo();
               break;
           case (state_option::ign):
               // RMS is powered, waiting for precharge
               qCout << "IGN" << endl;
               MainWindow::showStartupThree();
               break;
           case (state_option::precharge):
               // Precharging
               qCout << "Precharge" << endl;
               MainWindow::showStartupThree();
               break;
           case (state_option::start):
               // Precharge complete, ready for power
               // Show Press Start Button
               qCout << "Start" << endl;
               MainWindow::showStartupFour();
               break;
           case(state_option::throttle):
               // Throttle is active, ask user what to do
               qCout << "Throttle" << endl;
               toRaceView();
               break;
           default:
               break;
           }
    }

    if(fault_code != fault_value){
        fault_code = fault_value;
        qCout << "Fault Changed to: " << fault_value << endl;
    }
    emit stateSet();
}

int MainWindow::getIGNOK()
{
    qCout << "ignok: " << gpio_value.IGNOK << endl;
    return gpio_value.IGNOK;
}

int MainWindow::getIMD()
{
    qCout << "imd: " << gpio_value.IMD << endl;
    return gpio_value.IMD;
}

int MainWindow::getPRESSURE()
{
    qCout << "pressure: " << gpio_value.PRESSURE << endl;
    return gpio_value.PRESSURE;
}

int MainWindow::getBMSDE()
{
    qCout << "bmsde: " << gpio_value.BMSDE << endl;
    return gpio_value.BMSDE;
}

int MainWindow::getState(){

    //OFF
    if(!gpio_value.IMD && !gpio_value.IGNOK && !gpio_value.BMSDE && !gpio_value.PRESSURE){
        MainWindow::setState(state_option::off);
    }

    // AUX
    if(!gpio_value.IMD && !gpio_value.IGNOK && gpio_value.BMSDE && !gpio_value.PRESSURE){
        MainWindow::setState(state_option::aux);
    }

    //ACC
    if(gpio_value.IMD && !gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE){
        MainWindow::setState(state_option::acc);
    }

    //IGN
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_vsm_state == -1 || rms_vsm_state == 14)){
        MainWindow::setState(state_option::ign);
    }

    //Precharge
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_vsm_state == 0 || rms_vsm_state == 1 || rms_vsm_state == 2 || rms_vsm_state == 3)){
        MainWindow::setState(state_option::precharge);
    }

    //Start
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_vsm_state == 4 || rms_vsm_state == 5)){
        MainWindow::setState(state_option::start);
    }

    //Throttle
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && rms_vsm_state == 6){
        MainWindow::setState(state_option::throttle);
    }

//     qCout << "State: " << state << " rms_vsm: " << rms_vsm_state << endl;

    // This qCout allows the states to not freeze, this is a bug
    // TODO: Fix this bug
    //qCout << "";

    return state;
}

int MainWindow::getFAULT(){
    return fault;
}

int MainWindow::getRMSVSM(){
    return rms_vsm_state;
}

// TODO : Exiting with a weird status, look into better way
void MainWindow::on_exitButton_clicked()
{
    exit(0);
}

