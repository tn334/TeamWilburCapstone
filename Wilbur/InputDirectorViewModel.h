#pragma once
#ifndef INPUTDIRECTORVIEWMODEL_H
#define INPUTDIRECTORVIEWMODEL_H

#include "SimulatorModel.h"
#include "SimOutputViewModel.h"

#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

enum buttonType {
	PUMP = 0, VALVE1, VALVE2, VALVE3, CONNECT
};

class InputDirectorViewModel
{
public:
	InputDirectorViewModel();

	InputDirectorViewModel(bool simState, QWidget* simOutputParent = nullptr);

	bool handleInput(enum buttonType, int newValue, std::string objectName);

private:

	bool simulatorMode;

	SimOutputViewModel* simOutput;

	SimulatorModel simObject;

};

#endif // INPUTDIRECTORVIEWMODEL_H
