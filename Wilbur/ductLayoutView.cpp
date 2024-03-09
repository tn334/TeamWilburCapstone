// Local Header Files
#include "DuctLayoutView.h"

DuctLayoutView::DuctLayoutView(QWidget* parent) : QWidget(parent)
{
	// Create layout for button 1
	layoutButtonOne = createButtonLayout("Duct One:", &buttonOne, &flowRateOne, VALVE1);

	// Create layout for button 2
	layoutButtonTwo = createButtonLayout("Duct Two:", &buttonTwo, &flowRateTwo, VALVE2);

	// Create layout for button 3
	layoutButtonThree = createButtonLayout("Duct Three:", &buttonThree, &flowRateThree, VALVE3);

	// Main layout
	verticalDuctLayout = new QVBoxLayout;
	verticalDuctLayout->addLayout(layoutButtonOne);
	verticalDuctLayout->addLayout(layoutButtonTwo);
	verticalDuctLayout->addLayout(layoutButtonThree);
	setLayout(verticalDuctLayout);

};

DuctLayoutView::~DuctLayoutView()
{
	// delete label objects
	delete layoutButtonOne;
	delete layoutButtonTwo;
	delete layoutButtonThree;

	// delete grid object
	delete verticalDuctLayout;
}

QHBoxLayout* DuctLayoutView::createButtonLayout(const QString& labelText, DuctButtonView** button, FlowRateLayoutView** flowLayout, buttonType valveType)
{
	// declare label name
	QLabel* buttonLabel = new QLabel(labelText);
	buttonLabel->setStyleSheet("font: bold 14px; ");

	// instantiate button
	*button = new DuctButtonView();

	// instantiate value box
	*flowLayout = new FlowRateLayoutView();


	//connect(*flowLayout, &FlowRateLayoutView::handleValueChanged, this, [this, valveType, flowLayout]() {
	//	callExecuteControl(valveType, (*flowLayout)->getSpinBox()->value());
	//	});

	// set button event handlers
	connect(*button, &DuctButtonView::clicked, this, [this, valveType, button]() {
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
void DuctLayoutView::callExecuteControl(buttonType button, int newValue)
{
	emit ductButtonClicked(button, newValue);
}

// @TODO: Hook up milk viscocity change to action logger
//void DuctLayoutView::callExecuteFlowRateControl(buttonType button, double newValue)
//{
//	emit ductFlowRateChanged(button, newValue);
//}