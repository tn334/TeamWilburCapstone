#pragma once
#ifndef INPUTDIRECTOR_H
#define INPUTDIRECTOR_H

#include "demoSimulator.h"

enum buttonType {
	PUMP = 0, VALVE1, VALVE2, VALVE3, CONNECT
};

class InputDirector
{
public:
	InputDirector();

	InputDirector(bool simState);

	bool handleInput(enum buttonType, int newValue);

private:

	bool simulatorMode;

	DemoSimulator simObject;

};

#endif // INPUTDIRECTOR_H
