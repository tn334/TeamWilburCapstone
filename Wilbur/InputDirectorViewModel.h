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
#include <QDebug>

class InputDirectorViewModel
{
public:
	InputDirectorViewModel();

	InputDirectorViewModel(bool simState, QWidget* QParent = nullptr);

	friend class TestInputDirector;

	bool handleInput(enum buttonType, int newState, std::string objectName);

private:
	bool simulatorMode;

	SimOutputViewModel* simOutput;

	SimulatorModel simObject;

	SerialConnection* serialClient;
};

#endif // INPUTDIRECTORVIEWMODEL_H
