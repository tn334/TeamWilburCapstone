// Local Header Files
#include "ductLayout.h"

DuctLayout::DuctLayout(QWidget* parent)
{
	// declare label names
	buttonLabelOne = new QLabel("Duct One:");
	buttonLabelTwo = new QLabel("Duct Two:");
	buttonLabelThree = new QLabel("Duct Three:");

	// instantiate buttons for ducts 1-3
	buttonOne = new DuctButton();
	buttonTwo = new DuctButton();
	buttonThree = new DuctButton();

	// set button event handlers
	connect(buttonOne, &DuctButton::clicked, this, [this]() {
		callExecuteControl(VALVE1, buttonOne->getState());
	});
	connect(buttonTwo, &DuctButton::clicked, this, [this]() {
		callExecuteControl(VALVE2, buttonTwo->getState());
	});
	connect(buttonThree, &DuctButton::clicked, this, [this]() {
		callExecuteControl(VALVE3, buttonThree->getState());
	});

	// declare grid layout
	buttonLayout = new QGridLayout;
	buttonLayout->addWidget(buttonLabelOne, 0, 0, 1, 1, Qt::AlignLeft);
	buttonLayout->addWidget(buttonOne, 0, 1, 1, 1, Qt::AlignLeft);
	buttonLayout->addWidget(buttonLabelTwo, 0, 2, 1, 1, Qt::AlignLeft);
	buttonLayout->addWidget(buttonTwo, 0, 3, 1, 1, Qt::AlignLeft);
	buttonLayout->addWidget(buttonLabelThree, 0, 4, 1, 1, Qt::AlignRight);
	buttonLayout->addWidget(buttonThree, 0, 5, 1, 1, Qt::AlignRight);
	setLayout(buttonLayout);

};

DuctLayout::~DuctLayout()
{
	// delete label objects
	delete buttonLabelOne;
	delete buttonLabelTwo;
	delete buttonLabelThree;

	// delete button objects
	delete buttonOne;
	delete buttonTwo;
	delete buttonThree;

	// delete grid object
	delete buttonLayout;
}

// coded along with ai
void DuctLayout::callExecuteControl(buttonType button, int newValue)
{
	emit ductButtonClicked(button, newValue);
}