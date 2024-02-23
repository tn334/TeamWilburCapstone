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
    explicit SliderLayout(QWidget* parent = nullptr);
    ~SliderLayout();
    StiffnessSlider* stiffnessSlider;

    void resizeEvent(QResizeEvent* event);

    //void updateTitle(int value);

private:
    QLabel* labelOff;
    QLabel* labelLow;
    QLabel* labelMedium;
    QLabel* labelHigh;
    QLabel* title;
    QGridLayout* stiffSliderLayout;
};

#endif // SLIDERLAYOUT_H