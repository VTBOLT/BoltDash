#ifndef ROSPROCESS_H
#define ROSPROCESS_H

#include <QThread>
#include <QProcess>
#include <QVariant>

class RosProcess : public QThread
{
    Q_OBJECT
public:
    RosProcess(QString path, QStringList args);
    void run();

private:
    void parseData(QByteArray data); // TODO
    void parseError();
    QProcess * m_processObj;

public slots:
    void readData();
    void readError();

signals:
    void updateBatteryTemp(int temp);
    void updateRPM(double rpm);
    void updateRPM_QVar(const QVariant & rpm);
    void updateRMScurr(int curr);
    void updateDCvolt(double volt);
    void updateDCVolt_QVar(const QVariant & volt);
    void updateHStemp(int temp);
    void updateMotorTemp(int temp);
    void updateVoltAngle(int angle);
    void updateIQcurr(int angle);
    void sendEMCY6(int emc);
    void sendEMCY7(int emc);
    void sendD6stat(int stat);
    void sendD7stat(int stat);
};

#endif // ROSPROCESS_H
