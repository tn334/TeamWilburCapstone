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
	// test object contructors
	void testActionLogContruction();

	void testActionLogDisplayConstruction();

	void testInputDirectorConstruction();

	void testMenuBarConstruction();

	void testPrototypeControllerConstruction();

	void testCentralWidget();


	// test functions
	void testToggleActionLogDisplay();

};
#endif // WILBURAPPLICATIONVIEWTEST_H

