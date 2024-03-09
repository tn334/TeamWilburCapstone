#include "BluetoothLayoutView.h"

BluetoothLayoutView::BluetoothLayoutView(QWidget* parent)
{
    // Create bluetooth label and button
    bluetoothLabel = new QLabel("Bluetooth Connection:");
    bluetoothLabel->setStyleSheet("font: bold 14px; ");
    bluetoothButton = new BluetoothButtonView(this);

    connect(bluetoothButton, &BluetoothButtonView::clicked, this, [this] {
        callExecuteControl(CONNECT, bluetoothButton->getState());
        });
    //connect(bluetoothButton, &BluetoothButtonView::clicked, this, 
        //&BluetoothLayoutView::toggleBluetoothConnection);

    //Bluetooth layout
    layout = new QGridLayout(this);
    layout->addWidget(bluetoothLabel, 0, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(bluetoothButton, 0, 1, 1, 1);

};

BluetoothLayoutView::~BluetoothLayoutView()
{
    delete bluetoothLabel;
    delete bluetoothButton;
    delete layout;
}

void BluetoothLayoutView::callExecuteControl(buttonType button, int newValue)
{
    emit bluetoothButtonClicked(button, newValue);
}

// TBD by backend hook up
//void BluetoothLayoutView::toggleBluetoothConnection(bool isConnected)
//{
//    if (isConnected)
//    {
//        // Trigger Bluetooth connection here
//        // For example:
//        //bluetoothClient->connectToDevice();
//    }
//    else
//    {
//        // Trigger Bluetooth disconnection here
//        // For example:
//        // bluetoothClient->disconnectFromDevice();
//    }
//}
