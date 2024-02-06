#pragma once
#ifndef DUCTBUTTON_H
#define DUCTBUTTON_H
#include "customButton.h"

class DuctButton : public CustomButton
{
    Q_OBJECT
public:
    explicit DuctButton(QWidget* parent = nullptr);
    enum ValveState { Closed, Open };
    Q_ENUM(ValveState)
    //method set to handle button clicked (redundant with bluetooth so maybe 
    //incorp into base class
    void handleButtonClicked();

    //Function to get current state
    bool getState() const;

    //function to set current state
    void setState(bool newState);
//public slots:
//    void handleButtonPressed(int valveNumber);
//    void controlManipulated(std::string objectName, int newValue);

signals:
    void stateChanged(bool newState);

private:
    bool isOpen; // tracking if duct is open or closed state

};
#endif // DUCTBUTTON_H

