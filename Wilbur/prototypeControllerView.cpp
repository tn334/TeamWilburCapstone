// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Local Header files
#include "PrototypeControllerView.h"

// cite https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html
PrototypeControllerView::PrototypeControllerView(QWidget* parent,
	ActionLogModel* actionLoggerPtr, InputDirectorViewModel* inputDirector)
{
	// Create a wrapper for controls
	QWidget* controller = new QWidget;
	setCentralWidget(controller);

	// Create control label
	controlLabel = new QLabel(tr("<i>Choose prototype settings."), this);
	//controlLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
	controlLabel->setAlignment(Qt::AlignCenter);
	controlLabel->setStyleSheet("font: bold 14px; ");
	controlLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	// create a frame for control label
	QFrame* controlFrame = new QFrame(this);
	controlFrame->setFrameShape(QFrame::Box); // set shape to a box
	controlFrame->setFrameShadow(QFrame::Raised);
	controlFrame->setLineWidth(1); // set the width of the frames border
	controlFrame->setMidLineWidth(0);

	// create frame layout
	QVBoxLayout* frameLayout = new QVBoxLayout(controlFrame);
	frameLayout->addWidget(controlLabel);
	// change frame color

	//add instance of simOutput window
	simOutput = new SimOutputViewModel(this);

	// create local variable to reference inputDirector
	director = inputDirector;

	// create assign member variable to reference actionLogger
	actionLog = actionLoggerPtr;

	// Create bluetooth layout
	connectionLayout = new ConnectionLayoutView(this);

	// Connect layout to executeControl
	connect(connectionLayout, &ConnectionLayoutView::connectionButtonClicked,  
		this, &PrototypeControllerView::executeControl);

	// set switchLayout
	switchLayout = new SwitchLayoutView(this);

	// Connect the signal from SwitchLayoutView to executeControl slot
	connect(switchLayout, &SwitchLayoutView::switchButtonClicked, this,
		&PrototypeControllerView::executeControl);

	// Connect the signal from DuctLayoutView to executeFlowRateControl slot
	connect(switchLayout, &SwitchLayoutView::switchFlowRateChanged, this,
		&PrototypeControllerView::executeFlowRateControl);

	// Create a slider layout containing slider and its labels
	sliderLayout = new SliderLayoutView(this);
	connect(sliderLayout->stiffnessSlider, &StiffnessSliderView::sliderReleased,
		this, [this]() {executeControl(PUMP,
			sliderLayout->stiffnessSlider->value()); });

	// Full PrototypeControllerView Layout
	QVBoxLayout* controlLayout = new QVBoxLayout;
	controlLayout->addWidget(connectionLayout);
	controlLayout->addSpacing(10);
	controlLayout->addWidget(controlFrame);
	controlLayout->addWidget(switchLayout);
	controlLayout->addWidget(sliderLayout);
	controller->setLayout(controlLayout);
};

// Control manipulation changes
void PrototypeControllerView::executeControl(buttonType button, int newValue)
{
	// Initialize Variables
	std::string objectName = "N/A";
	bool actionSuccess = false;

	// IMPORTANT: This will transferred to stringBuilder sometime in the
	// future, this is here temporarily
	switch (button)
	{
	case PUMP:
		objectName = "Pump Slider";
		break;
	case VALVE1:
		objectName = "Switch One";
		break;
	case VALVE2:
		objectName = "Switch Two";
		break;
	case VALVE3:
		objectName = "Switch Three";
		break;
	case CONNECT:
		objectName = "Connect Button";
		break;
	}

	actionSuccess = director->handleInput(button, newValue, objectName);

	// At action logger, build string and append it to list of actions
	actionLog->buildStringAndAppend(objectName, newValue);
}

void PrototypeControllerView::executeFlowRateControl(buttonType button,
	double newValue)
{
	// Initialize Variables
	std::string objectName = "N/A";

	// IMPORTANT: This will transferred to stringBuilder sometime in the
	// future, this is here temporarily
	switch (button)
	{
	case VALVE1:
		objectName = "Switch One";
		break;

	case VALVE2:
		objectName = "Switch Two";
		break;

	case VALVE3:
		objectName = "Switch Three";
		break;
	}

	objectName += " Flow Rate";

	// At action logger, build string and append it to list of actions
	actionLog->buildStringAndAppend(objectName, std::to_string(newValue));
}

PrototypeControllerView::~PrototypeControllerView()
{
	// delete objects
	delete connectionLayout;
	delete sliderLayout;
	delete controlLabel;

	// delete instances
	delete director;
	delete simOutput;
}


