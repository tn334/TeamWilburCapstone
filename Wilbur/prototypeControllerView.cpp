// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local Header files
#include "PrototypeControllerView.h"

// cite https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html
PrototypeControllerView::PrototypeControllerView(QWidget* parent, ActionLogModel* actionLog, InputDirectorViewModel* inputDirector)
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
    /*QLabel* bluetoothLabel = new QLabel("Bluetooth Connection:", controller);
    bluetoothLabel->setStyleSheet("font: bold 14px; ");
    bluetooth = new BluetoothButtonView(this);*/
    bluetoothLayout = new BluetoothLayoutView(this);
    connect(bluetoothLayout, &BluetoothLayoutView::bluetoothButtonClicked, this, &PrototypeControllerView::executeControl);

    //Bluetooth layout
	/*QGridLayout* bluetoothLayout = new QGridLayout;
    bluetoothLayout->addWidget(bluetoothLabel, 0, 0, 1, 1, Qt::AlignRight);
    bluetoothLayout->addWidget(bluetooth, 0, 1, 1, 1);*/

    // set ductLayout
    ductLayout = new DuctLayoutView(this);
    // Connect the signal from DuctLayoutView to executeControl slot
    connect(ductLayout, &DuctLayoutView::ductButtonClicked, this, &PrototypeControllerView::executeControl);
    
    // Create a slider layout containing slider and its labels
    sliderLayout = new SliderLayoutView(this);
    connect(sliderLayout->stiffnessSlider, &StiffnessSliderView::sliderReleased, customDialog, [this]() {
        executeControl(PUMP, sliderLayout->stiffnessSlider->value()); 
        });

    // Full PrototypeControllerView Layout
    QVBoxLayout* controlLayout = new QVBoxLayout;
    controlLayout->addWidget(bluetoothLayout);
    controlLayout->addSpacing(10);
    controlLayout->addWidget(controlLabel);
    controlLayout->addWidget(ductLayout);
    controlLayout->addWidget(sliderLayout);
    
    controller->setLayout(controlLayout);

    //Set style for PrototypeControllerView label
    controlLabel->setStyleSheet("QWidget { border: 1px solid black; }");
};

// Control manipulation changes
void PrototypeControllerView::executeControl(buttonType button, int newValue)
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

PrototypeControllerView::~PrototypeControllerView()
{
    // delete objects
    delete bluetoothLayout;
    delete sliderLayout;
    delete controlLabel;

    // delete instances
    delete director;
    delete customDialog;
}


