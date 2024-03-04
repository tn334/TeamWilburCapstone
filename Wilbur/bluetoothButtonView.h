#pragma once
#ifndef BLUETOOTHBUTTONVIEW_H
#define BLUETOOTHBUTTONVIEW_H

// Header Files
#include "BaseButtonView.h" // QPushButton included here
#include "InputDirectorViewModel.h" // Where buttonType is defined
class BluetoothButtonView : public BaseButtonView
{
    Q_OBJECT

public:
    explicit BluetoothButtonView(QWidget* parent = nullptr);
    
    QSize sizeHint() const override;

    //method to set the bluetooth conection status
    void handleButtonClicked();

    //Function to get current state
    bool getState() const;

    void setState(bool newState);

signals:
    int bluetoothConnectionRequested(bool isConnected);

private:
    bool isConnected; // tracking bluetooth connection status
};

#endif // BLUETOOTHBUTTONVIEW_H