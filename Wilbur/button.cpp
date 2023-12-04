// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "button.h"


Button::Button(const QString& text, QWidget * parent)
    : QToolButton(parent), currentState(false) // initialize current state of button
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);

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

    // Emit the modified clicked signal
    //emit clicked(currentState, text(), currentState);
}