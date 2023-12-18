#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Raster Algorithms");
    w.resize(850,750);
    w.show();
    return a.exec();
}
