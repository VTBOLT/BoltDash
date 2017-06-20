//
// dash_gui.cpp
//
// Created: 27 Feb 2017
// Author: Adam Plowcha
//

#include <dash_gui.h>

QTextStream qCout(stdout);

namespace dash_gui
{

DashGui::DashGui() : 
  rqt_gui_cpp::Plugin(), widget_(0)
{
    setObjectName("DashGui");
}

DashGui::~DashGui()
{
  delete widget_;
  delete datanode;
}

void DashGui::initPlugin(qt_gui_cpp::PluginContext &context)
{
    /* Setup the widget */
    widget_ = new QOpenGLWidget();
    ui_.setupUi(widget_);
    context.addWidget(widget_);

    // instantiates a ros node to read data
    datanode = new DataNode();

    loadQML();

    connectStartupSlots();
    connectRaceSlots();
    connectNavSlots();
    connectDebugSlots();

    // call DataNode::run() to get the ros spinner going
    datanode->start();

    // TODO : replace with startup stuff
    toRaceView();
}

void DashGui::loadQML()
{
    ui_.qmlRace->setSource(QUrl("qrc:///qml/race_view.qml"));
    rootObject = ui_.qmlRace->rootObject();
}

void DashGui::connectDebugSlots()
{
    connect(datanode, SIGNAL( updateRPM(double)), ui_.lcdRPM, SLOT(display(double)));
    connect(datanode, SIGNAL( updateMotorTemp(double)), ui_.lcdMotorTemp, SLOT(display(double)));
    connect(datanode, SIGNAL( updatePackVolts(double)), ui_.lcdPackVoltage, SLOT(display(double)));
    connect(datanode, SIGNAL( updateOutputVolts(double)), ui_.lcdOutputVoltage, SLOT(display(double)));
    connect(datanode, SIGNAL( updateDcCurrent(double)), ui_.lcdDCCurrent, SLOT(display(double)));
    connect(datanode, SIGNAL( updatePackCurrent(double)), ui_.lcdPackCurrent, SLOT(display(double)));
    connect(datanode, SIGNAL( updatePackTempHigh(double)), ui_.lcdPackTempHigh, SLOT(display(double)));
    connect(datanode, SIGNAL( updateSOC(double)), ui_.lcdSOC, SLOT(display(double)));
    connect(datanode, SIGNAL( updateDelta(double)), ui_.lcdDelta_2, SLOT(display(double)));
    connect(datanode, SIGNAL( updateControllerTemp(double)), ui_.lcdControllerTemp, SLOT(display(double)));
    connect(datanode, SIGNAL( updateRmsCurrent(double)), ui_.lcdRmsCurrent, SLOT(display(double)));
    connect(datanode, SIGNAL( updateFieldWeakening(double)), ui_.lcdFieldWeakening, SLOT(display(double)));

}

void DashGui::connectRaceSlots()
{
    connect(datanode, SIGNAL(updateRPM(QVariant)), this, SLOT(setRPM(QVariant)));
    connect(datanode, SIGNAL(updateSOC(QVariant)), this, SLOT(setBatteryPercent(QVariant)));

}

void DashGui::connectStartupSlots()
{
    connect(this, SIGNAL( updateState()), this, SLOT(getState()));
    connect(datanode, SIGNAL(updateIGNOK(int)), this, SLOT(setIGNOK(int)));
    connect(datanode, SIGNAL(updateIMD(int)), this, SLOT(setIMD(int)));
    connect(datanode, SIGNAL(updatePRESSURE(int)), this, SLOT(setPRESSURE(int)));
    connect(datanode, SIGNAL(updateBMSDE(int)), this, SLOT(setBMSDE(int)));
    connect(datanode, SIGNAL(updateRMSVSM(int)), this, SLOT(setRMSVSM(int)));
    connect(datanode, SIGNAL(updateInverter(int)), this, SLOT(setInverter(int)));

}

void DashGui::setRPM(QVariant rpm)
{
    float angle = rpm.toFloat() * (180.0/8000.0);
    rootObject->setProperty("myRot", QVariant(angle));
}

void DashGui::setBatteryPercent(QVariant value)
{
    rootObject->setProperty("green_bar", QVariant(value));
}

void DashGui::connectNavSlots()
{
    connect(rootObject, SIGNAL(toDebugSignal()), this, SLOT(toDebugView()));

    connect(ui_.toRaceButton,SIGNAL(clicked(bool)),this,SLOT(toRaceView()));
    connect(ui_.toDebugButton,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(ui_.toVoltageButton,SIGNAL(clicked(bool)),this,SLOT(toVoltageView()));
    connect(ui_.exitButton,SIGNAL(clicked(bool)),this,SLOT(on_exitButton_clicked()));
}

void DashGui::toDebugView()
{
    ui_.views->setCurrentIndex(DEBUG);
}

void DashGui::toRaceView()
{
    ui_.views->setCurrentIndex(RACE);
}

void DashGui::toVoltageView()
{
    ui_.views->setCurrentIndex(VOLTAGE);
}

void DashGui::toStartupScreen()
{
    ui_.views->setCurrentIndex(STARTUP);
}

void DashGui::showStartupZero()
{
    qCout << "Display BOLT Logo" << endl;
    DashGui::toStartupScreen();
    ui_.startupFrame->setStyleSheet("border-image:url(:/images/startup_0.png)0 0 0 0 stretch stretch; background-repeat: none" );
}

void DashGui::showStartupOne()
{
    qCout << "Display Acc" << endl;
    DashGui::toStartupScreen();
    ui_.startupFrame->setStyleSheet("border-image:url(:/images/startup_1.png)0 0 0 0 stretch stretch; background-repeat: none");
}

void DashGui::showStartupTwo()
{
    qCout << "Display Ign" << endl;
    DashGui::toStartupScreen();
    ui_.startupFrame->setStyleSheet("border-image:url(:/images/startup_2.png)0 0 0 0 stretch stretch; background-repeat: none");
}

void DashGui::showStartupThree()
{
    qCout << "Display Precharge" << endl;
    DashGui::toStartupScreen();
    ui_.startupFrame->setStyleSheet("border-image:url(:/images/startup_3.png)0 0 0 0 stretch stretch; background-repeat: none");

}

void DashGui::showStartupFour()
{
    qCout << "Display Start" << endl;
    DashGui::toStartupScreen();
    ui_.startupFrame->setStyleSheet("border-image:url(:/images/startup_4.png)0 0 0 0 stretch stretch; background-repeat: none");
}

// Set Methods

void DashGui::setIGNOK(int state)
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

void DashGui::setIMD(int state)
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

void DashGui::setPRESSURE(int state)
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

void DashGui::setBMSDE(int state)
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

void DashGui::setRMSVSM(int value){
        rms_vsm_state = value;
        qCout << "set RMS VSM State: " << rms_vsm_state <<  " window: " << ui_.views->currentIndex() << endl;
        emit updateState();
}

void DashGui::setInverter(int value){
    rms_inverter_state = value;
    emit updateState();
}

void DashGui::setState(int set_state, int fault_value){

    if(state != set_state){
       state = set_state;
       qCout << "State Changed To: " << state << endl; 

       switch(state)
       {
           case (state_option::fault):
               //Show fault screen
               DashGui::getFAULT();
               //Determine what to do next
               break;
           case (state_option::off):
               qCout << "Battery Connected" << endl;
               // Show BOLT Logo Briefly
               DashGui::showStartupZero();
               break;
           case (state_option::aux):
               // Show Turn On ACC
               qCout << "AUX" << endl;
               DashGui::showStartupOne();
               break;
           case (state_option::acc):
               // Show Turn on Ign
               qCout << "ACC" << endl;
               DashGui::showStartupTwo();
               break;
           case (state_option::ign):
               // RMS is powered, waiting for precharge
               qCout << "IGN" << endl;
               DashGui::showStartupThree();
               break;
           case (state_option::precharge):
               // Precharging
               qCout << "Precharge" << endl;
               DashGui::showStartupThree();
               break;
           case (state_option::start):
               // Precharge complete, ready for power
               // Show Press Start Button
               qCout << "Start" << endl;
               DashGui::showStartupFour();
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

int DashGui::getIGNOK()
{
    qCout << "ignok: " << gpio_value.IGNOK << endl;
    return gpio_value.IGNOK;
}

int DashGui::getIMD()
{
    qCout << "imd: " << gpio_value.IMD << endl;
    return gpio_value.IMD;
}

int DashGui::getPRESSURE()
{
    qCout << "pressure: " << gpio_value.PRESSURE << endl;
    return gpio_value.PRESSURE;
}

int DashGui::getBMSDE()
{
    qCout << "bmsde: " << gpio_value.BMSDE << endl;
    return gpio_value.BMSDE;
}

int DashGui::getState(){

    //OFF
    if(!gpio_value.IMD && !gpio_value.IGNOK && !gpio_value.BMSDE && !gpio_value.PRESSURE){
        DashGui::setState(state_option::off);
    }

    // AUX
    if(!gpio_value.IMD && !gpio_value.IGNOK && gpio_value.BMSDE && !gpio_value.PRESSURE){
        DashGui::setState(state_option::aux);
    }

    //ACC
    if(gpio_value.IMD && !gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE){
        DashGui::setState(state_option::acc);
    }

    //IGN
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_vsm_state == -1 || rms_vsm_state == 14)){
        DashGui::setState(state_option::ign);
    }

    //Precharge
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_vsm_state == 0 || rms_vsm_state == 1 || rms_vsm_state == 2 || rms_vsm_state == 3)){
        DashGui::setState(state_option::precharge);
    }

    //Start
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && (rms_vsm_state == 4 || rms_vsm_state == 5)){
        DashGui::setState(state_option::start);
    }

    //Throttle
    if(gpio_value.IMD && gpio_value.IGNOK && gpio_value.BMSDE && gpio_value.PRESSURE && rms_vsm_state == 6){
        DashGui::setState(state_option::throttle);
    }

//     qCout << "State: " << state << " rms_vsm: " << rms_vsm_state << endl;

    // This qCout allows the states to not freeze, this is a bug
    // TODO: Fix this bug
    //qCout << "";

    return state;
}

int DashGui::getFAULT(){
    return fault;
}

int DashGui::getRMSVSM(){
    return rms_vsm_state;
}

// TODO : Exiting with a weird status, look into better way
void DashGui::on_exitButton_clicked()
{
    exit(0);
}


// END NAMESPACE
}

//This is a required line for Qt and ROS to work together
PLUGINLIB_EXPORT_CLASS(dash_gui::DashGui, rqt_gui_cpp::Plugin)
