#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<QVector<GridUpdateEvent *> >("QVector<GridUpdateEvent *>");
    QApplication a(argc, argv);
    MainWindow w(8,8);
    w.show();
    return a.exec();
}
