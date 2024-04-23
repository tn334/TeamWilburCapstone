#include "TestWilburApplicationView.h"
//#include "WilburApplicationView.h"

#include <QTest>
#include <QObject>

void TestWilburApplicationView::testActionLogContruction()
{
	WilburApplicationView window;
	ActionLogModel* actionLog = window.getActionLog();
	QVERIFY(actionLog != nullptr);
}
void TestWilburApplicationView::testActionLogDisplayConstruction()
{
	WilburApplicationView window;
	ActionLogView* actionLogDisplay = window.getActionLogDisplay();
	QVERIFY(actionLogDisplay != nullptr);
}
void TestWilburApplicationView::testInputDirectorConstruction()
{
	WilburApplicationView window;
	InputDirectorViewModel* inputDirector = window.getInputDirector();
	QVERIFY(inputDirector != nullptr);
}
void TestWilburApplicationView::testMenuBarConstruction()
{
	WilburApplicationView window;
	MenuBarView* menuBar = window.getMenuBar();
	QVERIFY(menuBar != nullptr);
}
void TestWilburApplicationView::testPrototypeControllerConstruction()
{
	WilburApplicationView window;
	PrototypeControllerView* robotControl = window.getRobotControl();
	QVERIFY(robotControl != nullptr);
}
void TestWilburApplicationView::testCentralWidget()
{
	WilburApplicationView window;
	QWidget* centralWidget = window.getCentralWidget();
	QVERIFY(centralWidget != nullptr);
}

	// test functions
void TestWilburApplicationView::testToggleActionLogDisplay()
{
	WilburApplicationView window;

	QVERIFY(window.actionLogDisplay->isVisible());

	window.toggleActionLogDisplay(true);
	QVERIFY(window.actionLogDisplay->isVisible());

	window.toggleActionLogDisplay(false);
	QVERIFY(!window.actionLogDisplay->isVisible());
}
