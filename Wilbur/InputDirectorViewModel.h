#pragma once
#ifndef INPUTDIRECTORVIEWMODEL_H
#define INPUTDIRECTORVIEWMODEL_H

#include "SimulatorModel.h"
#include "SimOutputViewModel.h"
#include "BluetoothClientViewModel.h"
#include "SerialConnection.h"

#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

class InputDirectorViewModel
{
public:
	InputDirectorViewModel();

	InputDirectorViewModel(bool simState, QWidget* QParent = nullptr);

	bool handleInput(enum buttonType, int newValue, std::string objectName);

private:
	bool simulatorMode;

	SimOutputViewModel* simOutput;

	SimulatorModel simObject;

	BluetoothClient* btClient;

	SerialConnection* serialClient;

	QWidget* QParent;
};

#endif // INPUTDIRECTORVIEWMODEL_H
