#pragma once
#ifndef BLUETOOTHBUTTON_H
#define BLUETOOTHBUTTON_H

// Header Files
#include "customButton.h" // QPushButton included here

class BluetoothButton :
    public CustomButton
{
    Q_OBJECT

public:
    explicit BluetoothButton(QWidget* parent = nullptr);
    QSize sizeHint() const override;

    //method to set the bluetooth conection status
    void handleButtonClicked();

private:
    bool isConnected; // tracking bluetooth connection status
};

#endif // BLUETOOTHBUTTON_H