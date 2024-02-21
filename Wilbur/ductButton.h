#pragma once
#ifndef DUCTBUTTON_H
#define DUCTBUTTON_H

// Header Files
#include "customButton.h"

class DuctButton : public CustomButton
{
    Q_OBJECT

public:
    explicit DuctButton(QWidget* parent = nullptr);

    void handleButtonClicked();

    //Function to get current state
    bool getState() const;

    //function to set current state
    void setState(bool newState);

signals:
    void stateChanged(bool newState);

private:
    bool isOpen; // tracking if duct is open or closed state
};

#endif // DUCTBUTTON_H