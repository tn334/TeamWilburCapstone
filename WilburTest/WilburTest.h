#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WilburTest.h"
#include <QTest>

#include "WilburApplicationView.h"

class WilburTest : public QMainWindow
{
    Q_OBJECT

public:
    WilburTest(QWidget *parent = nullptr);
    ~WilburTest();

private:
    Ui::WilburTestClass ui;
};
