#pragma once

#ifndef DEMOSIMULATOR_H
#define DEMOSIMULATOR_H

#include <iostream>
#include <vector>
#define OPEN true
#define CLOSED false

enum pumpValue {
    OFF=0, LOW, MED, HIGH
};

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

    SimPump(pumpValue startingStiffness, pumpValue minVal, pumpValue maxVal);

    bool setStiffness(pumpValue newStiffness);

    pumpValue getStiffness();
    std::string percentStiffness();

private:
    pumpValue stiffness;
    pumpValue minimumVal = OFF;
    pumpValue maximumVal = HIGH;

};

class DemoSimulator
{
public:

    DemoSimulator();

    DemoSimulator(int numValves);

    bool setValve(int valveToSet, bool stateToSet);

    bool setPump(pumpValue stiffnessToSet);

    std::string displayState();

private:
    SimPump pneumaticPump;
    std::vector<SimValve> valveList;
    int numValves;
};

#endif // DEMOSIMULATOR_H