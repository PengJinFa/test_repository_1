#include "mainwindow.h"
#include <QApplication>


int allCanSee=3.14;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
