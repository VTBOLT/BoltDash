#ifndef GPIONODE_H
#define GPIONODE_H

#include <QThread>
#include "wiringPi.h"

#define IGNOK_PIN 27
#define IMD_PIN 24
#define PRESSURE_PIN 28
#define BMSDE_PIN 25

class GpioNode : public QThread
{
    Q_OBJECT
public:
    GpioNode();
    void run();

private:
    int IGNOK;
    int IMD;
    int PRESSURE;
    int BMSDE;

signals:
    void updateIGNOK(int data);
    void updateIMD(int imd);
    void updatePRESSURE(int pres);
    void updateBMSDE(int bmsde);
};

#endif // GPIONODE_H
