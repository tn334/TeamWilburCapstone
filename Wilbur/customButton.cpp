// Copyright (C) 2016 The Qt Company Ltd.

#include "customButton.h"

CustomButton::CustomButton(const QString& tooltip,
	const QString& text, const QColor& bgColor,
	QWidget* parent) : QPushButton(parent),
	m_tooltip(tooltip), m_text(text), m_backgroundColor(bgColor)
{

	// set initial properties
	setText(m_text);
	setToolTip(m_tooltip);
	setStyleSheet(QString("background-color:%1").arg(m_backgroundColor.name()));
	/*setStyleSheet("color: white;"
		"background-color: #88CCEE;"
		"border-width: 2px;"
		"border-style: outset;"
		"border-radius: 4px;"
		"font: bold 12px; ");*/
}

//function implementation
QString CustomButton::getToolTip() const
{
	return m_tooltip;
}

QString CustomButton::getText() const
{
	return m_text;
}

QColor CustomButton::getBackgroundColor() const
{
	return m_backgroundColor;
}
