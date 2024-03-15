#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include "IStringBuilder.h"
#include "ActionLogModel.h"
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QStringList>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>

class SimStringBuilder : IStringBuilder 
{
public:
	void buildStringAndAppend(std::string objectName, int newValue);

	QStringList getAllText() const;

private:
	// List that holds all texts
	QStringList textList;
	QString objectText;
};

class SimOutputViewModel : public QDialog
{
	Q_OBJECT

public:
	SimOutputViewModel(QWidget* parent = nullptr);

public slots:
	void appendActionString(std::string objectName, int newValue);

private:
	void initUI();
	SimStringBuilder stringBuilder;
	QTextEdit* textEdit;
};

#endif // CUSTOMDIALOG_H

