#include "WilburTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WilburTest w;
    w.show();
    return a.exec();
}
