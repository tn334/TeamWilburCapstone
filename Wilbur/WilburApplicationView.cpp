// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local header files
#include "WilburApplicationView.h"

// setting up Qt version through Qt Visual Studio Tools
// https://doc.qt.io/qtvstools/qtvstools-how-to-add-qt-versions.html
// setting Qt version for project 
// https://doc.qt.io/qtvstools/qtvstools-how-to-select-qt-versions-for-project.html

// Main Window Class
WilburApplicationView::WilburApplicationView(QWidget* parent, int simulatorMode) : QMainWindow(parent)
{
    // Set up the main layout
    mainLayout = new QGridLayout;

    // Instantiate Action Log
    actionLog = new ActionLogging;

    // Instantiate Input Director
    inputDirector = new InputDirector(simulatorMode);

    // Instantiate Navigation Bar at top of window
    navigationBar = new NavigationBar(this, actionLog);

    // Instantiate Robot Control Box
    robotControl = new PrototypeControllerView(this, actionLog, inputDirector);

    // Instantiate Central Widget "holder"
    centralWidget = new QWidget(this);

    // Instantiate spacer item for bottom of window
    QSpacerItem* verticalSpacer = new QSpacerItem(0, 20, QSizePolicy::Minimum,
        QSizePolicy::Expanding);

    // At main layout, add navigation bar, robot control box, and spacer widgets
    mainLayout->addWidget(navigationBar, 0, 0, 1, 6);
    mainLayout->addWidget(robotControl, 1, 0, 1, 3);
    mainLayout->addItem(verticalSpacer, 2, 0, 1, 6);

    // Set the main layout for the central widget
    centralWidget->setLayout(mainLayout);

    // Set the main widget in application
    setCentralWidget(centralWidget);

    // Start application in maximized view
    showMaximized();

    // Set the application window title
    setWindowTitle("Wilbur");
};

//Destructor Wilbur - Main Window
WilburApplicationView::~WilburApplicationView()
{
}