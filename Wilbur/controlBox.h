#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CONTROLBOX_H
#define CONTROLBOX_H

// Local Headers
#include "sliderLayout.h"
#include "ductLayout.h" // ductButton.h, QLabel included in ductLayout.
#include "button.h" // QToolButton included in button.h
#include "customDialog.h" // QLabel, QMainWindow included in customDialog.h
#include "demoSimulator.h" 
#include "bluetoothButton.h"
#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

class ControlBox : public QMainWindow
{
	Q_OBJECT

public:
	ControlBox(QWidget *parent = nullptr);
	~ControlBox();

	//QSize sizeHint() const override;

public slots:
	void controlManipulated(std::string objectName, int newValue);
	void handleButtonPressed(int valveNumber);
	/*void handleSliderValueChanged(int value);*/

private slots:
	//void buttonClicked();

private:
	// objects
	BluetoothButton* bluetooth;
	DuctLayout* ductLayout;
	Button* buttonOne;
	Button* buttonTwo;
	Button* buttonThree;
	SliderLayout* sliderLayout;
	//StiffnessSlider* stiffnessSlider;

	// instances
	DemoSimulator demoSimulator;
	CustomDialog* customDialog;
	template<typename PointerToMemberFunction>
	Button* createButton(const QString& text, const PointerToMemberFunction& member);
	/*StiffnessSlider* createSlider(const QString& title, const QString& objectName);*/

	// controller label
	QLabel* controlLabel;
};

#endif // CONTROLBOX_H