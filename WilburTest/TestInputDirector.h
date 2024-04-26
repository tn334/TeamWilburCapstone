#pragma once
#ifndef TESTINPUTDIRECTOR_H
#define TESTINPUTDIRECTOR_H

#include "InputDirectorViewModel.h"
#include "WilburApplicationView.h"
#include <QObject>
#include <QTest>


class TestInputDirector : public QObject
{
    Q_OBJECT
private slots:
    void testConstructor();
    void testSimFunctions();
};

#endif // TESTINPUTDIRECTOR_H