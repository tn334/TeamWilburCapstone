// Header Files
#include "ductButtonView.h"

// Duct Button Constructor
DuctButtonView::DuctButtonView(QWidget* parent)
	: BaseButtonView("Click to change state of the duct",
		"Closed", QColor(136, 34, 85), parent), isOpen(false) // initialize state to false
{

	//connect button to event handler(clicked)
	connect(this, &DuctButtonView::clicked, this, & DuctButtonView::handleButtonClicked);

	// set resizing policies for horizontal and vertical sizes
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

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
bool DuctButtonView::getState() const {return isOpen;}

void DuctButtonView::setState(bool newState) {isOpen = newState;}

// Button Clicks Handler
void DuctButtonView::handleButtonClicked()
{
	// Toggle the connection status
	isOpen = !isOpen;

	// Update the button text based on the new connection status
	if (isOpen)
	{
		// Update text and style sheet when connection is made
		setText("Open");
		setStyleSheet("color: white;"
			"background-color: #117733;"
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