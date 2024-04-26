#pragma once

// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WILBURAPPLICATIONVIEW_H
#define WILBURAPPLICATIONVIEW_H

// Header files
#include "ActionLogModel.h"
#include "ActionLogView.h"
#include "PrototypeControllerView.h"
#include "MenuBarView.h"
#include "SimOutputViewModel.h" // Simulation Window

#include <QWidget>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QApplication>	
#include <QHideEvent>
#include <QLabel>
#include <QMessageBox>
#include <QShowEvent>
#include <QSlider>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QToolBar>

class WilburApplicationView : public QMainWindow
{
    Q_OBJECT

public:
    WilburApplicationView(QWidget *parent = nullptr, int simulatorMode = 1);
    ~WilburApplicationView();

    friend class TestWilburApplicationView;

    friend class TestInputDirector;

    ActionLogModel* getActionLog() const { return actionLog; };
    ActionLogView* getActionLogDisplay() const { return actionLogDisplay; };
    InputDirectorViewModel* getInputDirector() const { return inputDirector; };
    MenuBarView* getMenuBar() const { return menuBar; };
    PrototypeControllerView* getRobotControl() const { return robotControl; };
    QWidget* getCentralWidget() const { return centralWidget; };
private:
    // Instantiate objects
        // widget layout
    QGridLayout* mainLayout;

    // Custom widgets
    ActionLogModel* actionLog; // log of button presses
    ActionLogView* actionLogDisplay; // in app view of log

    InputDirectorViewModel* inputDirector; // handles control of button presses

    MenuBarView* menuBar; // menu bar at top of application

    PrototypeControllerView* robotControl; // widget containing connection, switch control, and stiffness slider
    
    QWidget* centralWidget;

    //void resizeEvent(QResizeEvent* event);
    void toggleActionLogDisplay(bool visible);
};

#endif // WILBURAPPLICATIONVIEW_H