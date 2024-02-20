// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local header files
#include "Wilbur.h"
#include "controlBox.h"
#include "navigationBar.h" //Nav Bar at Top of Window
#include "customDialog.h" // Simulation Window

// setting up Qt version through Qt Visual Studio Tools
// https://doc.qt.io/qtvstools/qtvstools-how-to-add-qt-versions.html
// setting Qt version for project 
// https://doc.qt.io/qtvstools/qtvstools-how-to-select-qt-versions-for-project.html

// Main Window Class
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{ 
    // Instantiate Navigation Bar at top of window
    NavigationBar* navigationBar = new NavigationBar(this);

<<<<<<< Updated upstream
    // Instantiate Controller
    ControlBox* roboControl = new ControlBox(this);

    // Spacer item for bottom of window
    QSpacerItem* verticalSpacer = new QSpacerItem(0, 20, QSizePolicy::Minimum, 
        QSizePolicy::Expanding);

    // Set up the main layout
    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(navigationBar, 0, 0, 1, 6);
    mainLayout->addWidget(roboControl, 1, 0, 1, 3);
    mainLayout->addItem(verticalSpacer, 2, 0, 1, 6);
 // Align the main layout to the top left corner
=======
	// Instantiate Robot Control Box
    ControlBox* robotControl = new ControlBox(this);
    
	// Instantiate Central Widget "holder"
    QWidget* centralWidget = new QWidget(this);

	// At main layout, add navigation bar and robot control box widgets
    mainLayout->addWidget(navigationBar);
    mainLayout->addWidget(robotControl);
>>>>>>> Stashed changes

    // Set the main layout for the central widget
    centralWidget->setLayout(mainLayout);

<<<<<<< Updated upstream
=======
	// Set the main widget in application
>>>>>>> Stashed changes
    setCentralWidget(centralWidget);

	// Start application in maximized view
    showMaximized();

	// Set the application window title
    setWindowTitle("Wilbur");
}

//Destructor Wilbur - Main Window
MainWindow::~MainWindow()
{
}