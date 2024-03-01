// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Header files
#include "stringBuilderViewModel.h"

StringBuilderViewModel::StringBuilderViewModel() 
{
    // Initialize if needed
}

void StringBuilderViewModel::controlManipulated(std::string objectName, int newValue) 
{
    // check for button
    if (objectName == "Button One" || objectName == "Button Two" || objectName == "Button Three")
    {
		// Create button change string that will be shown in text window
        objectText = QString("%1 changed to %2").arg(QString::fromStdString(objectName)).arg(newValue ? "Open" : "Closed");
    }

    else if (objectName == "Bluetooth Button")
    {
        // Create button change string that will be shown in text window
        objectText = QString("%1 is %2").arg(QString::fromStdString(objectName)).arg(newValue ? "Connected" : "Disconnected");
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

        objectText = QString("Pump Stiffness set to %1").arg(QString::fromStdString(stiffnessString));
    }
	
	// Show text in window text history
    textList.append(objectText);
}

QStringList StringBuilderViewModel::getAllText() const {
	// Return full list containing all strings regarding changes
    return textList;
}

QString StringBuilderViewModel::getActionText() const
{
	// Return the text of the current object that was interacted with
	return objectText;
}