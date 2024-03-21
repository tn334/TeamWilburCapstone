#pragma once
#ifndef ACTIONLOGVIEW_H
#define ACTIONLOGVIEW_H

// Header Files
#include "ActionLogModel.h" // includes QFile

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QPlainTextEdit>
class ActionLogView : public QWidget
{
	Q_OBJECT
public:
	explicit ActionLogView(ActionLogModel* actionLogModel,QWidget* parent = nullptr);

signals:

public slots:

private:
	QVBoxLayout* mainLayout;
	QPlainTextEdit* logTextEdit;
	QFile logFile;
	QLabel* actionLabel;
};

#endif // ACTIONLOGVIEW_H

