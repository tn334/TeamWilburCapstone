// Include header files
#include "Wilbur.h"
#include <QPalette>
#include <QDebug>
#include <QtWidgets/QApplication>
// https://doc.qt.io/qt-6/qgridlayout.html
#include <QGridLayout>

int main(int argc, char *argv[])
{
    // set up and show widgets
    QApplication app(argc, argv);

    // Wilbur widgets - initialize object
    MainWindow wilbur;
    wilbur.show();

    

    // call the application
    return app.exec();
}
