#pragma once
// https://doc.qt.io/qt-6/qpushbutton.html

#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <qpushbutton.h>
#include <qcolor.h>
class CustomButton : public QPushButton
{
	Q_OBJECT
private:
	QString m_label;
	QString m_tooltip;
	QString m_text;
	QColor m_backgroundColor;

public:
	CustomButton(const QString& label, const QString& tooltip,
		const QString& text, const QColor& bgColor,
		QWidget* parent = nullptr);

	QString getLabel() const;
	QString getToolTip() const;
	QString getText() const;
	QColor getBackgroundColor() const;

	//https://doc.qt.io/qt-6/qpushbutton.html#flat-prop
		// painting the button background

	
//protected:
	//virtual void keyPressEvent(QFocusEvent* e);
};

#endif // CUSTOMBUTTON_H
