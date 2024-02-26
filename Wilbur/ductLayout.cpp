// Local Header Files
#include "ductLayout.h"

DuctLayout::DuctLayout(QWidget* parent)
{
	// Create layout for button 1
	layoutButtonOne = createButtonLayout("Duct One:", &buttonOne, &viscValueOne, &flowRateUnitOne, VALVE1);

	// Create layout for button 2
	layoutButtonTwo = createButtonLayout("Duct Two:", &buttonTwo, &viscValueTwo, &flowRateUnitTwo, VALVE2);

	// Create layout for button 3
	layoutButtonThree = createButtonLayout("Duct Three:", &buttonThree, &viscValueThree, &flowRateUnitThree, VALVE3);

	// Main layout
	verticalDuctLayout = new QVBoxLayout;
	verticalDuctLayout->addLayout(layoutButtonOne);
	verticalDuctLayout->addLayout(layoutButtonTwo);
	verticalDuctLayout->addLayout(layoutButtonThree);
	setLayout(verticalDuctLayout);

};

DuctLayout::~DuctLayout()
{
	// delete label objects
	delete layoutButtonOne;
	delete layoutButtonTwo;
	delete layoutButtonThree;

	// delete grid object
	delete verticalDuctLayout;
}

QHBoxLayout* DuctLayout::createButtonLayout(const QString& labelText, DuctButton** button, QLineEdit** lineEdit, QLabel** unitLabel, buttonType valveType)
{
	// declare label name
	QLabel* buttonLabel = new QLabel(labelText);
	buttonLabel->setStyleSheet("font: bold 14px; ");

	// instantiate button
	*button = new DuctButton();

	// instantiate line edit for viscocity value input
	*lineEdit = new QLineEdit();
	(*lineEdit)->setMaximumWidth(75);
	(*lineEdit)->setFixedHeight(20); // Adjust the height as needed
	(*lineEdit)->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);

	// unit label
	*unitLabel = new QLabel("m<sup>3</sup>/s");
	(*unitLabel)->setStyleSheet("font: bold 12px; ");

	// set button event handlers
	connect(*button, &DuctButton::clicked, this, [this, valveType, button]() {
		callExecuteControl(valveType, (*button)->getState());
		});

	// button layout
	buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(buttonLabel); // label
	buttonLayout->addWidget(*lineEdit); // value edit
	buttonLayout->addWidget(*unitLabel); // unit label
	buttonLayout->addWidget(*button, Qt::AlignLeft); // button
	buttonLayout->addSpacing(10);

	return buttonLayout;
}

// coded along with ai
void DuctLayout::callExecuteControl(buttonType button, int newValue)
{
	emit ductButtonClicked(button, newValue);
}