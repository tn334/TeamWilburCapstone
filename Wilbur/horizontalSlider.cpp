// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "horizontalSlider.h"

HorizontalSlider::HorizontalSlider(QWidget *parent) 
    : QSlider(Qt::Horizontal, parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setTickPosition(QSlider::TicksBothSides);
    setTickInterval(10);
    setSingleStep(1);

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

