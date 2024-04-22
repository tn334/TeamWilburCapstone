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

	// functions used in testing
	QScrollArea* getScrollArea() const { return scrollArea; };
	QLabel* getTitleLabel() const { return titleLabel; };
	QLabel* getActionLabel() const { return actionLabel; };
	QGridLayout* getMainLayout() const { return mainLayout; };

signals:

public slots:

private:
	QScrollArea* scrollArea;
	QFrame* frame;
	QVBoxLayout* frameLayout;
	QGridLayout* mainLayout;
	QLabel* titleLabel;
	QLabel* actionLabel;
};

#endif // ACTIONLOGVIEW_H

