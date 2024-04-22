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
	void testActionLogContruction()
	{
		WilburApplicationView window;
		ActionLogModel* actionLog = window.getActionLog();
		QVERIFY(actionLog != nullptr);
	}
	void testActionLogDisplayConstruction()
	{
		WilburApplicationView window;
		ActionLogView* actionLogDisplay = window.getActionLogDisplay();
		QVERIFY(actionLogDisplay != nullptr);
	}
	void testInputDirectorConstruction()
	{
		WilburApplicationView window;
		InputDirectorViewModel* inputDirector = window.getInputDirector();
		QVERIFY(inputDirector != nullptr);
	}
	void testMenuBarConstruction()
	{
		WilburApplicationView window;
		MenuBarView* menuBar = window.getMenuBar();
		QVERIFY(menuBar != nullptr);
	}
	void testPrototypeControllerConstruction()
	{
		WilburApplicationView window;
		PrototypeControllerView* robotControl = window.getRobotControl();
		QVERIFY(robotControl != nullptr);
	}
	void testCentralWidget()
	{
		WilburApplicationView window;
		QWidget* centralWidget = window.getCentralWidget();
		QVERIFY(centralWidget != nullptr);
	}

	// test functions
	void testToggleActionLogDisplay()
	{
		WilburApplicationView window;

		QVERIFY(window.actionLogDisplay->isVisible());

		window.toggleActionLogDisplay(true);
		QVERIFY(window.actionLogDisplay->isVisible());

		window.toggleActionLogDisplay(false);
		QVERIFY(!window.actionLogDisplay->isVisible());
	}
};
#endif // WILBURAPPLICATIONVIEWTEST_H

