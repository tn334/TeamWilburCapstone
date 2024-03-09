// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local Header files
#include "PrototypeControllerView.h"

// cite https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html
PrototypeControllerView::PrototypeControllerView(QWidget* parent, ActionLogModel* actionLoggerPtr, InputDirectorViewModel* inputDirector)
{
    // Create a wrapper for controls
    QWidget* controller = new QWidget;
    setCentralWidget(controller);

	// Create control box label
    controlLabel = new QLabel(tr("<i>Choose prototype settings."));
    controlLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    controlLabel->setAlignment(Qt::AlignCenter);

    //add instance of simOutput window
    simOutput = new SimOutputViewModel(this);

    // create local variable to reference inputDirector
    director = inputDirector;
    // create assign member variable to reference actionLogger
    actionLog = actionLoggerPtr;
	// Create bluetooth layout
    bluetoothLayout = new BluetoothLayoutView(this);
    // Connect layout to executeControl
    connect(bluetoothLayout, &BluetoothLayoutView::bluetoothButtonClicked, this, &PrototypeControllerView::executeControl);

    // set ductLayout
    ductLayout = new DuctLayoutView(this);
    // Connect the signal from DuctLayoutView to executeControl slot
    connect(ductLayout, &DuctLayoutView::ductButtonClicked, this, &PrototypeControllerView::executeControl);

    // @TODO: Need to log the milk viscocity values 
   /* connect(ductLayout, &DuctLayoutView::ductFlowRateChanged, this, &PrototypeControllerView::executeFlowRateControl);*/
    // Create a slider layout containing slider and its labels
    sliderLayout = new SliderLayoutView(this);
    connect(sliderLayout->stiffnessSlider, &StiffnessSliderView::sliderReleased, this, [this]() {executeControl(PUMP, sliderLayout->stiffnessSlider->value()); });

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

    actionSuccess = director->handleInput(button, newValue, objectName);

    // @TODO: make function call to actionlogger here
    // @TODO: also need to handle milk viscocity change to output to log
    // textHandler.getActionText()
    actionLog->addActionToLog("Previously this was stringBuilder.getActionText()");

}

PrototypeControllerView::~PrototypeControllerView()
{
    // delete objects
    delete bluetoothLayout;
    delete sliderLayout;
    delete controlLabel;

    // delete instances
    delete director;
    delete simOutput;
}


