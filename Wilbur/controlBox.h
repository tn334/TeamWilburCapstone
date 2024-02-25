#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CONTROLBOX_H
#define CONTROLBOX_H

// Local Headers
#include "button.h" // QToolButton included in button.h
#include "bluetoothButton.h"
#include "sliderLayout.h" // QSlider is included in file
#include "ductLayout.h"
#include "customDialog.h" // QLabel, QMainWindow included in customDialog.h
#include "demoSimulator.h" 
#include "actionLogging.h"
#include "inputDirector.h"

#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

//forward declaration of buttonType enum
enum buttonType;

class ControlBox : public QMainWindow
{
	Q_OBJECT

public:
	// constructor
	ControlBox(QWidget* parent = nullptr, ActionLogging* actionLog = nullptr, InputDirector* inputDirector = nullptr);
	// destructor
	~ControlBox();

	// define executeControl
	void executeControl(buttonType button, int newValue);

private:
	// objects
	BluetoothButton* bluetooth;
	Button* buttonOne;
	Button* buttonTwo;
	Button* buttonThree;
	SliderLayout* sliderLayout;
	DuctLayout* ductLayout;

	// instances
	DemoSimulator demoSimulator;
	InputDirector* director;
	CustomDialog* customDialog;
	template<typename PointerToMemberFunction>
	Button* createButton(const QString& text, const PointerToMemberFunction& member);

	// controller label
	QLabel* controlLabel;
};

#endif // CONTROLBOX_H