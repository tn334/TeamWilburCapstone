#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef PROTOTYPECONTROLLERVIEW_H
#define PROTOTYPECONTROLLERVIEW_H

// Local Headers
#include "ConnectionLayoutView.h"
#include "SliderLayoutView.h" // QSlider is included in file
#include "DuctLayoutView.h" // DuctButtonView and QAbstractButton included
#include "SimOutputViewModel.h" // QLabel, QMainWindow included in SimOutputViewModel.h
#include "ActionLogModel.h"
#include "InputDirectorViewModel.h"

#include <QFrame>
#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

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
	void executeFlowRateControl(buttonType button, double newValue);

private:
	// objects
	ConnectionLayoutView* connectionLayout;
	SliderLayoutView* sliderLayout;
	DuctLayoutView* ductLayout;

	// instances
	SimulatorModel demoSimulator;
	InputDirectorViewModel* director;
	ActionLogModel* actionLog;
	SimOutputViewModel* simOutput;

	// controller label
	QLabel* controlLabel;
};

#endif // PROTOTYPECONTROLLERVIEW_H