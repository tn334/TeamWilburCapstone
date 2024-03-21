// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Include header files
//Local
#include "navigationBar.h"

// setting up Qt version through Qt Visual Studio Tools
// https://doc.qt.io/qtvstools/qtvstools-how-to-add-qt-versions.html
// setting Qt version for project 
// https://doc.qt.io/qtvstools/qtvstools-how-to-select-qt-versions-for-project.html

// NavigationBar Constructor
NavigationBar::NavigationBar(QWidget* parent, ActionLogModel* actionLog)
{
    // Create a wrapper a holder for the menubar
    //cite: https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/mainwindows/menus?h=6.6

    this->setStyleSheet("background-color: #666666;");

	// Instantiate bar and fillers as widgets
    QWidget* menuBar = new QWidget;

	// Instantiate layout
    QGridLayout* menuLayout = new QGridLayout;

	// Set logPtr to action log
	logPtr = actionLog;

	// Set menu bar as main widget
    setCentralWidget(menuBar);

	// Create label and set its style and alignment
    infoLabel = new QLabel(tr("<i>Choose a menu option."));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

	// Set menu margins and add label
    menuLayout->setContentsMargins(0, 0, 0, 0);
    menuLayout->addWidget(infoLabel, 1, 0, 1, 1);

	// Set menu size constraints to a fixed size
    menuLayout->setSizeConstraint(QLayout::SetFixedSize);

	// Set menu bar layout to follow the main menu layout values/settings
    menuBar->setLayout(menuLayout);

	// Create navigation bar actions for every menu option
    createActions();

	// Create menu options in navigation bar
    createMenus();
}

//Destructor Wilbur - Main Windor
NavigationBar::~NavigationBar()
{
}

// MenuEvent that allows use of keyboard shortcuts
void NavigationBar::contextMenuEvent(QContextMenuEvent* event)
{
    // Instantiate menu
    QMenu menu(this);
	// Allow for copy to be done using shortcut (CTRL+C presumably)
    menu.addAction(copyAct);
	
	// Find where the copy is being used in global position/screen
    menu.exec(event->globalPos());
}

// Actions to execute when action is clicked
void NavigationBar::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void NavigationBar::exportLog()
{
    infoLabel->setText(tr("Invoked <b>File|Export Logn</b>"));
	logPtr->exportLog();
}

void NavigationBar::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void NavigationBar::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void NavigationBar::darkMode()
{
	infoLabel->setText("Invoked <b>Changed to dark mode<\b>");
}

void NavigationBar::print()
{
    infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void NavigationBar::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
        tr("The <b>Menu</b> example shows how to create "
            "menu-bar menus and context menus."));
}

void NavigationBar::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}

// Create actions for menus
void NavigationBar::createActions()
{
    //create new file
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &NavigationBar::newFile);
	
    //export existing file
    ExportLog = new QAction(tr("&Export Log..."), this);
    ExportLog->setShortcuts(QKeySequence::SaveAs);
    ExportLog->setStatusTip(tr("Export control log"));
    connect(ExportLog, &QAction::triggered, this, &NavigationBar::exportLog);

	//save existing file
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the log to disk"));
    connect(saveAct, &QAction::triggered, this, &NavigationBar::save);

	//print existing file
    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the log"));
    connect(printAct, &QAction::triggered, this, &NavigationBar::print);

	//copy text from file
    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
        "clipboard"));
    connect(copyAct, &QAction::triggered, this, &NavigationBar::copy);

	//exit application
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

	//dark mode
	darkModeAct = new QAction("Dark Mode", this);
	darkModeAct->setStatusTip("no");
	darkModeAct->setCheckable(true);
	connect(darkModeAct, &QAction::triggered, this, &NavigationBar::darkMode);

	//about application guide
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &NavigationBar::about);

	//about Qt guide
    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &NavigationBar::aboutQt);
}

// Create menus for actions
void NavigationBar::createMenus()
{
	// Create file menu and its actions
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(ExportLog);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

	// Create edit menu and its actions
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(copyAct);
    editMenu->addSeparator();

	// Create view menu and its actions
	viewMenu = menuBar()->addMenu("View");
	viewMenu->addAction(darkModeAct);

	// Create help menu and its actions
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}