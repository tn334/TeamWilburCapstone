// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Header Files
#include "SimOutputViewModel.h"

// Sim String Builder buildString implementation
void SimStringBuilder::buildStringAndAppend(std::string objectName, int newValue)
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

    else if (objectName == "Bluetooth Button")
    {
        // Create button change string that will be shown in text window
        returnText = QString("%1 is %2").arg(QString::fromStdString(objectName), 
									  newValue ? "Connected" : "Disconnected");
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

    // Show text in window text history
    textList.append(returnText);
}

QStringList SimStringBuilder::getAllText() const 
{
    // Return full list containing all strings regarding changes
    return textList;
}

// Custom Dialog Box Constructor
SimOutputViewModel::SimOutputViewModel(QWidget* parent)
    : QDialog(parent, Qt::Window)
{
	// Initialize Dialog UI
    initUI();

    // Set initial window geometry
    setWindowGeometry(100, 100, 300, 300);
}

// UI Initializer
void SimOutputViewModel::initUI()
{
	// Instantiate dialog layout
    QVBoxLayout* dialogLayout = new QVBoxLayout(this);
	
	// Create title label and set settings
    QLabel* titleLabel = new QLabel("SimulatorModel:", this);
    titleLabel->setAlignment(Qt::AlignCenter); // Adjust alignment as needed
    titleLabel->setFont(QFont("Arial", 16, QFont::Bold)); // Adjust font as needed
    
	// Add title text/label to dialog layout
	dialogLayout->addWidget(titleLabel);

	// Create new text editor
    textEdit = new QTextEdit(this);

	// Add text editor to dialog layout
    dialogLayout->addWidget(textEdit);

	// Set dialog layout to main layout
    setLayout(dialogLayout);
}

// Handle text editor text manipulation
void SimOutputViewModel::appendActionString(std::string objectName, int newValue) 
{
	// Using the string builder, control text manipulation and append end 
	// result to respective list
    stringBuilder.buildStringAndAppend(objectName, newValue);

	// Optionally update the text in the QTextEdit immediately
    textEdit->setPlainText(stringBuilder.getAllText().join("\n"));

    // Show the dialog
    this->show(); // This causes the error on the current terminal window.
}

// Set the geometry of the window
void SimOutputViewModel::setWindowGeometry(int x, int y, int width, int height)
{
    this->setGeometry(x, y, width, height);
}