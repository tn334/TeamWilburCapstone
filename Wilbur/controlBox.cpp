// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local Header files
#include "controlBox.h"
#include "bluetoothButton.h"
#include "ductButton.h"

// Qt header files
#include <QBoxLayout>
#include <QSlider>
#include <QToolButton>
#include <QGridLayout>
#include <QLabel>

// cite https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html
ControlBox::ControlBox(QWidget* parent)
{
    // Create a wrapper for controls
    QWidget* controller = new QWidget;
    setCentralWidget(controller);

    controlLabel = new QLabel(tr("<i>Choose prototype settings."));
    controlLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    controlLabel->setAlignment(Qt::AlignCenter);

    //add instance of customDialog
    customDialog = new CustomDialog(this);

    QLabel* bluetoothLabel = new QLabel("Bluetooth Connection:", controller);
    bluetoothLabel->setStyleSheet("font: bold 12px; ");
    BluetoothButton* bluetooth = new BluetoothButton(this);
    //Bluetooth layout
    QGridLayout* bluetoothLayout = new QGridLayout;
    bluetoothLayout->addWidget(bluetoothLabel, 0, 0, 1, 1, Qt::AlignRight);
    bluetoothLayout->addWidget(bluetooth, 0, 1, 1, 1);

    // setting up duct buttons

    buttonOne = createButton("Closed", [this]() {handleButtonPressed(0);  });
    QLabel* buttonOneTitle = new QLabel("Duct One:", controller);
    //Manipulate with backend code
    connect(buttonOne, &Button::clicked, customDialog, [this]() {controlManipulated("buttonOne", 0);  });

    buttonTwo = createButton("Closed", [this]() {handleButtonPressed(1);  });
    QLabel* buttonTwoTitle = new QLabel("Duct Two:", controller);
    // Manipulate with backend code
    connect(buttonTwo, &Button::clicked, customDialog, [this]() {controlManipulated("buttonTwo", 0);  });

    buttonThree = createButton("Closed", [this]() {handleButtonPressed(2);  });
    QLabel* buttonThreeTitle = new QLabel("Duct Three:", controller);
    // Manipulate with backend code
    connect(buttonThree, &Button::clicked, customDialog, [this]() {controlManipulated("buttonThree", 0);  });

    // Set fixed size for the buttons
    buttonOne->setFixedSize(80, 30);
    buttonTwo->setFixedSize(80, 30);  // adjust size
    buttonThree->setFixedSize(80, 30); //adjust size  
    
    // Grid box for buttons and labels
    QGridLayout* buttonLayout = new QGridLayout;
    // Not implemented correctly
    buttonLayout->addWidget(buttonOneTitle, 0, 0, 1, 1, Qt::AlignLeft);
    buttonLayout->addWidget(buttonOne, 0, 1, 1, 1, Qt::AlignLeft);
    buttonLayout->addWidget(buttonTwoTitle, 0, 2, 1, 1, Qt::AlignLeft);
    buttonLayout->addWidget(buttonTwo, 0, 3, 1, 1, Qt::AlignLeft);
    buttonLayout->addWidget(buttonThreeTitle, 0, 4, 1, 1, Qt::AlignRight);
    buttonLayout->addWidget(buttonThree, 0, 5, 1, 1, Qt::AlignRight);
    
    // create a child widget inside box for stiffness slide
    stiffnessSlider = createSlider("Stiffness:", "StiffnessSlider");
    QLabel* sliderTitle = new QLabel("Nipple Stiffness Control:", this);
    sliderTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    //TODO Connect to backend code and add update
    QGridLayout* sliderLayout = new QGridLayout;
    sliderLayout->addWidget(sliderTitle, 0, 0, 1, 1);
    sliderLayout->addWidget(stiffnessSlider->labelOne, 1, 0, 1, 1);
    sliderLayout->addWidget(stiffnessSlider->labelTwo, 1, 1, 1, 1, Qt::AlignLeft);
    sliderLayout->addWidget(stiffnessSlider->labelThree, 1, 3, 1, 1, Qt::AlignRight);
    sliderLayout->addWidget(stiffnessSlider->labelFour, 1, 5, 1, 1, Qt::AlignRight);
    sliderLayout->addWidget(stiffnessSlider, 2, 0, 1, 6);
    //Slider style TODO (incorporate into slide class)
    sliderTitle->setStyleSheet("font: bold 12px;");
    stiffnessSlider->setStyleSheet("QWidget { border: 1.25px solid black;}");

    //Full ControlBox Layout
    QVBoxLayout* controlLayout = new QVBoxLayout;
    controlLayout->addLayout(bluetoothLayout);
    controlLayout->addSpacing(10);
    controlLayout->setSizeConstraint(QLayout::SetFixedSize);
    controlLayout->addWidget(controlLabel);
    controlLayout->addLayout(buttonLayout);
    controlLayout->addLayout(sliderLayout);
    controller->setLayout(controlLayout);
    //Style for ControlBox
    controlLabel->setStyleSheet("QWidget { border: 1px solid black; }");
};

template<typename PointerToMemberFunction>
Button* ControlBox::createButton(const QString& text, const PointerToMemberFunction& member)
{
    Button* button = new Button(text);
    connect(button, &Button::clicked, this, member);
    return button;
}

HorizontalSlider* ControlBox::createSlider(const QString& title, const QString& objectName) {
    HorizontalSlider* slider = new HorizontalSlider(this);

    // Disconnect any existing connections for the slider
    disconnect(slider, &HorizontalSlider::sliderReleased, this, nullptr);

    connect(slider, &HorizontalSlider::sliderReleased, this, [this, objectName, slider]() {
        controlManipulated(objectName.toStdString(), slider->value());
        });

    return slider;
}

void ControlBox::handleButtonPressed(int valveNumber)
{
    bool newState;
    // Get the current state of the button
    if (valveNumber == 0)
    {
        newState = buttonOne->getState();
    }
    else if (valveNumber == 1)
    {
        newState = buttonTwo->getState();
    }
    else
    {
        newState = buttonThree->getState();
    }

     // Set to true for open, false for closed
    demoSimulator.setValve(valveNumber , newState);

    // Optionally, you can update the UI or do additional tasks here
}

void ControlBox::controlManipulated(std::string objectName, int newValue)
{
    bool newState;
    
    if (objectName == "buttonOne" || objectName == "buttonTwo" || objectName == "buttonThree")
    {
        // Get the current state of the button
        if (objectName == "buttonOne")
        {
            newState = buttonOne->getState();
        }
        else if (objectName == "buttonTwo")
        {
            newState = buttonTwo->getState();
        }
        else
        {
            newState = buttonThree->getState();
        }
    }
    else
    {
        std::string objectName = "PumpSlider"; // Provide an appropriate name
        newState = true; // You need to determine the current state based on your logic

    }

    customDialog->controlManipulated(objectName, newState, newValue);
    // Set the main window as the parent of the dialog
    customDialog->setParent(this);

    // Show the existing customDialog without blocking
    customDialog->show();
    customDialog->setAttribute(Qt::WA_ShowWithoutActivating);
}

//NOT CURRENTLY IMPLEMENTED IN SLIDER
void ControlBox::handleSliderValueChanged(int value) {
    // Handle the slider value change here
    // Trigger setPump function in demoSimulator

    pumpValue sliderValue = (pumpValue)value;

    bool success = demoSimulator.setPump(sliderValue); // Assuming setPump is designed to take a float value
    if (success) {
        // Call controlManipulation with the correct arguments
        // You need to define the correct arguments based on your requirements
        // For example, assuming controlManipulation takes a string, a boolean, and an int
        std::string objectName = "PumpSlider"; // Provide an appropriate name
        bool currentState = true; // You need to determine the current state based on your logic
        int valueChanged = value; // You might need to adjust this based on your requirements

        // Call controlManipulation with the updated values
        
    }
}

ControlBox::~ControlBox()
{
    delete customDialog;
}


