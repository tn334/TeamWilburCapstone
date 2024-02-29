// Copyright (C) 2016 The Qt Company Ltd.

// Header Files
#include "BaseButtonView.h"

// Custom Button Constructor
BaseButtonView::BaseButtonView(const QString& tooltip,
	const QString& text, const QColor& bgColor,
	QWidget* parent) : QPushButton(parent),
	m_tooltip(tooltip), m_text(text), m_backgroundColor(bgColor)
{
	// set initial properties
	setText(m_text);
	setToolTip(m_tooltip);
	setStyleSheet(QString("background-color:%1").arg(m_backgroundColor.name()));
}

// Function that returns width and heigth
QSize BaseButtonView::sizeHint() const
{
	// Return width (1st param) and height (2nd param)
	return QSize(80, 30);
}

// Function that displays tool tips
QString BaseButtonView::getToolTip() const
{
	// Return button tool tip
	return m_tooltip;
}

// Function that gets label text
QString BaseButtonView::getText() const
{
	// Return button label text
	return m_text;
}

// Function that retrieves current background color
QColor BaseButtonView::getBackgroundColor() const
{
	// Return current bg color
	return m_backgroundColor;
}
