#pragma once
#ifndef TESTACTIONLOGVIEW_H
#define TESTACTIONLOGVIEW_H

#include <QTest>
#include <QObject>

#include "ActionLogView.h"

class TestActionLogView : public QObject {
    Q_OBJECT

private slots:
    void testWidgetConstruction();

    void testActionLogUpdate(); // Test Fails
    
    void testScrollToBottom(); // Test Fails

};

#endif // !TESTACTIONLOGVIEW_H
