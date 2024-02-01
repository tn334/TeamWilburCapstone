// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// Qt webpage breakdown of abstract slider https://doc.qt.io/qt-6/qslider.html

#include "horizontalSlider.h"

HorizontalSlider::HorizontalSlider(QWidget *parent) 
    : QSlider(Qt::Horizontal, parent)
{
    setFocusPolicy(Qt::StrongFocus);
    //setting maximum limit for slider range
    setMaximum(3);
    //set minimum limit at 0
    setMinimum(0);
    //display tick marks on top and bottom of slider
    setTickPosition(QSlider::TicksBothSides);
    // creates 4 total ticks at off, 33, 66 and 99
    setTickInterval(1);
    
    //To add text above slider ticks https://forum.qt.io/topic/101343/qslider-with-text-at-tick-marks
    
    //Setting Label Style
    this->labelOne->setStyleSheet("font: bold 12px;");
    this->labelTwo->setStyleSheet("font: bold 12px;");
    this->labelThree->setStyleSheet("font: bold 12px;");
    this->labelFour->setStyleSheet("font: bold 12px;");
    //TODO add text to slider ticks and thicken tick marks
    setToolTip("Drag Slider to select a stiffness mode");

    connect(this, &QSlider::valueChanged, this, &HorizontalSlider::updateValue);
}

//void HorizontalSlider::setValue(int value)
//
//{
//    QSlider::setValue(value);
//
//    //this is an attempt to create a dialogue output to the mainwindow
//    emit stringReturned("Your string here");
//}

//void HorizontalSlider::setMinimum(int value)
//
//{
//    QSlider::setMinimum(value);
//}
//
//void HorizontalSlider::setMaximum(int value)
//
//{
//    QSlider::setMaximum(value);
//}

//bool HorizontalSlider::getValue() const
//{
//    return currentValue;
//}
//
//void Button::setState(bool newState)
//{
//    currentValue = newValue;
//}

//void HorizontalSlider::updateValue(int newValue)
//{
//    currentValue = newValue;
//}

void HorizontalSlider::updateValue(int value) {
    if (validValue(value)) {
        // Emit the slider value when it changes
        emit sliderValueChanged(value);
    }
}


//REDUNDANT USELESS
bool HorizontalSlider::validValue(int value) {
    // Perform any validation checks if needed
    // For simplicity, consider all values as valid in this example
    Q_UNUSED(value);
    return true;
}

