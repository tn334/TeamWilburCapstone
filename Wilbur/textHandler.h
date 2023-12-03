#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include <QStringList>

class TextHandler
{
public:
	TextHandler();

	void controlManipulated();
	void processSliderChange();

	QStringList getAllText() const;

private:
	QStringList textList;
};

#endif // TEXTHANDLER_H