/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtQuickWidgets/QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *mainVBoxLayout;
    QStackedWidget *views;
    QWidget *RaceView;
    QGridLayout *gridLayout_2;
    QQuickWidget *qmlRace;
    QWidget *DebugView;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLCDNumber *angle_lcd;
    QLabel *rms_lab;
    QLCDNumber *drive7_lcd;
    QLCDNumber *dc_lcd;
    QLabel *dc_lab;
    QLabel *rpm_lab;
    QLCDNumber *hs_lcd;
    QLabel *motorTemp_lab;
    QLCDNumber *emcy7_lcd;
    QLCDNumber *motorTemp_lcd;
    QLCDNumber *rpm_lcd;
    QLabel *drive6_lab;
    QLabel *iq_lab;
    QLCDNumber *battTemp_lcd;
    QLabel *emcy6_lab;
    QLabel *angle_lab;
    QLabel *drive7_lab;
    QLabel *emcy7_lab;
    QLabel *batt_lab;
    QLCDNumber *emcy6_lcd;
    QLCDNumber *iq_lcd;
    QLCDNumber *rms_lcd;
    QLabel *hs_lab;
    QLCDNumber *drive6_lcd;
    QHBoxLayout *buttonLayout2;
    QSpacerItem *horizontalSpacer;
    QPushButton *toRaceButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1238, 699);
        MainWindow->setStyleSheet(QLatin1String("background: black\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mainVBoxLayout = new QVBoxLayout();
        mainVBoxLayout->setSpacing(6);
        mainVBoxLayout->setObjectName(QStringLiteral("mainVBoxLayout"));
        views = new QStackedWidget(centralWidget);
        views->setObjectName(QStringLiteral("views"));
        RaceView = new QWidget();
        RaceView->setObjectName(QStringLiteral("RaceView"));
        gridLayout_2 = new QGridLayout(RaceView);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        qmlRace = new QQuickWidget(RaceView);
        qmlRace->setObjectName(QStringLiteral("qmlRace"));
        qmlRace->setMinimumSize(QSize(1200, 600));
        qmlRace->setMaximumSize(QSize(1280, 650));
        qmlRace->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout_2->addWidget(qmlRace, 0, 0, 1, 1);

        views->addWidget(RaceView);
        DebugView = new QWidget();
        DebugView->setObjectName(QStringLiteral("DebugView"));
        DebugView->setStyleSheet(QLatin1String("QLabel {font : bold 24px; color: white}\n"
"QLCDNumber {color: white}\n"
"QPushButton {background: white}"));
        gridLayout_3 = new QGridLayout(DebugView);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        angle_lcd = new QLCDNumber(DebugView);
        angle_lcd->setObjectName(QStringLiteral("angle_lcd"));

        gridLayout->addWidget(angle_lcd, 3, 2, 1, 1);

        rms_lab = new QLabel(DebugView);
        rms_lab->setObjectName(QStringLiteral("rms_lab"));

        gridLayout->addWidget(rms_lab, 0, 2, 1, 1);

        drive7_lcd = new QLCDNumber(DebugView);
        drive7_lcd->setObjectName(QStringLiteral("drive7_lcd"));

        gridLayout->addWidget(drive7_lcd, 5, 3, 1, 1);

        dc_lcd = new QLCDNumber(DebugView);
        dc_lcd->setObjectName(QStringLiteral("dc_lcd"));

        gridLayout->addWidget(dc_lcd, 1, 3, 1, 1);

        dc_lab = new QLabel(DebugView);
        dc_lab->setObjectName(QStringLiteral("dc_lab"));

        gridLayout->addWidget(dc_lab, 0, 3, 1, 1);

        rpm_lab = new QLabel(DebugView);
        rpm_lab->setObjectName(QStringLiteral("rpm_lab"));

        gridLayout->addWidget(rpm_lab, 0, 0, 1, 1);

        hs_lcd = new QLCDNumber(DebugView);
        hs_lcd->setObjectName(QStringLiteral("hs_lcd"));

        gridLayout->addWidget(hs_lcd, 3, 0, 1, 1);

        motorTemp_lab = new QLabel(DebugView);
        motorTemp_lab->setObjectName(QStringLiteral("motorTemp_lab"));

        gridLayout->addWidget(motorTemp_lab, 2, 1, 1, 1);

        emcy7_lcd = new QLCDNumber(DebugView);
        emcy7_lcd->setObjectName(QStringLiteral("emcy7_lcd"));

        gridLayout->addWidget(emcy7_lcd, 5, 1, 1, 1);

        motorTemp_lcd = new QLCDNumber(DebugView);
        motorTemp_lcd->setObjectName(QStringLiteral("motorTemp_lcd"));

        gridLayout->addWidget(motorTemp_lcd, 3, 1, 1, 1);

        rpm_lcd = new QLCDNumber(DebugView);
        rpm_lcd->setObjectName(QStringLiteral("rpm_lcd"));

        gridLayout->addWidget(rpm_lcd, 1, 0, 1, 1);

        drive6_lab = new QLabel(DebugView);
        drive6_lab->setObjectName(QStringLiteral("drive6_lab"));

        gridLayout->addWidget(drive6_lab, 4, 2, 1, 1);

        iq_lab = new QLabel(DebugView);
        iq_lab->setObjectName(QStringLiteral("iq_lab"));

        gridLayout->addWidget(iq_lab, 2, 3, 1, 1);

        battTemp_lcd = new QLCDNumber(DebugView);
        battTemp_lcd->setObjectName(QStringLiteral("battTemp_lcd"));

        gridLayout->addWidget(battTemp_lcd, 1, 1, 1, 1);

        emcy6_lab = new QLabel(DebugView);
        emcy6_lab->setObjectName(QStringLiteral("emcy6_lab"));

        gridLayout->addWidget(emcy6_lab, 4, 0, 1, 1);

        angle_lab = new QLabel(DebugView);
        angle_lab->setObjectName(QStringLiteral("angle_lab"));

        gridLayout->addWidget(angle_lab, 2, 2, 1, 1);

        drive7_lab = new QLabel(DebugView);
        drive7_lab->setObjectName(QStringLiteral("drive7_lab"));

        gridLayout->addWidget(drive7_lab, 4, 3, 1, 1);

        emcy7_lab = new QLabel(DebugView);
        emcy7_lab->setObjectName(QStringLiteral("emcy7_lab"));

        gridLayout->addWidget(emcy7_lab, 4, 1, 1, 1);

        batt_lab = new QLabel(DebugView);
        batt_lab->setObjectName(QStringLiteral("batt_lab"));

        gridLayout->addWidget(batt_lab, 0, 1, 1, 1);

        emcy6_lcd = new QLCDNumber(DebugView);
        emcy6_lcd->setObjectName(QStringLiteral("emcy6_lcd"));

        gridLayout->addWidget(emcy6_lcd, 5, 0, 1, 1);

        iq_lcd = new QLCDNumber(DebugView);
        iq_lcd->setObjectName(QStringLiteral("iq_lcd"));

        gridLayout->addWidget(iq_lcd, 3, 3, 1, 1);

        rms_lcd = new QLCDNumber(DebugView);
        rms_lcd->setObjectName(QStringLiteral("rms_lcd"));

        gridLayout->addWidget(rms_lcd, 1, 2, 1, 1);

        hs_lab = new QLabel(DebugView);
        hs_lab->setObjectName(QStringLiteral("hs_lab"));

        gridLayout->addWidget(hs_lab, 2, 0, 1, 1);

        drive6_lcd = new QLCDNumber(DebugView);
        drive6_lcd->setObjectName(QStringLiteral("drive6_lcd"));

        gridLayout->addWidget(drive6_lcd, 5, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        buttonLayout2 = new QHBoxLayout();
        buttonLayout2->setSpacing(6);
        buttonLayout2->setObjectName(QStringLiteral("buttonLayout2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout2->addItem(horizontalSpacer);

        toRaceButton = new QPushButton(DebugView);
        toRaceButton->setObjectName(QStringLiteral("toRaceButton"));

        buttonLayout2->addWidget(toRaceButton);


        gridLayout_3->addLayout(buttonLayout2, 1, 0, 1, 1);

        views->addWidget(DebugView);

        mainVBoxLayout->addWidget(views);


        horizontalLayout_2->addLayout(mainVBoxLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1238, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        rms_lab->setText(QApplication::translate("MainWindow", "RMS Current", Q_NULLPTR));
        dc_lab->setText(QApplication::translate("MainWindow", "DC Voltage", Q_NULLPTR));
        rpm_lab->setText(QApplication::translate("MainWindow", "RPM", Q_NULLPTR));
        motorTemp_lab->setText(QApplication::translate("MainWindow", "Motor Temp", Q_NULLPTR));
        drive6_lab->setText(QApplication::translate("MainWindow", "drive6stat", Q_NULLPTR));
        iq_lab->setText(QApplication::translate("MainWindow", "IQ Current", Q_NULLPTR));
        emcy6_lab->setText(QApplication::translate("MainWindow", "EMCY6", Q_NULLPTR));
        angle_lab->setText(QApplication::translate("MainWindow", "Voltage Angle", Q_NULLPTR));
        drive7_lab->setText(QApplication::translate("MainWindow", "drive7stat", Q_NULLPTR));
        emcy7_lab->setText(QApplication::translate("MainWindow", "EMCY7", Q_NULLPTR));
        batt_lab->setText(QApplication::translate("MainWindow", "Battery Temp", Q_NULLPTR));
        hs_lab->setText(QApplication::translate("MainWindow", "HS Temp", Q_NULLPTR));
        toRaceButton->setText(QApplication::translate("MainWindow", "to Dashboard", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
