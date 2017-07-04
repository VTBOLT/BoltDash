#include "gpionode.h"

GpioNode::GpioNode()
{
    return;
}

void GpioNode::run()
{
    while (1)
    {
        // Setup GPIO
        wiringPiSetup();
        // Setup Dash Pin as Input
        pinMode(IGNOK_PIN, INPUT);
        pinMode(IMD_PIN, INPUT);
        pinMode(PRESSURE_PIN, INPUT);
        pinMode(BMSDE_PIN, INPUT);

        // Read Dash Pin State
        IGNOK = digitalRead(IGNOK_PIN);
        IMD = digitalRead(IMD_PIN);
        PRESSURE = digitalRead(PRESSURE_PIN);

        if(digitalRead(BMSDE_PIN) == 1)
            BMSDE = 0;
        else if (digitalRead(BMSDE_PIN) == 0)
            BMSDE = 1;

        emit updateBMSDE(BMSDE);
        emit updateIGNOK(IGNOK);
        emit updateIMD(IMD);
        emit updatePRESSURE(PRESSURE);

        // sleep 50 milliseconds
        msleep(50);
    }
}
