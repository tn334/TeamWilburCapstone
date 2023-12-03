#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WILBUR_H
#define WILBUR_H

//Header files
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include "ui_Wilbur.h"
#include <QPlainTextEdit>
#include <QGridLayout>

// for menu
QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printToConsole(const QString& message);

private:
    QPlainTextEdit* consoleOutput;
};

class ParamGrid : public QGridLayout, MainWindow
{
    //What is this
    Q_OBJECT

public:
    //Constructor
    ParamGrid(QWidget *parent = nullptr);
    //Deconstructor
    ~ParamGrid();

private:
    
};

#endif // WILBUR_H