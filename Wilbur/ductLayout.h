#pragma once

#ifndef DUCTLAYOUT_H
#define DUCTLAYOUT_H

//Header Files
#include "ductButton.h"
#include "inputDirector.h" // includes enum def

#include <QLabel>
#include <QWidget>

//Forward Declaration of buttonType
enum buttonType;

class DuctLayout : public QWidget
{
	Q_OBJECT

public:
	// constructor
	explicit DuctLayout(QWidget* parent = nullptr);

	// destructor
	~DuctLayout();

	void callExecuteControl(buttonType button, int newValue);

signals:
	void ductButtonClicked(buttonType button, int newValue);

private:
	// create button label variables
	QLabel* buttonLabelOne;
	QLabel* buttonLabelTwo;
	QLabel* buttonLabelThree;

	// create duct button variables
	DuctButton* buttonOne;
	DuctButton* buttonTwo;
	DuctButton* buttonThree;

	// create layout variable
	QGridLayout* buttonLayout;

};

#endif // DUCTLAYOUT_H
