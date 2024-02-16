// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Include header files
//Local
#include "navigationBar.h"
// Qt Header Files
#include <QWidget>
#include <QContextMenuEvent>
#include <QLabel>
#include <QMessageBox>
#include <QSlider>
#include <QStackedWidget>

// setting up Qt version through Qt Visual Studio Tools
// https://doc.qt.io/qtvstools/qtvstools-how-to-add-qt-versions.html
// setting Qt version for project 
// https://doc.qt.io/qtvstools/qtvstools-how-to-select-qt-versions-for-project.html

NavigationBar::NavigationBar(QWidget* parent)
{

    // Create a wrapper a holder for the menubar
    //cite: https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/mainwindows/menus?h=6.6
    QWidget* menuBar = new QWidget;
    setCentralWidget(menuBar);
    QWidget* topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option."));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget* bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QGridLayout* menuLayout = new QGridLayout;
    //menuLayout->setContentsMargins(5, 5, 5, 5);
    menuLayout->addWidget(topFiller, 0, 0, 1, 1);
    menuLayout->addWidget(infoLabel, 1, 0, 1, 1, Qt::AlignCenter);
    //menuLayout->addWidget(bottomFiller, 2, 0, 1, 1);

    menuLayout->setSizeConstraint(QLayout::SetFixedSize);
    menuBar->setLayout(menuLayout);

    createActions();
    createMenus();

    

}

//Destructor Wilbur - Main Windor
NavigationBar::~NavigationBar()
{

}

#ifndef QT_NO_CONTEXTMENU
void NavigationBar::contextMenuEvent(QContextMenuEvent* event)
{
    //implementation of context menu
    QMenu menu(this);
    //menu.addAction(cutAct);
    menu.addAction(copyAct);
    //menu.addAction(pasteAct);
    menu.exec(event->globalPos());


}
#endif // QT_NO_CONTEXTMENU
void NavigationBar::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void NavigationBar::exportLog()
{
    infoLabel->setText(tr("Invoked <b>File|Export Logn</b>"));
}

void NavigationBar::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void NavigationBar::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
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

void NavigationBar::createActions()
{
    //create new file
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &NavigationBar::newFile);
    //exportLog existing file
    ExportLog = new QAction(tr("&Export Log..."), this);
    ExportLog->setShortcuts(QKeySequence::SaveAs);
    ExportLog->setStatusTip(tr("Export control log"));
    connect(ExportLog, &QAction::triggered, this, &NavigationBar::exportLog);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the log to disk"));
    connect(saveAct, &QAction::triggered, this, &NavigationBar::save);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the log"));
    connect(printAct, &QAction::triggered, this, &NavigationBar::print);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
        "clipboard"));
    connect(copyAct, &QAction::triggered, this, &NavigationBar::copy);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &NavigationBar::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &NavigationBar::aboutQt);

}

void NavigationBar::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(ExportLog);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    //editMenu->addAction(undoAct);
    //editMenu->addAction(redoAct);
    //editMenu->addSeparator();
    //editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    //editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);


}