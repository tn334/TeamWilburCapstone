#pragma once
#ifndef BLUETOOTHBUTTON_H
#define BLUETOOTHBUTTON_H

#include <qpushbutton.h>
#include "customButton.h" // local file


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
