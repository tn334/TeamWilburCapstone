// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Header files
#include "textHandler.h"

TextHandler::TextHandler() 
{
    // Initialize if needed
}

void TextHandler::controlManipulated(std::string objectName, bool currentState, int valueChanged) 
{
    // check for button
    if (objectName == "buttonOne" || objectName == "buttonTwo" || objectName == "buttonThree") 
    {
		// Create button change string that will be shown in text window
        objectText = QString("%1 is changed to %2").arg(QString::fromStdString(objectName)).arg(currentState ? "Open" : "Closed");
    }

	// Check for slider
    else 
    {
		// Create slider change string that will be shown in text window
        objectText = QString("Prototype Stiffness is at %1%").arg(valueChanged);
    }
	
	// Show text in window text history
    textList.append(objectText);
}

QStringList TextHandler::getAllText() const {
	// Return full list containing all strings regarding changes
    return textList;
}

QString TextHandler::getActionText() const
{
	// Return the text of the current object that was interacted with
	return objectText;
}