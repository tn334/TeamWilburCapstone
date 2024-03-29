#pragma once
#ifndef CONNECTIONBUTTONVIEW_H
#define CONNECTIONBUTTONVIEW_H

// Header Files
#include "BaseButtonView.h" // QPushButton included here

class ConnectionButtonView : public BaseButtonView
{
    Q_OBJECT

public:
    explicit ConnectionButtonView(QWidget* parent = nullptr);
    
    QSize sizeHint() const override;

    //method to set the conection status
    void handleButtonClicked();

    //Function to get current state
    bool getState() const;

    void setState(bool newState);

signals:


private:
    bool isConnected; // tracking connection status
};

#endif // CONNECTIONBUTTONVIEW_H