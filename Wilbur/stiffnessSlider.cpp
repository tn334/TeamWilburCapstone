// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// Qt webpage breakdown of abstract slider https://doc.qt.io/qt-6/qslider.html

#include "stiffnessSlider.h"

StiffnessSlider::StiffnessSlider(QWidget *parent) 
    : QSlider(Qt::Horizontal, parent)
{
    //setting tooltip for slider
    setToolTip("Drag Slider to select a stiffness mode");
    
    //To add text above slider ticks https://forum.qt.io/topic/101343/qslider-with-text-at-tick-marks
    
    //creating slider
    slider = new QSlider(Qt::Horizontal, this);
        //Setting up actual slider parameters
    setFocusPolicy(Qt::StrongFocus);
        //setting maximum limit for slider range
    setMaximum(3);
        //set minimum limit at 0
    setMinimum(0);
        //display tick marks on top and bottom of slider
    setTickPosition(QSlider::TicksBothSides);
        // creates 4 total ticks at off, 33-Low, 66-Medium and 99-High
    setTickInterval(1);
    //creating title
    title = new QLabel("Nipple Stiffness Control:");
    //set parent of title
    title->setParent(parent);
    title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    title->setStyleSheet("font: bold 12px;");
    //Setting Label Style
    labelOff = new QLabel("Off");
    labelOff->setParent(parent);
    labelOff->setStyleSheet("font: bold 12px;");
    labelLow = new QLabel("Low");
    labelLow->setParent(parent);
    labelLow->setStyleSheet("font: bold 12px;");
    labelMedium = new QLabel("Medium");
    labelMedium->setParent(parent);
    labelMedium->setStyleSheet("font: bold 12px;");
    labelHigh = new QLabel("High");
    labelHigh->setParent(parent);
    labelHigh->setStyleSheet("font: bold 12px;");
    
    // create and initialize the layout
    sliderLayout = new QGridLayout(this);
    sliderLayout->addWidget(title, 0, 0, 1, 1, Qt::AlignLeft);
    sliderLayout->addWidget(labelOff, 1, 0, 1, 1);
    sliderLayout->addWidget(labelLow, 1, 1, 1, 1, Qt::AlignLeft);
    sliderLayout->addWidget(labelMedium, 1, 3, 1, 1, Qt::AlignRight);
    sliderLayout->addWidget(labelHigh, 1, 5, 1, 1, Qt::AlignRight);
    sliderLayout->addWidget(slider, 2, 0, 1, 6);

    connect(slider, &QSlider::valueChanged, this, &StiffnessSlider::updateValue);
}

//deconstructor
StiffnessSlider::~StiffnessSlider()
{
    // delete the slider, the labels, and the layout
    delete slider;
    delete title;
    delete labelOff;
    delete labelLow;
    delete labelMedium;
    delete labelHigh;
    delete sliderLayout;
}

//void StiffnessSlider::updateLabel(int value)
//{
//    // update the label text according to the slider value
//    if (value == 0) {
//        title->setText("Nipple Stiffness Control: Off");
//    }
//    else if (value <= 33) {
//        title->setText("Nipple Stiffness Control: Low");
//    }
//    else if (value <= 66) {
//        title->setText("Nipple Stiffness Control: Medium");
//    }
//    else {
//        title->setText("Nipple Stiffness Control: High");
//    }
//}

//Function Implementation
void StiffnessSlider::updateValue(int value) {
    if (validValue(value)) {
        // Emit the slider value when it changes
        emit sliderValueChanged(value);
    }
    // update the label text according to the slider value
    if (value == 0) {
        title->setText("Nipple Stiffness Control: Off");
    }
    else if (value <= 33) {
        title->setText("Nipple Stiffness Control: Low");
    }
    else if (value <= 66) {
        title->setText("Nipple Stiffness Control: Medium");
    }
    else {
        title->setText("Nipple Stiffness Control: High");
    }
}

bool StiffnessSlider::validValue(int value) {
    // Perform any validation checks if needed
    // For simplicity, consider all values as valid in this example
    Q_UNUSED(value);
    return true;
}
