#include "TestInputDirector.h"

void TestInputDirector::testConstructor()
{
    WilburApplicationView window;
    InputDirectorViewModel* inputDirector = window.getInputDirector();

    QVERIFY(inputDirector->simulatorMode);

    QVERIFY(inputDirector->simOutput != nullptr);

    QVERIFY(typeid(inputDirector->simObject) == typeid(SimulatorModel));

}

void TestInputDirector::testSimFunctions()
{
    WilburApplicationView window;
    InputDirectorViewModel* inputDirector = window.getInputDirector();

    QVERIFY(inputDirector->handleInput(VALVE1, OPEN, "Switch One"));

    QVERIFY(inputDirector->handleInput(VALVE1, CLOSED, "Switch One"));

    QVERIFY(inputDirector->handleInput(VALVE2, OPEN, "Switch Two"));

    QVERIFY(inputDirector->handleInput(VALVE2, CLOSED, "Switch Two"));

    QVERIFY(inputDirector->handleInput(VALVE3, OPEN, "Switch Three"));

    QVERIFY(inputDirector->handleInput(VALVE3, CLOSED, "Switch Three"));

    QVERIFY(inputDirector->handleInput(PUMP, LOW, "Pump"));

    QVERIFY(inputDirector->handleInput(PUMP, MED, "Pump"));

    QVERIFY(inputDirector->handleInput(PUMP, HIGH, "Pump"));

    QVERIFY(inputDirector->handleInput(PUMP, OFF, "Pump"));
}