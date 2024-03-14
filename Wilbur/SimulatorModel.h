#pragma once

#ifndef SIMULATORMODEL_H
#define SIMULATORMODEL_H

// Header Files
#include "EnumsAndConstants.h"

#include <sstream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

class SimValve 
{
public:

    SimValve();

    SimValve(bool startingState);

    bool setState(bool stateToBe);

    bool getState();

    std::string stringState();

private:
    bool state;
};

class SimPump 
{
public:

    SimPump();

    SimPump(pumpValue startingStiffness, pumpValue minVal, pumpValue maxVal);

    bool setStiffness(pumpValue newStiffness);

    pumpValue getStiffness();
    std::string percentStiffness();

private:
    pumpValue stiffness;
    pumpValue minimumVal = OFF;
    pumpValue maximumVal = HIGH;

};

class SimulatorModel
{
public:

    SimulatorModel();

    SimulatorModel(int numValves);

    bool setValve(int valveToSet, bool stateToSet);

    bool setPump(pumpValue stiffnessToSet);

    std::string displayState();

private:
    SimPump pneumaticPump;
    std::vector<SimValve> valveList;
    int numValves;
};

#endif // SIMULATORMODEL_H