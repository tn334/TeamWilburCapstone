// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "button.h"


Button::Button(QString text, QWidget * parent)
    : QToolButton(parent), currentState(false) // initialize current state of button
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    //State should always start in the open position
    setText(text);
    setToolTip("Press button to open or close duct");

    connect(this, &Button::clicked, this, &Button::buttonStateChange);
}

QSize Button::sizeHint() const

{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}

bool Button::getState() const
{
    return currentState;
}

void Button::setState(bool newState)
{
    currentState = newState;
    
}

void Button::buttonStateChange()
{
    // Toggle the state when the button is clicked
    currentState = !currentState;
    //TODO change text of button from Open to close or vice versa
    if (currentState == true)
    {
        this->setText("Open");
    }
    else { this->setText("Closed"); }

    // Emit the modified clicked signal
    //emit clicked(currentState, text(), currentState);
}