#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CONTROLBOX_H
#define CONTROLBOX_H

// Local Headers
#include "horizontalSlider.h"
#include "button.h"
#include "customDialog.h"

// Qt Remote Headers
#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QMainWindow>

class ControlBox : public QMainWindow
{
	Q_OBJECT

public:
	ControlBox(QWidget *parent = nullptr);
	~ControlBox();

public slots:
	void controlManipulated();

private slots:
	void buttonClicked();

private:
	CustomDialog* customDialog;
	template<typename PointerToMemberFunction>
	Button* createButton(const QString& text, const PointerToMemberFunction& member);
	/*void buttonClicked();*/
	// controller
	QLabel* controlLabel;
	QLabel* minimumLabel;
	QLabel* maximumLabel;
	QLabel* valueLabel;

};

#endif // CONTROLBOX_H