// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Header Files
#include "customDialog.h"

// Custom Dialog Box Constructor
CustomDialog::CustomDialog(QWidget* parent, ActionLogging* actionLog)
    : QDialog(parent, Qt::Window)
{
	// Set logPtr to action log
	logPtr = actionLog;

	// Initialize Dialog UI
    initUI();
}

// UI Initializer
void CustomDialog::initUI()
{
	// Instantiate dialog layout
    QVBoxLayout* dialogLayout = new QVBoxLayout(this);
	
	// Create title label and set settings
    QLabel* titleLabel = new QLabel("Simulator:", this);
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
void CustomDialog::controlManipulated(std::string objectName, bool currentState, int valueChanged) 
{
	// Using the text handler, control text manipulation
    textHandler.controlManipulated(objectName, currentState, valueChanged);

	// Optionally update the text in the QTextEdit immediately
    textEdit->setPlainText(textHandler.getAllText().join("\n"));

	// Add the action to the log of actions
	logPtr->addActionToLog(textHandler.getActionText());

    // Show the dialog
    this->show();
}

