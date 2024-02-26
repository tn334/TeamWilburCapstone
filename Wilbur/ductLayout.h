#pragma once

#ifndef DUCTLAYOUT_H
#define DUCTLAYOUT_H

//Header Files
#include "ductButton.h"
#include "inputDirector.h" // includes enum def of buttonType

#include <QLabel>
#include <QWidget>
#include <QLineEdit>

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
	QLabel* flowRateUnitOne;
	QLabel* flowRateUnitTwo;
	QLabel* flowRateUnitThree;

	// create duct button variables
	DuctButton* buttonOne;
	DuctButton* buttonTwo;
	DuctButton* buttonThree;

	// create value input labels
	QLineEdit* viscValueOne;
	QLineEdit* viscValueTwo;
	QLineEdit* viscValueThree;

	// create layout variable
	QHBoxLayout* layoutButtonOne;
	QHBoxLayout* layoutButtonTwo;
	QHBoxLayout* layoutButtonThree;
	QVBoxLayout* verticalDuctLayout;
	QHBoxLayout* buttonLayout;

	// functions
	QHBoxLayout* createButtonLayout(const QString& labelText, DuctButton** button, QLineEdit** lineEdit, QLabel** unitLabel, buttonType valveType);

};

#endif // DUCTLAYOUT_H
