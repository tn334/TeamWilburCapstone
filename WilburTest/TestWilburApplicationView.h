#pragma once
#ifndef TESTWILBURAPPLICATIONVIEW_H
#define TESTWILBURAPPLICATIONVIEW_H
#include "WilburApplicationView.h"

#include <QTest>
#include <QObject>

class TestWilburApplicationView : public QObject
{
	Q_OBJECT

private slots:
	// Test object contructors
	void testActionLogContruction();

	void testActionLogDisplayConstruction();

	void testInputDirectorConstruction();

	void testMenuBarConstruction();

	void testPrototypeControllerConstruction();

	void testCentralWidget();

	// Test functions
	void testToggleActionLogDisplay();

};
#endif // WILBURAPPLICATIONVIEWTEST_H

