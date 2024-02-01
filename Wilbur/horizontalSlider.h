#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html

#ifndef HORIZONTALSLIDERS_H
#define HORIZONTALSLIDERS_H

#include <QGroupBox>
#include <QSlider>
#include <QMainWindow>
#include <QLabel>

class HorizontalSlider : public QSlider
{
    Q_OBJECT

public:
    HorizontalSlider(QWidget* parent = nullptr);
    QLabel* labelOne = new QLabel("Off", this);
    QLabel* labelTwo = new QLabel("Low", this);
    QLabel* labelThree = new QLabel("Medium", this);
    QLabel* labelFour = new QLabel("High", this);


    /*int getValue() const;
    int setValue(int newVal);*/

signals:
    void sliderValueChanged(bool newState);
    //void stringReturned(const QString& string);

//public slots:
    //void setValue(int value);
    /*void setMinimum(int value);
    void setMaximum(int value)*/;

private slots:
    void updateValue(int value);

private:
    //int currentValue;
    //int newValue;
    bool validValue(int value);


};

#endif // HORIZONTALSLIDERS_H