#include "inputDirector.h"
#include "demoSimulator.h"

InputDirector::InputDirector() : simulatorMode(true), simObject(DemoSimulator()) {}

InputDirector::InputDirector(bool simState) : simulatorMode(simState) 
{
	if (simState) 
	{
		simObject = DemoSimulator();
	}
	else 
	{
		// Initialize bluetooth connection object here
	}
}

bool InputDirector::handleInput(buttonType inputType, int newValue) 
{
	bool hardwareResponse = false;

	if (simulatorMode)
	{
		switch (inputType)
		{


			case PUMP:
				// cast newValue int to a pump enum value
				hardwareResponse = simObject.setPump(static_cast<pumpValue>(newValue));
				break;

			case CONNECT:

				// return success until simulator has a simulated bluetooth connection
				hardwareResponse = true;
				break;

			default:
				// default to valve input, modify enum to translate for simulator values
				hardwareResponse = simObject.setValve(static_cast<int>(inputType) - 1, newValue);
				break;
		}
	}
	else
	{
		// Handle bluetooth forwarding here
	}

	return hardwareResponse;
}
