// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local header files
#include "Wilbur.h"
#include "controlBox.h"
#include "navigationBar.h" //Nav Bar at Top of Window
#include "customDialog.h" // Simulation Window
#include "bluetoothButton.h"


//Qt Header Files
#include <QPlainTextEdit>
#include <QWidget>
#include <QContextMenuEvent>
#include <QLabel>
#include <QMessageBox>
#include <QSlider>
#include <QVBoxLayout>
#include <QStackedWidget>

// setting up Qt version through Qt Visual Studio Tools
// https://doc.qt.io/qtvstools/qtvstools-how-to-add-qt-versions.html
// setting Qt version for project 
// https://doc.qt.io/qtvstools/qtvstools-how-to-select-qt-versions-for-project.html

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{ 
    // Set up the main layout
    QVBoxLayout* mainLayout = new QVBoxLayout;

    // Instantiate Navigation Bar at top of window
    NavigationBar* navigationBar = new NavigationBar(this);
    //navigationBar->setMaximumHeight(100);
    mainLayout->addWidget(navigationBar);

    ControlBox* roboControl = new ControlBox(this);
    //roboControl->setMaximumSize(roboControl->sizeHint());
    mainLayout->addWidget(roboControl);

    // Set the main layout for the central widget
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

    mainLayout->setContentsMargins(0, 0, 0, 0);
    //centralWidget->layout()->setContentsMargins(0, 0, 0, 0);

    setCentralWidget(centralWidget);

    showMaximized();
    setWindowTitle(tr("WilburMain", "Wilbur"));
}

//Destructor Wilbur - Main Windor
MainWindow::~MainWindow()
{
    
}

void MainWindow::updateTextEdit(const QString& string)
{
    QTextEdit* textEdit = findChild<QTextEdit*>();
    textEdit->append(string);
}


