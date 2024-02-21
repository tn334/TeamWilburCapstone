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
    // Set up the main layout
    QGridLayout* mainLayout = new QGridLayout;

    // Instantiate Navigation Bar at top of window
    NavigationBar* navigationBar = new NavigationBar(this);

	// Instantiate Robot Control Box
    ControlBox* robotControl = new ControlBox(this);
    
	// Instantiate Central Widget "holder"
    QWidget* centralWidget = new QWidget(this);

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
}

//Destructor Wilbur - Main Window
MainWindow::~MainWindow()
{
}