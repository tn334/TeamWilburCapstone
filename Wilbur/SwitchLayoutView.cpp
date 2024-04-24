// Local Header Files
#include "SwitchLayoutView.h"

SwitchLayoutView::SwitchLayoutView(QWidget* parent) : QWidget(parent)
{
	// Create labels for switches
	switchLabel = new QLabel;
	switchLabel->setStyleSheet("font: bold 14px; ");
	switchLabel->setText("Switch:");
	switchLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	viscosityLabel = new QLabel;
	viscosityLabel->setStyleSheet("font: bold 14px; ");
	viscosityLabel->setText("Flow Rate:");

	buttonLabel = new QLabel;
	buttonLabel->setStyleSheet("font: bold 14px; ");
	buttonLabel->setText("Switch State:");

	// Create horizontal layout for labels
	horizontalLabelLayout = new QHBoxLayout;

	// Create a QGrid Layout for the grid layout
	QGridLayout* labelLayout = new QGridLayout;

	labelLayout->addWidget(switchLabel, 0, 0);
	labelLayout->addWidget(viscosityLabel, 0, 1, Qt::AlignRight);
	labelLayout->addWidget(buttonLabel, 0, 2, Qt::AlignRight);


	//Add the grid layout to the horizontal layout
	horizontalLabelLayout->addLayout(labelLayout);

	// Create layout for button 1
	layoutButtonOne = createButtonLayout("One", &buttonOne, &flowRateOne, VALVE1);

	// Create layout for button 2
	layoutButtonTwo = createButtonLayout("Two", &buttonTwo, &flowRateTwo, VALVE2);

	// Create layout for button 3
	layoutButtonThree = createButtonLayout("Three", &buttonThree, &flowRateThree, VALVE3);

	// Main layout
	verticalSwitchLayout = new QVBoxLayout;
	verticalSwitchLayout->addLayout(horizontalLabelLayout);
	verticalSwitchLayout->addLayout(layoutButtonOne);
	verticalSwitchLayout->addLayout(layoutButtonTwo);
	verticalSwitchLayout->addLayout(layoutButtonThree);
	setLayout(verticalSwitchLayout);

};

SwitchLayoutView::~SwitchLayoutView()
{
	// delete label objects
	delete layoutButtonOne;
	delete layoutButtonTwo;
	delete layoutButtonThree;

	// delete grid object
	delete verticalSwitchLayout;
}

QHBoxLayout* SwitchLayoutView::createButtonLayout(const QString& labelText, SwitchButtonView** button, FlowRateLayoutView** flowLayout, buttonType valveType)
{
	// declare label name
	QLabel* buttonLabel = new QLabel(labelText);
	buttonLabel->setStyleSheet("font: bold 14px; ");

	// instantiate button
	*button = new SwitchButtonView();

	// instantiate value box
	*flowLayout = new FlowRateLayoutView();

	connect((*flowLayout)->getSpinBox(), &QDoubleSpinBox::valueChanged, this,
		[this, valveType, flowLayout]() {callExecuteFlowRateControl(valveType, 
										 (*flowLayout)->getSpinBox()->value());
		});

	// set button event handlers
	connect(*button, &SwitchButtonView::clicked, this, [this, valveType, button]() {
		callExecuteControl(valveType, (*button)->getState());
		});

	// button layout
	buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(buttonLabel); // label
	buttonLayout->addWidget(*flowLayout);
	buttonLayout->addWidget(*button, Qt::AlignLeft); // button
	buttonLayout->addSpacing(10);

	return buttonLayout;
}

// coded along with ai
void SwitchLayoutView::callExecuteControl(buttonType button, int newValue)
{
	emit switchButtonClicked(button, newValue);
}

// @TODO: Hook up milk viscocity change to action logger
void SwitchLayoutView::callExecuteFlowRateControl(buttonType button, double newValue)
{
	emit switchFlowRateChanged(button, newValue);
}