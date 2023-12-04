#include "demoSimulator.h"

#include <sstream>
#include "demoSimulator.h"
#include <Windows.h>

// Declare the Sleep function explicitly
extern "C" void __stdcall Sleep(unsigned long dwMilliseconds);
#include <stdlib.h>
#include <time.h>
#define OPEN true
#define CLOSED false

using namespace std;

// Pump

SimPump::SimPump() : stiffness(0), minimumVal(0), maximumVal(1) {}

SimPump::SimPump(float startingStiffness, float minVal, float maxVal) :
    stiffness(startingStiffness), minimumVal(minVal), maximumVal(maxVal) {}

bool SimPump::setStiffness(float newStiffness) {
    if (newStiffness >= minimumVal && newStiffness <= maximumVal) {
        Sleep(((rand() % 3) + 1) * 1000);
        stiffness = newStiffness;
        return true;
    }
    return false;
}

float SimPump::getStiffness() {
    return stiffness;
}

string SimPump::percentStiffness() {
    int percentStiffness = (int)(stiffness * 100);
    return (to_string(percentStiffness) + "%");
}

//Duct System Controls

SimValve::SimValve() : state(CLOSED) {}

SimValve::SimValve(bool startingState) : state(startingState) {}

bool SimValve::setState(bool stateToBe) {
    if (stateToBe != state) {
        Sleep(((rand() % 3) + 1) * 1000);
        state = stateToBe;
    }
    return true;
}

bool SimValve::getState() {
    return state;
}

string SimValve::stringState() {
    if (state) {
        return "open";
    }
    else {
        return "closed";
    }
}

DemoSimulator::DemoSimulator() {
    srand(time(NULL));
    numValves = 3;
    pneumaticPump = SimPump();
    for (int i = 0; i < 3; i++) {
        valveList.push_back(SimValve());
    }
}

DemoSimulator::DemoSimulator(int numValves) : numValves(numValves) {
    srand(time(NULL));
    pneumaticPump = SimPump();
    for (int i = 0; i < numValves; i++) {
        valveList.push_back(SimValve());
    }
}

bool DemoSimulator::setValve(int valveToSet, bool stateToSet) {
    if (valveToSet > -1 && valveToSet < valveList.size()) {
        return valveList.at(valveToSet).setState(stateToSet);
    }
    return false;
}

bool DemoSimulator::setPump(float stiffnessToSet) {
    return pneumaticPump.setStiffness(stiffnessToSet);
}

string DemoSimulator::displayState() {
    stringstream builtString;
    builtString << "Simulator Component Status:" << endl;
    builtString << "    Pump stiffness: " << pneumaticPump.percentStiffness() << endl;
    for (int i = 0; i < numValves; i++) {
        builtString << "    Valve " << i << " state: " << valveList.at(i).stringState() << endl;
    }
    return builtString.str();
}

