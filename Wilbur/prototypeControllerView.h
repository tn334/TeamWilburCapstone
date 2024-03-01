#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef PROTOTYPECONTROLLERVIEW_H
#define PROTOTYPECONTROLLERVIEW_H

// Local Headers
#include "BluetoothLayoutView.h"
#include "SliderLayoutView.h" // QSlider is included in file
#include "DuctLayoutView.h" // DuctButtonView and QAbstractButton included
#include "customDialog.h" // QLabel, QMainWindow included in customDialog.h
#include "ActionLogModel.h"
#include "InputDirectorViewModel.h"

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
	PrototypeControllerView(QWidget* parent = nullptr, ActionLogModel* actionLog = nullptr, InputDirectorViewModel* inputDirector = nullptr);
	// destructor
	~PrototypeControllerView();

	// define executeControl
	void executeControl(buttonType button, int newValue);

private:
	// objects
	BluetoothLayoutView* bluetoothLayout;
	SliderLayoutView* sliderLayout;
	DuctLayoutView* ductLayout;

	// instances
	SimulatorModel demoSimulator;
	InputDirectorViewModel* director;
	CustomDialog* customDialog;

	// controller label
	QLabel* controlLabel;
};

#endif // PROTOTYPECONTROLLERVIEW_H