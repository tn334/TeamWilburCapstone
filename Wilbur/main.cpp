// Include header files
#include "Wilbur.h"
//#include <iostream>
// Qt Header Files
#include <QPalette>
#include <QDebug>
#include <QtWidgets/QApplication>
// https://doc.qt.io/qt-6/qgridlayout.html
#include <QGridLayout>

//CONFIG += console

int main(int argc, char *argv[])
{
    // set up and show widgets
    QApplication app(argc, argv);

    // Wilbur widgets - initialize object
    MainWindow wilbur;
    wilbur.show();

    //std::cout << "Application started!" << std::endl;

    // call the application
    return app.exec();
}
