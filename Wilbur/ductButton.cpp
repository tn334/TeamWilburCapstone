// Header Files
#include "ductButton.h"

// Duct Button Constructor
DuctButton::DuctButton(QWidget* parent)
	: CustomButton("Click to change state of the duct",
		"Closed", QColor(136, 34, 85), parent)
{
	//initialize isOpen to default of false
	isOpen = false;

	//connect button to event handler(clicked)
	connect(this, &DuctButton::clicked, this, & DuctButton::handleButtonClicked);

	// set resizing policies for horizontal and vertical sizes
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	//setFixedSize(80, 30);

	//style sheet information https://doc.qt.io/qt-6/stylesheet-examples.html
	// Set style sheet for created button
	this->setStyleSheet("color: white;"
		"background-color: #882255;"
		"border-width: 2px;"
		"border-style: outset;"
		"border-radius: 4px;"
		"font: bold 12px; ");

}

//Function implementations
bool DuctButton::getState() const {return isOpen;}

void DuctButton::setState(bool newState) {isOpen = newState;}

// Button Clicks Handler
void DuctButton::handleButtonClicked()
{
	// Toggle the connection status
	isOpen = !isOpen;

	// Update the button text based on the new connection status
	if (isOpen)
	{
		// Update text and style sheet when connection is made
		setText("Connected");
		setStyleSheet("color: white;"
			"background-color: #332288;"
			"border-width: 2px;"
			"border-style: outset;"
			"border-radius: 4px;"
			"font: bold 12px; ");
	}
	
	else
	{
		// Update text and style sheet when connection is closed
		setText("Closed");
		setStyleSheet("color: white;"
			"background-color: #882255;"
			"border-width: 2px;"
			"border-style: outset;"
			"border-radius: 4px;"
			"font: bold 12px;");
	}
}