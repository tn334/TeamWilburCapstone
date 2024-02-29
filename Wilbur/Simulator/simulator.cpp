#include <iostream>
#include <vector>
#include "simulator.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#define OPEN true
#define CLOSED false

using namespace std;

SimPump::SimPump() : stiffness(0), minimumVal(0), maximumVal(1) {}

SimPump::SimPump(float startingStiffness, float minVal, float maxVal) : 
                        stiffness(startingStiffness), minimumVal(minVal), maximumVal(maxVal) {}

bool SimPump::setStiffness(float newStiffness) {
        if ( newStiffness >= minimumVal && newStiffness <= maximumVal ) {
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

SimulatorModel::SimulatorModel() {
    srand(time(NULL));
    numValves = 3;
    pneumaticPump = SimPump();
    for (int i = 0; i < 3; i++) {
        valveList.push_back(SimValve());
    }
}

SimulatorModel::SimulatorModel(int numValves): numValves(numValves) {
    srand(time(NULL));
    pneumaticPump = SimPump();
    for (int i = 0; i < numValves; i++) {
        valveList.push_back(SimValve()); 
    }
}

bool SimulatorModel::setValve(int valveToSet, bool stateToSet) {
    if (valveToSet > -1 && valveToSet < valveList.size()) {
        return valveList.at(valveToSet).setState(stateToSet);
    }
    return false;
}

bool SimulatorModel::setPump(float stiffnessToSet) {
    return pneumaticPump.setStiffness(stiffnessToSet);
}

void SimulatorModel::displayState() {
    cout << "SimulatorModel Component Status:" << endl;
    cout << "    Pump stiffness: " << pneumaticPump.percentStiffness() << endl;
    for (int i = 0; i < numValves; i++) {
        cout << "    Valve " << i << " state: " << valveList.at(i).stringState() << endl;
    }
}