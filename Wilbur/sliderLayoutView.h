#pragma once
#ifndef SLIDERLAYOUTVIEW_H
#define SLIDERLAYOUTVIEW_H

// Header Files
#include "stiffnessSliderView.h" // QWidget and QLabel included here
#include <QGridLayout>
#include <qstyle.h>
#include <QResizeEvent>

class SliderLayoutView : public QWidget
{
    Q_OBJECT

public:
    // constructor
    explicit SliderLayoutView(QWidget* parent = nullptr);

    // destructor
    ~SliderLayoutView();
    
    // create slider variable
    StiffnessSliderView* stiffnessSlider;

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

#endif // SLIDERLAYOUTVIEW_H