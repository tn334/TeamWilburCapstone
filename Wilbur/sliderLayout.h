#pragma once
#ifndef SLIDERLAYOUT_H
#define SLIDERLAYOUT_H

// Header Files
#include "stiffnessSlider.h" // QWidget and QLabel included here
#include <QGridLayout>
#include <qstyle.h>
#include <QResizeEvent>

class SliderLayout : public QWidget
{
    Q_OBJECT

public:
    // constructor
    explicit SliderLayout(QWidget* parent = nullptr);

    // destructor
    ~SliderLayout();
    
    // create slider variable
    StiffnessSlider* stiffnessSlider;

    // function to resize the size of the slider
    void resizeEvent(QResizeEvent* event);

    //void updateTitle(int value);

private:
    // create label variables
    QLabel* labelOff;
    QLabel* labelLow;
    QLabel* labelMedium;
    QLabel* labelHigh;
    QLabel* title;
    
    // create layout variable
    QGridLayout* stiffSliderLayout;
};

#endif // SLIDERLAYOUT_H