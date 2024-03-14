#pragma once
#ifndef INPUTDIRECTORVIEWMODEL_H
#define INPUTDIRECTORVIEWMODEL_H

#include "SimulatorModel.h"
#include "SimOutputViewModel.h"

#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

class InputDirectorViewModel
{
public:
	InputDirectorViewModel();

	InputDirectorViewModel(bool simState, QWidget* simOutputParent = nullptr);

	bool handleInput(enum buttonType, int newValue, std::string objectName);

	// FUNCTION COMMENTED, NO USE DECLARED AS OF NOW (ADRIEL)
	// bool handleInput(enum buttonType, double newValue, std::string objectName);

private:

	bool simulatorMode;

	SimOutputViewModel* simOutput;

	SimulatorModel simObject;

};

#endif // INPUTDIRECTORVIEWMODEL_H
