#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

//Header files
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include "ui_Wilbur.h"
#include <QGridLayout>

// for menu
QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class NavigationBar : public QMainWindow
{
    Q_OBJECT

public:
    NavigationBar(QWidget* parent = nullptr);
    ~NavigationBar();
    //initialize visocity slider
    //SlidersGroup *horizontalSliders;
    //void createMenus();

protected:
    // Context Menu
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent* event) override;
#endif // QT_NO_CONTEXTMENU

    //menuBar slots
private slots:
    void newFile();
    void open();
    void save();
    void print();
    void copy();
    void about();
    void aboutQt();

private:
    // MenuBar
    void createActions();
    void createMenus();
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;
    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* printAct;
    QAction* copyAct;
    QAction* exitAct;
    QLabel* infoLabel;
    QAction* aboutAct;
    QAction* aboutQtAct;
    Ui::WilburClass ui;
    // controller
    QLabel* controlLabel;
};

#endif // NAVIGATIONBAR_H