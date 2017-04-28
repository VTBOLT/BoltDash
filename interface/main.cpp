/* AUTO GENERATED FILE - has been updated */

#include "mainwindow.h"
#include <QApplication>
#include <QCursor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCursor cursor(Qt::BlankCursor);
    QApplication::setOverrideCursor(cursor);
    QApplication::changeOverrideCursor(cursor);
    MainWindow w;
    w.show(); // Best choice for testing
    //w.showFullScreen(); // On the Pi we want to run this one...
    //w.showMaximized();

    return a.exec();
}
