#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CONTROLBOX_H
#define CONTROLBOX_H

#include "horizontalSlider.h"
#include "button.h"
// Qt header files
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

//protected:

private:
	template<typename PointerToMemberFunction>
	Button* createButton(const QString& text, const PointerToMemberFunction& member);
	void buttonClicked();
	// controller
	QLabel* controlLabel;
	QLabel* minimumLabel;
	QLabel* maximumLabel;
	QLabel* valueLabel;



};

#endif // CONTROLBOX_H