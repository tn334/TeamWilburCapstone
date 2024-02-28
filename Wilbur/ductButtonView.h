#pragma once
#ifndef DUCTBUTTONVIEW_H
#define DUCTBUTTONVIEW_H

// Header Files
#include "customButton.h"

class DuctButtonView : public CustomButton
{
    Q_OBJECT

public:
    explicit DuctButtonView(QWidget* parent = nullptr);

    void handleButtonClicked();

    //Function to get current state
    bool getState() const;

    //function to set current state
    void setState(bool newState);

//signals:
    //void stateChanged(bool newState);

private:
    bool isOpen; // tracking if duct is open or closed state
};

#endif // DUCTBUTTONVIEW_H