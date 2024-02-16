#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CONTROLBOX_H
#define CONTROLBOX_H

// Local Headers
#include "sliderLayout.h"
#include "button.h"
#include "ductButton.h"
#include "customDialog.h"
#include "demoSimulator.h"

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

	//QSize sizeHint() const override;

public slots:
	void controlManipulated(std::string objectName, int newValue);
	void handleButtonPressed(int valveNumber);
	void handleSliderValueChanged(int value);

private slots:
	//void buttonClicked();

private:
	// objects
	DuctButton* ductTestButton;
	Button* buttonOne;
	Button* buttonTwo;
	Button* buttonThree;
	//StiffnessSlider* stiffnessSlider;
	SliderLayout* sliderLayout;

	// instances
	DemoSimulator demoSimulator;
	CustomDialog* customDialog;
	template<typename PointerToMemberFunction>
	Button* createButton(const QString& text, const PointerToMemberFunction& member);
	StiffnessSlider* createSlider(const QString& title, const QString& objectName);

	// controller
	QLabel* controlLabel;


};

#endif // CONTROLBOX_H