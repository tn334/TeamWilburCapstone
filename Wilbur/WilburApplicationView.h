#pragma once

// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WILBURAPPLICATIONVIEW_H
#define WILBURAPPLICATIONVIEW_H

// Header files
#include "actionLogging.h"
#include "prototypeControllerView.h"
#include "navigationBar.h" //Nav Bar at Top of Window
#include "customDialog.h" // Simulation Window
#include <QWidget>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QApplication>	
#include <QLabel>
#include <QMessageBox>
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
private:
    QGridLayout* mainLayout;
    ActionLogging* actionLog;
    InputDirector* inputDirector;
    NavigationBar* navigationBar;
    PrototypeControllerView* robotControl;
    QWidget* centralWidget;
};

#endif // WILBURAPPLICATIONVIEW_H