#include "BluetoothButton.h"

BluetoothButton::BluetoothButton(QWidget* parent)
	: CustomButton("Bluetooth Connection", "Click to establish bluetooth connection to prototype",
		"Disconnected", QColor(136, 204, 238), parent)
{
	//initialize the connection status to false
	isConnected = false;

	// connect button to event handler(clicked) and function(handleButtonClicked)
	connect(this, &BluetoothButton::clicked, this, &BluetoothButton::handleButtonClicked);

	//set a fixed size for the button
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setFixedSize(100, 50);
}



void BluetoothButton::handleButtonClicked()
{
	// Toggle the connection status
	isConnected = !isConnected;

	// Update the button text based on the new connection status
	if (isConnected)
	{
		setText("Bluetooth Connected");
		setStyleSheet("background-color: #332288");
	}
	else
	{
		setText("Connect Bluetooth");
		setStyleSheet("background-color: #88CCEE");
	}
		

}