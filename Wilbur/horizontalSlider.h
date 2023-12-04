#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef HORIZONTALSLIDERS_H
#define HORIZONTALSLIDERS_H

#include <QGroupBox>
#include <QSlider>
#include <QMainWindow>

class HorizontalSlider : public QSlider
{
    Q_OBJECT

public:
    HorizontalSlider(QWidget* parent = nullptr);

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