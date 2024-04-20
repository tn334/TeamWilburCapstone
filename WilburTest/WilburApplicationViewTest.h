#pragma once
#ifndef WILBURAPPLICATIONVIEWTEST_H
#define WILBURAPPLICATIONVIEWTEST_H
#include "WilburApplicationView.h"

#include <QTest>
#include <QObject>

class WilburApplicationViewTest : public QObject
{
	Q_OBJECT

private slots:
	void testToggleActionLogDisplay();
};
#endif // WILBURAPPLICATIONVIEWTEST_H

