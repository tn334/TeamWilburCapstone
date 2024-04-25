#include "TestInputDirector.h"

void TestInputDirector::testConstructor()
{

    InputDirectorViewModel simDirector = new InputDirectorViewModel();



}

void TestInputDirector::testSimFunctions()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}