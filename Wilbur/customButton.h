#pragma once
// https://doc.qt.io/qt-6/qpushbutton.html

#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <qpushbutton.h>
#include <qcolor.h>
#include <qlabel.h>
#include <QGridLayout>
class CustomButton : public QPushButton
{
	Q_OBJECT
private:

	QString m_tooltip;
	QString m_text;
	QColor m_backgroundColor;

public:
	CustomButton(const QString& tooltip,
		const QString& text, const QColor& bgColor,
		QWidget* parent = nullptr);
	void printLabelLocation();

	QString getToolTip() const;
	QString getText() const;
	QColor getBackgroundColor() const;

	QSize sizeHint() const override;

	//https://doc.qt.io/qt-6/qpushbutton.html#flat-prop

};
#endif // CUSTOMBUTTON_H
