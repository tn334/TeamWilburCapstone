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
}

void HorizontalSlider::setValue(int value)

{
    QSlider::setValue(value);
}

void HorizontalSlider::setMinimum(int value)

{
    QSlider::setMinimum(value);
}

void HorizontalSlider::setMaximum(int value)

{
    QSlider::setMaximum(value);
}

