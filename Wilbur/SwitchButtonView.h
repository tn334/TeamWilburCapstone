#pragma once
#ifndef SWITCHBUTTONVIEW_H
#define SWITCHBUTTONVIEW_H

// Header Files
#include "BaseButtonView.h"

class SwitchButtonView : public BaseButtonView
{
    Q_OBJECT

public:
    explicit SwitchButtonView(QWidget* parent = nullptr);

    void handleButtonClicked();

    //Function to get current state
    bool getState() const;

    //function to set current state
    void setState(bool newState);

private:
    bool isOpen; // tracking if switch is open or closed state
};

#endif // SWITCHBUTTONVIEW_H