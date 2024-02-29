// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// Qt webpage breakdown of abstract slider https://doc.qt.io/qt-6/qslider.html

// Header Files
#include "stiffnessSliderView.h"

// Stiffness Slider Constructor
StiffnessSliderView::StiffnessSliderView(QWidget *parent) 
    : QSlider(Qt::Horizontal, parent)
{
    // setting tooltip for slider
    setToolTip("Drag Slider to select a stiffness mode");
    
    //To add text above slider ticks https://forum.qt.io/topic/101343/qslider-with-text-at-tick-marks
	
    //creating slider
    slider = new QSlider(Qt::Horizontal);

    //Setting up actual slider parameters
    setFocusPolicy(Qt::StrongFocus);

    //set minimum limit at 0
    setMinimum(0);

    //setting maximum limit for slider range
    setMaximum(3);

    //display tick marks on top and bottom of slider
    setTickPosition(QSlider::TicksBothSides);

    // creates 4 total ticks at off, 33-Low, 66-Medium and 99-High
    setTickInterval(1);

	// Connect slider to value updates
    connect(slider, &QSlider::valueChanged, this, &StiffnessSliderView::updateValue);
}

// deconstructor
StiffnessSliderView::~StiffnessSliderView()
{
    // delete the slider
    delete slider;
}

// Update slider value
void StiffnessSliderView::updateValue(int value) 
{
	// Check if the value is valid
    if (validValue(value)) 
	{
        // Emit the slider value when it changes
        emit sliderValueChanged(value);
    }
    
}

// Validate values
bool StiffnessSliderView::validValue(int value) 
{
    // Perform any validation checks if needed
    // For simplicity, consider all values as valid in this example
    Q_UNUSED(value);
    return true;
}
