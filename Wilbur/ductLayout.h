#pragma once

#include "ductButton.h"

#include <QLabel>
#include <QWidget>

class DuctLayout : public QWidget
{
	Q_OBJECT

public:
	explicit DuctLayout(QWidget* parent = nullptr);
	~DuctLayout();

private:
	QLabel* buttonLabelOne;
	QLabel* buttonLabelTwo;
	QLabel* buttonLabelThree;
	DuctButton* buttonOne;
	DuctButton* buttonTwo;
	DuctButton* buttonThree;


};

