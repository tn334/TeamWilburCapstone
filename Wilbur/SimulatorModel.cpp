// Header File
#include "SimulatorModel.h"

// Global Constants defined in .h file
// OPEN = true
// CLOSED = false

typedef unsigned char Byte;
typedef Byte cs_byte;

// SimulatorModel Pump Constructor
SimPump::SimPump() : stiffness(OFF), minimumVal(OFF), maximumVal(HIGH) {}

// SimulatorModel Pump Constructor with values
SimPump::SimPump(pumpValue startingStiffness, pumpValue minVal, pumpValue maxVal) :
    stiffness(startingStiffness), minimumVal(minVal), maximumVal(maxVal) {}

// Stiffness setter
bool SimPump::setStiffness(pumpValue newStiffness) 
{
    if (newStiffness >= minimumVal && newStiffness <= maximumVal) 
	{
        Sleep(((rand() % 3) + 1) * 1000);
        stiffness = newStiffness;
        return true;
    }

    return false;
}

// Stiffness getter
pumpValue SimPump::getStiffness() 
{
    return stiffness;
}

// Stiffness converted to percentage
std::string SimPump::percentStiffness() 
{
    int percentStiffness = (int)(stiffness * 30);
    return (std::to_string(percentStiffness) + "%");
}

//Duct System Controls
SimValve::SimValve() : state(CLOSED) {}

SimValve::SimValve(bool startingState) : state(startingState) {}

bool SimValve::setState(bool stateToBe) 
{
    if (stateToBe != state) 
	{
        Sleep(((rand() % 3) + 1) * 1000);
        state = stateToBe;
    }
    return true;
}

bool SimValve::getState() 
{
    return state;
}

std::string SimValve::stringState() 
{
    if (state) 
	{
        return "open";
    }
    else 
	{
        return "closed";
    }

}

SimulatorModel::SimulatorModel() 
{
    srand(time(NULL));
    numValves = 3;
    pneumaticPump = SimPump();
    for (int i = 0; i < 3; i++) 
	{
        valveList.push_back(SimValve());
    }
}

SimulatorModel::SimulatorModel(int numValves) : numValves(numValves) 
{
    srand(time(NULL));
    pneumaticPump = SimPump();
    for (int i = 0; i < numValves; i++) 
	{
        valveList.push_back(SimValve());
    }
}

bool SimulatorModel::setValve(int valveToSet, bool stateToSet) 
{
    if (valveToSet > -1 && valveToSet < valveList.size()) 
	{
        return valveList.at(valveToSet).setState(stateToSet);
    }

    return false;
}

bool SimulatorModel::setPump(pumpValue stiffnessToSet) 
{
    return pneumaticPump.setStiffness(stiffnessToSet);
}

std::string SimulatorModel::displayState() 
{
    std::stringstream builtString;
    builtString << "SimulatorModel Component Status:" << std::endl;
    builtString << "    Pump stiffness: " << pneumaticPump.percentStiffness() << std::endl;
    for (int i = 0; i < numValves; i++) 
	{
        builtString << "    Valve " << i << " state: " << valveList.at(i).stringState() << std::endl;
    }

    return builtString.str();
}

