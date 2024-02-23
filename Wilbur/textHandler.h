#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

// Header files
#include <QStringList>

class TextHandler
{
public:
	// Constructor
	TextHandler();

	// Change in front end
	void controlManipulated(std::string objectName, bool currentState, int valueChanged);

	// Gather all session texts
	QStringList getAllText() const;

	QString getActionText() const;
private:
	// List that holds all texts
	QStringList textList;
	QString objectText;
};

#endif // TEXTHANDLER_H