// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local Header files
#include "controlBox.h"

// cite https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html
ControlBox::ControlBox(QWidget* parent, ActionLogging* actionLog, InputDirector* inputDirector)
{
    // Create a wrapper for controls
    QWidget* controller = new QWidget;
    setCentralWidget(controller);

	// Create control box label
    controlLabel = new QLabel(tr("<i>Choose prototype settings."));
    controlLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    controlLabel->setAlignment(Qt::AlignCenter);

    //add instance of customDialog
    customDialog = new CustomDialog(this, actionLog);

    // create local variable to reference inputDirector
    director = inputDirector;

	// Create bluetooth label and button
    QLabel* bluetoothLabel = new QLabel("Bluetooth Connection:", controller);
    bluetoothLabel->setStyleSheet("font: bold 14px; ");
    bluetooth = new BluetoothButton(this);
    connect(bluetooth, &BluetoothButton::handleButtonClicked, this, &ControlBox::executeControl);

    //Bluetooth layout
	QGridLayout* bluetoothLayout = new QGridLayout;
    bluetoothLayout->addWidget(bluetoothLabel, 0, 0, 1, 1, Qt::AlignRight);
    bluetoothLayout->addWidget(bluetooth, 0, 1, 1, 1);

    // set ductLayout
    ductLayout = new DuctLayout(this);
    // Connect the signal from DuctLayout to executeControl slot
    connect(ductLayout, &DuctLayout::ductButtonClicked, this, &ControlBox::executeControl);
    
    // Create a slider layout containing slider and its labels
    sliderLayout = new SliderLayout(this);
    connect(sliderLayout->stiffnessSlider, &StiffnessSlider::sliderReleased, customDialog, [this]() {executeControl(PUMP, sliderLayout->stiffnessSlider->value()); });

    // Full ControlBox Layout
    QVBoxLayout* controlLayout = new QVBoxLayout;
    controlLayout->addLayout(bluetoothLayout);
    controlLayout->addSpacing(10);
    controlLayout->addWidget(controlLabel);
    controlLayout->addWidget(ductLayout);
    controlLayout->addWidget(sliderLayout);
    
    controller->setLayout(controlLayout);

    //Set style for ControlBox label
    controlLabel->setStyleSheet("QWidget { border: 1px solid black; }");
};

// Create button derived from control box
// Name: createButton
// Description: create a new button, initialize with provided text, establish 
//  connection between the button's clicked signal and a specified member 
//  function
// Dependencies: connect()
template<typename PointerToMemberFunction>
Button* ControlBox::createButton(const QString& text, const PointerToMemberFunction& member)
{
    // Instantiate new button
    Button* button = new Button(text);
    connect(button, &Button::clicked, this, member);
    return button;
}

// Control manipulation changes
void ControlBox::executeControl(buttonType button, int newValue)
{
	// Initialize Variables
    std::string objectName = "N/A";
    bool actionSuccess = false;


    switch (button)
    {
        case PUMP:
            objectName = "Pump Slider";
            break;
        case VALVE1:
            objectName = "Button One";
            break;
        case VALVE2:
            objectName = "Button Two";
            break; 
        case VALVE3:
            objectName = "Button Three";
            break;
        case CONNECT:
            objectName = "Bluetooth Button";
            break;
    }

    actionSuccess = director->handleInput(button, newValue);

	// Change dialog in dialog box
    customDialog->controlManipulated(objectName, newValue);

    // Set the main window as the parent of the dialog
    customDialog->setParent(this);

    // Show the existing customDialog without blocking
    customDialog->show();
    customDialog->setAttribute(Qt::WA_ShowWithoutActivating);
}

ControlBox::~ControlBox()
{
    // delete objects
    delete bluetooth;
    delete sliderLayout;
    delete controlLabel;

    // delete instances
    delete director;
    delete customDialog;
}


