#pragma once

#ifndef DEMOSIMULATOR_H
#define DEMOSIMULATOR_H

#include <iostream>
#include <vector>
#define OPEN true
#define CLOSED false

class SimValve {
public:

    SimValve();

    SimValve(bool startingState);

    bool setState(bool stateToBe);

    bool getState();

    std::string stringState();

private:
    bool state;
};

class SimPump {
public:

    SimPump();

    SimPump(float startingStiffness, float minVal, float maxVal);

    bool setStiffness(float newStiffness);

    float getStiffness();
    std::string percentStiffness();

private:
    float stiffness;
    float minimumVal;
    float maximumVal;

};

class DemoSimulator
{
public:

    DemoSimulator();

    DemoSimulator(int numValves);

    bool setValve(int valveToSet, bool stateToSet);

    bool setPump(float stiffnessToSet);

    std::string displayState();

private:
    SimPump pneumaticPump;
    std::vector<SimValve> valveList;
    int numValves;
};

#endif // DEMOSIMULATOR_H