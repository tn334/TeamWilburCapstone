#pragma once
#ifndef SLIDERLAYOUT_H
#define SLIDERLAYOUT_H

// Header Files
// QWidget and QLabel included in stiffnessSlider.h
#include "stiffnessSlider.h"
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

<<<<<<< Updated upstream
    void resizeEvent(QResizeEvent* event);

    //void updateTitle(int value);
=======
    // void updateTitle(int value);
>>>>>>> Stashed changes

public slots:

private:
    QLabel* labelOff;
    QLabel* labelLow;
    QLabel* labelMedium;
    QLabel* labelHigh;
    QLabel* title;
    QGridLayout* sLayout;
};

#endif // SLIDERLAYOUT_H