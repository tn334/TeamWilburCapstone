#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include "textHandler.h"
#include "actionLogging.h"
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QStringList>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>

class CustomDialog : public QDialog
{
	Q_OBJECT

public:
	CustomDialog(QWidget* parent = nullptr, ActionLogging* actionLog = nullptr);

public slots:
	void controlManipulated(std::string objectName, bool currentState, int valueChanged);
	//void controlManipulated();

private:
	void initUI();
	TextHandler textHandler;
	QTextEdit* textEdit;
	ActionLogging* logPtr;
};

#endif // CUSTOMDIALOG_H

