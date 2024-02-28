#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef PROTOTYPECONTROLLERVIEW_H
#define PROTOTYPECONTROLLERVIEW_H

// Local Headers
#include "button.h" // QToolButton included in button.h
#include "bluetoothButtonView.h"
#include "sliderLayout.h" // QSlider is included in file
#include "ductLayoutView.h"
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

class PrototypeControllerView : public QMainWindow
{
	Q_OBJECT

public:
	// constructor
	PrototypeControllerView(QWidget* parent = nullptr, ActionLogging* actionLog = nullptr, InputDirector* inputDirector = nullptr);
	// destructor
	~PrototypeControllerView();

	// define executeControl
	void executeControl(buttonType button, int newValue);

private:
	// objects
	BluetoothButtonView* bluetooth;
	SliderLayout* sliderLayout;
	DuctLayoutView* ductLayout;

	// instances
	DemoSimulator demoSimulator;
	InputDirector* director;
	CustomDialog* customDialog;
	template<typename PointerToMemberFunction>
	Button* createButton(const QString& text, const PointerToMemberFunction& member);

	// controller label
	QLabel* controlLabel;
};

#endif // PROTOTYPECONTROLLERVIEW_H