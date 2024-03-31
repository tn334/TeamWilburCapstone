#pragma once
#ifndef INPUTDIRECTORVIEWMODELBT_H
#define INPUTDIRECTORVIEWMODELBT_H

#include "SimulatorModel.h"
#include "SimOutputViewModel.h"
#include "BluetoothClientViewModel.h"
#include "SerialConnection.h"

#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

class InputDirectorViewModelBT
{
public:
	InputDirectorViewModelBT();

	InputDirectorViewModelBT(bool simState, QWidget* QParent = nullptr);

	bool handleInput(enum buttonType, int newValue, std::string objectName);

private:
	bool simulatorMode;

	SimOutputViewModel* simOutput;

	SimulatorModel simObject;

	BluetoothClient* btClient;

	SerialConnection* serialClient;

	QWidget* QParent;
};

#endif // INPUTDIRECTORVIEWMODELBT_H