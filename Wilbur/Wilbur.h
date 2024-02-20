#pragma once

// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WILBUR_H
#define WILBUR_H

// Header files
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void printToConsole(const QString& message);

    //private:
    //    QPlainTextEdit* consoleOutput;
};

#endif // WILBUR_H