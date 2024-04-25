#pragma once
#ifndef SWITCHBUTTONVIEW_H
#define SWITCHBUTTONVIEW_H

// Header Files
#include "BaseButtonView.h"
#include "ConnectionButtonView.h"
#include <QMessageBox>

class SwitchButtonView : public BaseButtonView
{
    Q_OBJECT

public:
    explicit SwitchButtonView(ConnectionButtonView* connectionButton, QWidget* parent = nullptr);

    void initialSetupStyle();

    void handleButtonClicked();

    //Function to get current state
    bool getState() const { return isOpen; };

    //function to set current state
    void setState(bool newState) { isOpen = newState; };

protected:
    ConnectionButtonView* connectButton;

private:
    bool isOpen; // tracking if switch is open or closed state
};

#endif // SWITCHBUTTONVIEW_H