#pragma once

// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WILBUR_H
#define WILBUR_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, int simulatorMode = 1);
    ~MainWindow();
};

#endif // WILBUR_H