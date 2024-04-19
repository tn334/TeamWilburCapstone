#pragma once
#ifndef WILBURTEST_H
#define WILBURTEST_H
#include <QtWidgets/QMainWindow>
#include "ui_WilburTest.h"
#include <QTest>

class WilburTest : public QMainWindow
{
    Q_OBJECT

public:
    WilburTest(QWidget *parent = nullptr);
    ~WilburTest();

private:
    Ui::WilburTestClass ui;
};

#endif // WILBURTEST_H
