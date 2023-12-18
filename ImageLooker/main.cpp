
#include "imageinforeaderapp.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageInfoReaderApp w;
    w.show();
    return a.exec();
}
