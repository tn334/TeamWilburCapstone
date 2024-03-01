#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

//Header files
#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QContextMenuEvent>
#include <QLabel>
#include <QMessageBox>
#include "ui_wilbur.h"
#include "ActionLogModel.h"

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
    NavigationBar(QWidget* parent = nullptr, ActionLogModel* actionLog = nullptr);
    ~NavigationBar();

protected:
    // Context Menu
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent* event) override;
#endif // QT_NO_CONTEXTMENU

    //menuBar slots
private slots:
    void newFile();
    void exportLog();
    void save();
    void print();
    void copy();
	void darkMode();
    void about();
    void aboutQt();

private:
    // MenuBar
    void createActions();
    void createMenus();
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;
	QMenu* viewMenu;
    QAction* newAct;
    QAction* ExportLog;
    QAction* saveAct;
    QAction* printAct;
    QAction* copyAct;
    QAction* exitAct;
    QAction* aboutAct;
    QAction* aboutQtAct;
	QAction* darkModeAct;
    QLabel* infoLabel;
    Ui::WilburClass ui;
    QLabel* controlLabel;
	ActionLogModel* logPtr;
};

#endif // NAVIGATIONBAR_H