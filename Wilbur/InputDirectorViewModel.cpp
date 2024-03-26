#include "InputDirectorViewModel.h"

InputDirectorViewModel::InputDirectorViewModel() : simulatorMode(true), 
						     simObject(SimulatorModel()), simOutput(nullptr), btClient(nullptr), serialClient(nullptr) {}

InputDirectorViewModel::InputDirectorViewModel(bool simState, 
	    QWidget* WilburApp) : simulatorMode(simState), simOutput(nullptr), btClient(nullptr), serialClient(nullptr)
{
	if (simulatorMode)
	{
		simObject = SimulatorModel();

		simOutput = new SimOutputViewModel(WilburApp);
	}

	// Initialize serial connection here?
	else
	{
		QParent = WilburApp;
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
		// Combine newValue and inputType into a single string to send over bluetooth
		QString combinedChars = QString("%1%2").arg(static_cast<char>(inputType + '0')).arg(static_cast<char>(newValue + '0'));

		// Handle bluetooth forwarding here
		switch (inputType)
		{
		case CONNECT:

			// Initialize bluetooth connection or destroy it based on state
			if (newValue == 1)
			{
				// Establish a new connection object
				btClient = new BluetoothClient(QParent);
			}
			else
			{
				// Destroy the current connection object
				delete btClient;

				btClient = nullptr;
			}
			hardwareResponse = true;
			break;

		default:
			// default to control hardware as normal
			if (btClient != nullptr)
			{
				btClient->send(combinedChars);
				hardwareResponse = true;
			}
			else
			{
				hardwareResponse = false;
			}
			break;
		}
	}

	return hardwareResponse;
}
