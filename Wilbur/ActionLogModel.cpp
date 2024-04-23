// Header Files
#include "ActionLogModel.h"                                                     

ActionLogModel::ActionLogModel()
{
	// Initiate session timer
	sessionTimer.start();
}

void ActionLogModel::buildStringAndAppend(std::string objectName, int newValue)
{
	QString returnText;

	// check for button
	if (objectName == "Switch One" || objectName == "Switch Two"
		|| objectName == "Switch Three")
	{
		// Create button change string that will be shown in text window
		returnText = QString("%1 changed to %2").arg(
			QString::fromStdString(objectName), newValue ? "Open" : "Closed");
	}

	else if (objectName == "Connect Button")
	{
		// Create button change string that will be shown in text window
		returnText = QString("%1 the prototype").arg(
							  newValue ? "Connected to" : "Disconnected from");
	}

	// Check for slider
	else
	{
		// Create slider change string that will be shown in text window
		std::string stiffnessString = "N/A";
		switch (newValue)
		{
		case 0:
			stiffnessString = "Off";
			break;
		case 1:
			stiffnessString = "Low";
			break;
		case 2:
			stiffnessString = "Med";
			break;
		case 3:
			stiffnessString = "High";
			break;
		}

		returnText = QString("Pump Stiffness set to %1").arg(
			QString::fromStdString(stiffnessString));
	}

	addActionToLog(returnText);
}

void ActionLogModel::buildStringAndAppend(std::string objectName, 
														  std::string newValue)
{
	QString returnText;
	size_t flowRateStrFound = objectName.find("Flow Rate");

	// check for button
	if (objectName == "Switch One" || objectName == "Switch Two"
		|| objectName == "Switch Three")
	{
		// Create button change string that will be shown in text window
		returnText = QString("%1 changed to %2").arg(
											QString::fromStdString(objectName), 
									  std::stoi(newValue) ? "Open" : "Closed");
	}

	else if (objectName == "Connect Button")
	{
		// Create button change string that will be shown in text window
		returnText = QString("%1 the prototype").arg(
				   std::stoi(newValue) ? "Connected to" : "Disconnected from");
	}

	else if (flowRateStrFound != std::string::npos)
	{
		double roundedNewValue = std::stod(newValue);
		returnText = QString("%1 changed to %2").arg(
											QString::fromStdString(objectName), 
								     QString::number(roundedNewValue, 'f', 2));
	}

	// Check for slider
	else
	{
		// Create slider change string that will be shown in text window
		std::string stiffnessString = "N/A";

		switch (std::stoi(newValue))
		{
		case 0:
			stiffnessString = "Off";
			break;
		case 1:
			stiffnessString = "Low";
			break;
		case 2:
			stiffnessString = "Med";
			break;
		case 3:
			stiffnessString = "High";
			break;
		}

		returnText = QString("Pump Stiffness set to %1").arg(
									  QString::fromStdString(stiffnessString));
	}

	addActionToLog(returnText);
}

void ActionLogModel::exportLog()
{
	// Open a file dialog to choose the file location
	QString filePath = QFileDialog::getSaveFileName(nullptr, "Save Log File", 
								   QDir::homePath(), tr("Text files (*.txt)"));

	// Check if the user has not canceled the dialog
	if (!filePath.isEmpty())
	{
		// Create an IO stream to write into the file
		QTextStream stream(&fileToExport);

		// Set the file name
		fileToExport.setFileName(filePath);

		// Open output file
		fileToExport.open(WriteOnly);

		// Using the stream, write log of actions into the file
		stream << listOfActions.join("\n");

		// Close file access
		fileToExport.close();
	}

}

void ActionLogModel::addActionToLog(QString actionToAdd, const QTime& currentTime)
{
	// Format action time and text
	QString formattedAction = QString("%1 | %2 -> %3").arg(
						 formattedElapsedTime(), m_currentTime.toString(), actionToAdd);

	// Insert the new action to the list of actions along with its time and date
	listOfActions << formattedAction;

	// Emit the actionAdded Signal for ActionLogView
	emit actionAdded();
}

QString ActionLogModel::getActionTime()
{
	// Get the current time and date
	time_t time = std::time(0);

	// Convert time into a string
	QString timeString = ctime(&time);

	// Remove '\n' from time string
	timeString.remove("\n");

	// Return the time string
	return timeString;
}

QString ActionLogModel::formattedElapsedTime()
{
	// Return formatted elapsed time (hours/minutes/seconds/milliseconds)
	return QTime::fromMSecsSinceStartOfDay(
							  sessionTimer.elapsed()).toString("hh:mm:ss:zzz");
}

// Implementation of setCurrentTime
void ActionLogModel::setCurrentTime(const QTime& currentTime)
{
	m_currentTime = currentTime;
}