#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef BUTTON_H
#define BUTTON_H

#include <qtoolbutton.h>

class Button : public QToolButton
{
	Q_OBJECT

public:
	explicit Button(QString text, QWidget* parent = nullptr);

	QSize sizeHint() const override;

	//Function to get current state
	bool getState() const;

	//function to set current state
	void setState(bool newState);

signals:
		//void clicked(bool checked, const QString& objectName, int valueChanged);

private slots:
	void buttonStateChange();
private:
	//member variable to store state
	bool currentState;
};
#endif // BUTTON_H