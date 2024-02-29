#ifndef SIMULATOR
#define SIMULATOR
#include <iostream>
#include <vector>
using namespace std;
#define OPEN true
#define CLOSED false

class SimPump {
    public:

    SimPump();

    SimPump(float startingStiffness, float minVal, float maxVal);

    bool setStiffness(float newStiffness);

    float getStiffness();
    string percentStiffness();

    private:
    float stiffness;
    float minimumVal;
    float maximumVal;

};

class SimValve {
    public:

    SimValve();

    SimValve(bool startingState);

    bool setState(bool stateToBe);

    bool getState();

    string stringState();

    private:
    bool state;
};

class SimulatorModel {
    public:

    SimulatorModel();

    SimulatorModel(int numValves);

    bool setValve(int valveToSet, bool stateToSet);

    bool setPump(float stiffnessToSet);

    void displayState();

    private:
    SimPump pneumaticPump;
    vector<SimValve> valveList;
    int numValves;
};

#endif