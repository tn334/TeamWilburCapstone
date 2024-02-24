#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CONTROLBOX_H
#define CONTROLBOX_H

// Local Headers
#include "sliderLayout.h"
#include "button.h" // QToolButton included in button.h
#include "customDialog.h" // QLabel, QMainWindow included in customDialog.h
#include "demoSimulator.h" 
#include "bluetoothButton.h"
#include "actionLogging.h"
#include "inputDirector.h"
#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

class ControlBox : public QMainWindow
{
	Q_OBJECT

public:
	ControlBox(QWidget* parent = nullptr, ActionLogging* actionLog = nullptr, InputDirector* inputDirector = nullptr);
	~ControlBox();

	//QSize sizeHint() const override;

public slots:
	void controlManipulated(buttonType button, int newValue);
	/*void handleSliderValueChanged(int value);*/

private slots:
	//void buttonClicked();

private:
	// objects
	BluetoothButton* bluetooth;
	Button* buttonOne;
	Button* buttonTwo;
	Button* buttonThree;
	SliderLayout* sliderLayout;
	//StiffnessSlider* stiffnessSlider;

	// instances
	DemoSimulator demoSimulator;
	InputDirector* director;
	CustomDialog* customDialog;
	template<typename PointerToMemberFunction>
	Button* createButton(const QString& text, const PointerToMemberFunction& member);
	/*StiffnessSlider* createSlider(const QString& title, const QString& objectName);*/

	// controller label
	QLabel* controlLabel;
};

#endif // CONTROLBOX_H