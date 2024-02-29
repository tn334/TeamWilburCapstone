#pragma once

// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WILBURMAINWINDOWVIEW_H
#define WILBURMAINWINDOWVIEW_H

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

class WilburMainWindowView : public QMainWindow
{
    Q_OBJECT

public:
    WilburMainWindowView(QWidget *parent = nullptr, int simulatorMode = 1);
    ~WilburMainWindowView();

private:
    NavigationBar* navigationBar;
};

#endif // WILBURMAINWINDOWVIEW_H