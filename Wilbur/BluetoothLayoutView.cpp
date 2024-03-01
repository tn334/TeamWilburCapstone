#include "BluetoothLayoutView.h"

BluetoothLayoutView::BluetoothLayoutView(QWidget* parent) : QWidget(parent)
{
    // Create bluetooth label and button
    bluetoothLabel = new QLabel("Bluetooth Connection:");
    bluetoothLabel->setStyleSheet("font: bold 14px; ");
    bluetoothButton = new BluetoothButtonView(this);

    connect(bluetoothButton, &BluetoothButtonView::clicked, this, [this] {
        callExecuteControl(CONNECT, bluetoothButton->getState());
        });

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
