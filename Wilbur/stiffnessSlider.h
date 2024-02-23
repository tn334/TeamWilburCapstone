#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html

#ifndef STIFFNESSSLIDER_H
#define STIFFNESSSLIDER_H

#include <QWidget>
#include <QGroupBox>
#include <QSlider>
#include <QMainWindow>
#include <QLabel>

class StiffnessSlider : public QSlider
{
    Q_OBJECT

public:
    explicit StiffnessSlider(QWidget* parent = nullptr);
	int test = 0;
    ~StiffnessSlider();

private:
    //properties
    QSlider* slider;

    //methods
    bool validValue(int value);

signals:
    void sliderValueChanged(bool newState);

private slots:
    void updateValue(int value);
};

#endif // STIFFNESSSLIDER_H