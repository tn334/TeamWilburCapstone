#include "InputDirectorViewModel.h"

InputDirectorViewModel::InputDirectorViewModel() : simulatorMode(true), 
						     simObject(SimulatorModel()), simOutput(nullptr), serialClient(nullptr) {}

InputDirectorViewModel::InputDirectorViewModel(bool simState, 
	    QWidget* WilburApp) : simulatorMode(simState), simOutput(nullptr), serialClient(nullptr)
{
	if (simulatorMode)
	{
		simObject = SimulatorModel();

		simOutput = new SimOutputViewModel(WilburApp);
	}

	// Initialize serial connection here?
	else
	{
		serialClient = new SerialConnection(WilburApp);
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
			if (newValue)
			{
				hardwareResponse = serialClient->open("COM5", QSerialPort::Baud115200);
			}
			else
			{
				delete serialClient;
				serialClient = nullptr;

			}
			break;

		default:
			// default to control hardware as normal
			if (serialClient != nullptr)
			{
				serialClient->write(combinedChars);
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
