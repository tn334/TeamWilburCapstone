#pragma once
#ifndef DUCTBUTTONVIEW_H
#define DUCTBUTTONVIEW_H

// Header Files
#include "BaseButtonView.h"

class DuctButtonView : public BaseButtonView
{
    Q_OBJECT

public:
    explicit DuctButtonView(QWidget* parent = nullptr);

    void handleButtonClicked();

    //Function to get current state
    bool getState() const;

    //function to set current state
    void setState(bool newState);

private:
    bool isOpen; // tracking if duct is open or closed state
};

#endif // DUCTBUTTONVIEW_H