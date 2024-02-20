#pragma once
#ifndef SLIDERLAYOUT_H
#define SLIDERLAYOUT_H

#include "stiffnessSlider.h"

#include <qwidget.h>
#include <QLabel>
#include <QGridLayout>
#include <qstyle.h>
#include <QResizeEvent>

class SliderLayout : public QWidget
{
	Q_OBJECT

public:
    explicit SliderLayout(QWidget* parent = nullptr);
    ~SliderLayout();

    void resizeEvent(QResizeEvent* event);

    //void updateTitle(int value);

public slots:

private:
    
    StiffnessSlider* stiffnessSlider;
    QLabel* labelOff;
    QLabel* labelLow;
    QLabel* labelMedium;
    QLabel* labelHigh;
    QLabel* title;
    QGridLayout* sLayout;

};
#endif // SLIDERLAYOUT_H
