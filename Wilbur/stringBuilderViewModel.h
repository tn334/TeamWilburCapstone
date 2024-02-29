#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef STRINGBUILDERVIEWMODEL_H
#define STRINGBUILDERVIEWMODEL_H

// Header files
#include <QStringList>

class StringBuilderViewModel
{
public:
	// Constructor
	StringBuilderViewModel();

	// Change in front end
	void controlManipulated(std::string objectName, int newValue);

	// Gather all session texts
	QStringList getAllText() const;

	// Get the text of the most recent action
	QString getActionText() const;
private:
	// List that holds all texts
	QStringList textList;
	QString objectText;
};

#endif // STRINGBUILDERVIEWMODEL_H