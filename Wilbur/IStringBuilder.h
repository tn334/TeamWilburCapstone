#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef ISTRINGBUILDER_H
#define ISTRINGBUILDER_H

// Header files
#include <QStringList>

class IStringBuilder
{
public:
	// Change in front end
	virtual void buildStringAndAppend(std::string objectName, int newValue) = 0;

};

#endif // ISTRINGBUILDER_H