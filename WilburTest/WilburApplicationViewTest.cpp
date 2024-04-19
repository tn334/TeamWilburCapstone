#include "WilburApplicationViewTest.h"
#include <QTest>

void WilburApplicationViewTest::testToggleActionLogDisplay()
{
    WilburApplicationView window;
    
    QVERIFY(window.actionLogDisplay->isVisible());

    window.toggleActionLogDisplay(true);
    QVERIFY(window.actionLogDisplay->isVisible());

    window.toggleActionLogDisplay(false);
    QVERIFY(!window.actionLogDisplay->isVisible());
}

//QTEST_MAIN(WilburApplicationViewTest)
