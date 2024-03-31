#pragma once
#ifndef ACTIONLOGVIEW_H
#define ACTIONLOGVIEW_H

// Header Files
#include "ActionLogModel.h"

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QTimer>
#include <QWidget>

class ActionLogView : public QWidget
{
	Q_OBJECT
public:
	explicit ActionLogView(ActionLogModel* actionLogModel,QWidget* parent = nullptr);

signals:

public slots:

private:
	QGridLayout* mainLayout;
	QLabel* titleLabel;
	QLabel* actionLabel;
};

#endif // ACTIONLOGVIEW_H

