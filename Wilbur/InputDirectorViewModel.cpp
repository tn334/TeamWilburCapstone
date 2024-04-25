#include "InputDirectorViewModel.h"
#include "qdebug.h"

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

	else
	{
		serialClient = new SerialConnection(WilburApp);

	}
}

bool InputDirectorViewModel::handleInput(buttonType inputType, int newState, 
											            std::string objectName) 
{
	bool hardwareResponse = false;

	if (simulatorMode)
	{

		switch (inputType)
		{
			case PUMP:
				// cast newState int to a pump enum value
				hardwareResponse = simObject.setPump(static_cast<pumpValue>(newState));
				break;

			case CONNECT:
				hardwareResponse = true;
				break;

			default:
				// default to valve input, modify enum to translate for simulator values
				hardwareResponse = simObject.setValve(static_cast<int>(inputType) - 1, newState);
				break;
		}

		simOutput->appendActionString(objectName, newState);

	}
	else
	{
		// Combine newState and inputType into a single string to send over bluetooth
		QString combinedChars = QString("%1%2").arg(static_cast<char>(inputType + '0')).arg(static_cast<char>(newState + '0'));
		qDebug() << "made string";


		// Handle bluetooth forwarding here
		switch (inputType)
		{
		case CONNECT:
			if (newState)
			{
				
				hardwareResponse = serialClient->open("COM5", QSerialPort::Baud115200);

				qDebug() << "connected to hardware";
				if (hardwareResponse)
				{
					for (int i = 0; i < 4; i++)
					{
						QString initHardwareChars = QString("%1%2").arg(static_cast<char>(i + '0')).arg(static_cast<char>('0'));//explore qstring null terminator later
						qDebug() << initHardwareChars;
						serialClient->write(initHardwareChars);
						//if (serialClient->readSingleChar() == '\0')
						//{
						//	qDebug() << "Failed to initialize a hardware component";
						//}
					}
				}

			}
			else
			{
				serialClient->write("9");
				serialClient->close();

			}
			break;

		default:
			// default to control hardware as normal
			qDebug() << "About to send data";

			hardwareResponse = serialClient->write(combinedChars) == 2;
			qDebug() << "Data sent";


			
			

			break;
		}
	}

	return hardwareResponse;
}
