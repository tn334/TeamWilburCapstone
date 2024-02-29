#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include "StringBuilderViewModel.h"
#include "ActionLogModel.h"
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
	CustomDialog(QWidget* parent = nullptr, ActionLogModel* actionLog = nullptr);

public slots:
	void controlManipulated(std::string objectName, int newValue);

private:
	void initUI();
	StringBuilderViewModel textHandler;
	QTextEdit* textEdit;
	ActionLogModel* logPtr;
};

#endif // CUSTOMDIALOG_H

