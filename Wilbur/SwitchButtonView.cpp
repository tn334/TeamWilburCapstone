// Header Files
#include "SwitchButtonView.h"

// Duct Button Constructor
SwitchButtonView::SwitchButtonView(ConnectionButtonView* connectionButton, QWidget* parent)
	: BaseButtonView("Click to change state of the switch",
		"Closed", QColor(136, 34, 85), parent), isOpen(false), connectButton(connectionButton) // initialize state to false
{
	//connect button to event handler(clicked)
	connect(this, &SwitchButtonView::clicked, this, &SwitchButtonView::handleButtonClicked);

	// set resizing policies for horizontal and vertical sizes
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	initialSetupStyle();
}

//Function implementations

void SwitchButtonView::initialSetupStyle()
{
	//style sheet information https://doc.qt.io/qt-6/stylesheet-examples.html
	// Set the initial stylesheet
	setStyleSheet("color: white;"
		"background-color: #882255;"
		"border-width: 2px;"
		"border-color: #333333;"
		"border-style: outset;"
		"border-radius: 4px;"
		"font: bold 12px; ");
}

// Button Clicks Handler
void SwitchButtonView::handleButtonClicked()
{
	if (!connectButton->getState())
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Warning");
		msgBox.setText("The prototype is not connected!");

		// Set text color
		QPalette palette = msgBox.palette();
		palette.setColor(QPalette::Text, Qt::white); // Change text color to red
		msgBox.setPalette(palette);

		// Set background color
		msgBox.setStyleSheet("QMessageBox { background-color: #333333; }"
			"QPushButton { background-color: #333333; }"); // Change background color to light gray

		msgBox.exec();
		//QMessageBox::warning(this, "Warning", "The Application is not connected to the Prototype!");
		return;
	}
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
			"border-color: #333333;"
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
			"border-color: #333333;"
			"border-style: outset;"
			"border-radius: 4px;"
			"font: bold 12px;");
	}
}