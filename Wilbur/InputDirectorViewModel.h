#pragma once
#ifndef INPUTDIRECTORVIEWMODEL_H
#define INPUTDIRECTORVIEWMODEL_H

#include "SimulatorModel.h"

enum buttonType {
	PUMP = 0, VALVE1, VALVE2, VALVE3, CONNECT
};

class InputDirectorViewModel
{
public:
	InputDirectorViewModel();

	InputDirectorViewModel(bool simState);

	bool handleInput(enum buttonType, int newValue);

private:

	bool simulatorMode;

	SimulatorModel simObject;

};

#endif // INPUTDIRECTORVIEWMODEL_H
