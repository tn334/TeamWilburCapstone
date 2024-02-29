#pragma once
// https://doc.qt.io/qt-6/qpushbutton.html

#ifndef BASEBUTTONVIEW_H
#define BASEBUTTONVIEW_H

#include <QPushButton>
#include <QColor>
#include <QLabel>
#include <QGridLayout>

class BaseButtonView : public QPushButton
{
	Q_OBJECT

private:

	QString m_tooltip;
	QString m_text;
	QColor m_backgroundColor;

public:
	BaseButtonView(const QString& tooltip,
		const QString& text, const QColor& bgColor,
		QWidget* parent = nullptr);

	QString getToolTip() const;
	QString getText() const;
	QColor getBackgroundColor() const;

	QSize sizeHint() const override;

	//https://doc.qt.io/qt-6/qpushbutton.html#flat-prop

};

#endif // BASEBUTTONVIEW_H