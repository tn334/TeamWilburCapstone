#include "BluetoothButton.h"

BluetoothButton::BluetoothButton(QWidget* parent)
	: CustomButton("Click to establish bluetooth connection to prototype",
		"Disconnected", QColor(136, 204, 238), parent)
{
	//initialize the connection status to false
	isConnected = false;

	// connect button to event handler(clicked) and function(handleButtonClicked)
	connect(this, &BluetoothButton::clicked, this, &BluetoothButton::handleButtonClicked); 
	//set a fixed size for the button
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	//setFixedSize(125, 50);
	setStyleSheet("color: white;"
		"background-color: #88CCEE;"
		"border-width: 2px;"
		"border-style: outset;"
		"border-radius: 4px;"
		"font: bold 12px; ");
}


//Function implementations
QSize BluetoothButton::sizeHint() const
{
	// Return a QSize object with the fixed width and height
	return QSize(125, 50);
}

void BluetoothButton::handleButtonClicked()
{
	// Toggle the connection status
	isConnected = !isConnected;

	// Update the button text based on the new connection status
	if (isConnected)
	{
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
		setText("Disconnected");
		setStyleSheet("color: white;"
			"background-color: #88CCEE;"
			"border-width: 2px;"
			"border-style: outset;"
			"border-radius: 4px;"
			"font: bold 12px; ");
	}
		
	//bluetooth control backend?

}