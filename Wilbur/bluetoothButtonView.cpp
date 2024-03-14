// Header Files
#include "BluetoothButtonView.h"

// BluetoothButtonView Constructor
BluetoothButtonView::BluetoothButtonView(QWidget* parent)
	: BaseButtonView("Click to establish bluetooth connection to prototype",
		"Disconnected", QColor(136, 204, 238), parent), isConnected(false) //initialize button to disconnected
{
	connect(this, &BluetoothButtonView::clicked, this, &BluetoothButtonView::handleButtonClicked);

	// set a fixed size for the button
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	// set style sheet to button
	setStyleSheet("color: white;"
		"background-color: #88CCEE;"
		"border-width: 2px;"
		"border-style: outset;"
		"border-radius: 4px;"
		"font: bold 12px; ");
}


//Function implementations
QSize BluetoothButtonView::sizeHint() const
{
	// Return a QSize with the fixed width and height
	return QSize(125, 50);
}

bool BluetoothButtonView::getState() const { return isConnected; }

void BluetoothButtonView::setState(bool newState) { isConnected = newState; }

// Handler of button clicks
void BluetoothButtonView::handleButtonClicked()
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
			"border-style: outset;"
			"border-radius: 4px;"
			"font: bold 12px; ");
	}
}