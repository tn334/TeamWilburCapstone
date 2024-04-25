#include "ConnectionLayoutView.h"

ConnectionLayoutView::ConnectionLayoutView(ConnectionButtonView* connectionButton, QWidget* parent) : connectButton(connectionButton)
{
    // Create bluetooth label and button
    connectionLabel = new QLabel("Connection:");
    connectionLabel->setStyleSheet("font: bold 14px; ");

    connect(connectButton, &ConnectionButtonView::clicked, this, [this] {
        callExecuteControl(CONNECT, connectButton->getState());
        });
    //connect(connectionButton, &ConnectionButtonView::clicked, this, 
        //&ConnectionLayoutView::toggleBluetoothConnection);

    //Bluetooth layout
    layout = new QGridLayout(this);
    layout->addWidget(connectionLabel, 0, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(connectButton, 0, 1, 1, 1);
};

ConnectionLayoutView::~ConnectionLayoutView()
{
    delete connectionLabel;
    delete layout;
}

void ConnectionLayoutView::callExecuteControl(buttonType button, int newValue)
{
    emit connectionButtonClicked(button, newValue);
}

// TBD by backend hook up
//void ConnectionLayoutView::toggleBluetoothConnection(bool isConnected)
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
