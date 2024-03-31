// Header Files
#include "ConnectionButtonView.h"

// ConnectionButtonView Constructor
ConnectionButtonView::ConnectionButtonView(QWidget* parent)
	: BaseButtonView("Click to establish connection to prototype",
		"Disconnected", QColor(136, 204, 238), parent), isConnected(false) //initialize button to disconnected
{
	connect(this, &ConnectionButtonView::clicked, this, &ConnectionButtonView::handleButtonClicked);

	// set a fixed size for the button
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	// set style sheet to button
	setStyleSheet("color: white;"
		"background-color: #88CCEE;"
		"border-width: 2px;"
		"border-color: #333333;"
		"border-style: outset;"
		"border-radius: 4px;"
		"font: bold 12px; ");
}


//Function implementations
QSize ConnectionButtonView::sizeHint() const
{
	// Return a QSize with the fixed width and height
	return QSize(125, 50);
}

bool ConnectionButtonView::getState() const { return isConnected; }

void ConnectionButtonView::setState(bool newState) { isConnected = newState; }

// Handler of button clicks
void ConnectionButtonView::handleButtonClicked()
{
	// Toggle the connection status
	isConnected = !isConnected;

	// Update the button text based on the new connection status
	if (isConnected)
	{
		// Update text and style sheet to connected
		setText("Connected");
		setStyleSheet("color: white;"
			"background-color: #332288;"
			"border-width: 2px;"
			"border-color: #333333;"
			"border-style: outset;"
			"border-radius: 4px;"
			"font: bold 12px; ");
	}

	else
	{
		// Update text and style sheet to disconnected
		setText("Disconnected");
		setStyleSheet("color: white;"
			"background-color: #88CCEE;"
			"border-width: 2px;"
			"border-color: #333333;"
			"border-style: outset;"
			"border-radius: 4px;"
			"font: bold 12px; ");
	}
}