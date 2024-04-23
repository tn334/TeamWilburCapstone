#include "WilburTest.h"
#include <QtWidgets/QApplication>
#include <QTest>
#include "TestWilburApplicationView.h"
#include "TestActionLogView.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Run your tests
    int testFrontEndResult = 0;
    TestWilburApplicationView testAppBuild;
    testFrontEndResult |= QTest::qExec(&testAppBuild, argc, argv);

    // Create an instance of TestActionLogView and run its tests
    TestActionLogView testActionLog;
    testFrontEndResult |= QTest::qExec(&testActionLog, argc, argv);

    // Check if any tests failed
    if (testFrontEndResult != 0) {
        qDebug() << "One or more tests failed!";
        return testFrontEndResult;
    }

    qDebug() << "All tests passed!";
    return 0;
}

// Comment out main function and uncomment one of the below test calls to run tests for one file only
//QTEST_MAIN(TestWilburApplicationView)
//QTEST_MAIN(TestActionLogView)