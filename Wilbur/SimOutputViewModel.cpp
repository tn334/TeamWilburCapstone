// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Header Files
#include "SimOutputViewModel.h"


// Custom Dialog Box Constructor
SimOutputViewModel::SimOutputViewModel(QWidget* parent)
    : QDialog(parent, Qt::Window)
{
	// Initialize Dialog UI
    initUI();
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
	// Using the text handler, control text manipulation
    stringBuilder.buildString(objectName, newValue);

	// Optionally update the text in the QTextEdit immediately
    textEdit->setPlainText(stringBuilder.getAllText().join("\n"));

    // Show the dialog
    this->show();
}

