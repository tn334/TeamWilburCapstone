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
    //{
    //     Create an ActionLogModel (if needed)
    //    ActionLogModel actionLogModel;

    //     Create an ActionLogView widget
    //    ActionLogView actionLogView(&actionLogModel);

    //     Verify that the widget and its components are constructed correctly
    //    QVERIFY(actionLogView.getMainLayout() != nullptr);
    //    QVERIFY(actionLogView.getTitleLabel() != nullptr);
    //    QVERIFY(actionLogView.getActionLabel() != nullptr);
    //}

    void testActionLogUpdate();
    //{
    //    // Create an ActionLogModel
    //    ActionLogModel actionLogModel;

    //    // Create an ActionLogView widget
    //    ActionLogView actionLogView(&actionLogModel);

    //    // Add actions to the action log model
    //    actionLogModel.addActionToLog("Action 1");
    //    actionLogModel.addActionToLog("Action 2");

    //    // Verify that the action label updates with the new actions
    //    QCOMPARE(actionLogView.getActionLabel()->text(), QString("Action 1\nAction 2"));
    //}

    void testScrollToBottom();
    //{
    //    // Create an ActionLogModel
    //    ActionLogModel actionLogModel;

    //    // Create an ActionLogView widget
    //    ActionLogView actionLogView(&actionLogModel);

    //    // Add actions to the action log model
    //    for (int i = 0; i < 20; ++i) {
    //        actionLogModel.addActionToLog("Action " + QString::number(i));
    //    }

    //    // Simulate the addition of a new action
    //    actionLogModel.addActionToLog("New Action");

    //    // Verify that the scroll area scrolls to the bottom
    //    QVERIFY(actionLogView.getScrollArea()->verticalScrollBar()->value() == actionLogView.getScrollArea()->verticalScrollBar()->maximum());
    //}
};

#endif // !TESTACTIONLOGVIEW_H
