#-------------------------------------------------
#
# Project created by QtCreator 2017-07-02T19:21:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += quickwidgets

TARGET = gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#INCLUDEPATH += /usr/local/include
LIBS += -lwiringPi
LIBS += -lcrypt

SOURCES += main.cpp\
        mainwindow.cpp \
    cannode.cpp \
#    can/can_fault_code_fsm.cpp \
    can/canreceive.cpp \
    can/cansend.cpp \
    gpionode.cpp

HEADERS  += mainwindow.h \
    cannode.h \
    can/can.h \
    can/cancomm.h \
    can/canframelen.h \
    can/error.h \
    can/gw.h \
    can/isotp.h \
    can/lib.h \
    can/netlink.h \
    can/raw.h \
    can/terminal.h \
    gpionode.h

FORMS    += mainwindow.ui

DISTFILES += \
    resources/Dashboard Design Resized.ai \
    resources/battery_sized_to_fit_screen.png \
    resources/dash_background_with_meter.png \
    resources/needle_w_green_dot.png \
    resources/needle_w_red_dot.png \
    resources/needle_w_yellow_dot.png \
    resources/startup_0.png \
    resources/startup_1.png \
    resources/startup_2.png \
    resources/startup_3.png \
    resources/startup_4.png \
    resources/Dash_Needle.svg \
    resources/race_view.qml

RESOURCES += \
    resources/resources.qrc

