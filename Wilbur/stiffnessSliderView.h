#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html

#ifndef STIFFNESSSLIDERVIEW_H
#define STIFFNESSSLIDERVIEW_H

#include <QWidget>
#include <QGroupBox>
#include <QSlider>
#include <QMainWindow>
#include <QLabel>

class StiffnessSliderView : public QSlider
{
    Q_OBJECT

public:
    explicit StiffnessSliderView(QWidget* parent = nullptr);
	int test = 0;
    ~StiffnessSliderView();

signals:
    void sliderValueChanged(bool newState);

private slots:
    void handleSliderValueChanged();

private:
    //properties
    QSlider* slider;

    //methods
    bool validValue(int value);
    
    int previousValue;
};

#endif // STIFFNESSSLIDERVIEW_H