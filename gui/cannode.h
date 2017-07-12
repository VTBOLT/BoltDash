#ifndef CANNODE_H
#define CANNODE_H

#include <QThread>
#include <QVariant>
#include <QString>
#include "can/cancomm.h"

class CanNode : public QThread
{
    Q_OBJECT
public:
    CanNode();
    void run();

private:
    int cell_high = 0, cell_low = 0;
    int max_rinehart_temp = 0;

signals:
    void updateRPM(double rpm);
    void updateRPM(const QVariant & rpm);
    void updateSOC(double volt);
    void updateSOC(int volt);
    void updateMotorTemp(double temp);
    void updateDcCurrent(double current);
    void updateOutputVolts(double volts);
    void updatePackVolts(double volts);
    void updatePackCurrent(double current);
    void updatePackTempHigh(double temp);
    void updateDelta(double delta);
    void updateControllerTemp(double temp);
    void updateRmsCurrent(double rms);
    void updateFieldWeakening(double angle);
    void updateCellVoltHigh(int value);
    void updateCellVoltLow(int value);
    void updateCellVoltHighID(int value);
    void updateCellVoltLowID(int value);
    void updatePackDCL(int value);
    void updateRMSVSM(int value);
    void updateInverter(int value);
};

#endif // CANNODE_H
