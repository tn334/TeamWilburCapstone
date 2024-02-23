#pragma once
#ifndef ACTION_LOGGING
#define ACTION_LOGGING

// Header Files
#include <iostream>
#include <ctime>
#include <QFile>
#include <QTime>
#include <QDebug>
#include <QString>
#include <QElapsedTimer>
#include <QStringList>
#include <QTextStream>
#include <QCoreApplication>

// ActionLogging Class derived as a QFile
class ActionLogging : public QFile
{
public:
	// Action Log Constructor
	ActionLogging();
	
	// Export log as a txt file
	void exportLog();

	// Add an action to the list of logs
	void addActionToLog(QString logToAdd);

	// Get the time at which the action was made
	QString getActionTime();

	// Format the session timer
	QString formattedElapsedTime();

private:
	// File name for exported file
	QString fileName = "Log.txt";

	// File container that will be exported
	QFile fileToExport;

	// List containing actions
	QStringList listOfActions;

	// Session timer
	QElapsedTimer sessionTimer;
};

#endif // ACTION_LOGGING