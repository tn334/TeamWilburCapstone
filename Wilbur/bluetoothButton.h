#pragma once
#ifndef BLUETOOTHBUTTON_H
#define BLUETOOTHBUTTON_H

// Header Files
#include "customButton.h" // QPushButton included here
#include "inputDirector.h" // Where buttonType is defined
class BluetoothButton :
    public CustomButton
{
    Q_OBJECT

public:
    explicit BluetoothButton(QWidget* parent = nullptr);
    QSize sizeHint() const override;

    //method to set the bluetooth conection status
    void handleButtonClicked(buttonType button, int newValue);

    //Function to get current state
    bool getState() const { return isConnected; }

    void setState(bool newState) { isConnected = newState; }

signals:
    void bluetoothButtonClicked(buttonType button, int newValue);

private:
    bool isConnected; // tracking bluetooth connection status
};

#endif // BLUETOOTHBUTTON_H