// Header Files
#include "actionLogging.h"                                                     

ActionLogging::ActionLogging()
{
	// Initiate session timer
	sessionTimer.start();
}

void ActionLogging::exportLog()
{
	// Create an IO stream to write into the file
	QTextStream stream(&fileToExport);
	
	// Set the file name
	fileToExport.setFileName(fileName);

	// Open output file
	fileToExport.open(WriteOnly);

	// Using the stream, write log of actions into the file
	stream << listOfActions.join("\n");

	// Close file access
	fileToExport.close();
}

void ActionLogging::addActionToLog(QString actionToAdd)
{
	// Format action time and text
	QString formattedAction = QString("%1 | %2 -> %3").arg(
						 formattedElapsedTime(), getActionTime(), actionToAdd);

	// Insert the new action to the list of actions along with its time and date
	listOfActions << formattedAction;
}

QString ActionLogging::getActionTime()
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

QString ActionLogging::formattedElapsedTime()
{
	// Return formatted elapsed time (hours/minutes/seconds/milliseconds)
	return QTime::fromMSecsSinceStartOfDay(
							  sessionTimer.elapsed()).toString("hh:mm:ss:zzz");
}