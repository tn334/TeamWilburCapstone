#include "InputDirectorViewModel.h"

InputDirectorViewModel::InputDirectorViewModel() : simulatorMode(true), 
						     simObject(SimulatorModel()), simOutput(nullptr) {}

InputDirectorViewModel::InputDirectorViewModel(bool simState, 
	    QWidget* simOutputParent) : simulatorMode(simState), simOutput(nullptr)
{
	if (simulatorMode)
	{
		simObject = SimulatorModel();

		simOutput = new SimOutputViewModel(simOutputParent);
	}

	else 
	{
		// Initialize bluetooth connection object here
	}
}

bool InputDirectorViewModel::handleInput(buttonType inputType, int newValue, 
											            std::string objectName) 
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

		simOutput->appendActionString(objectName, newValue);

	}
	else
	{
		// Handle bluetooth forwarding here
	}

	return hardwareResponse;
}
