// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Include header files
#include "Wilbur.h"

// https://doc.qt.io/qt-6/qgridlayout.html

//CONFIG += console

// Main Wilbur Application Primer
int main(int argc, char *argv[])
{
    int simMode = 1;
    // set up and show widgets
    QApplication app(argc, argv);

    if (argc > 1)
    {
        // read first char of second command line arg, 'cast' to int
        simMode = argv[1][0] - '0';
    }

    // Wilbur widgets - initialize object
    MainWindow wilbur(nullptr, simMode);

	// Show Wilbur main window
    wilbur.show();

    // call the application
    return app.exec();
}
