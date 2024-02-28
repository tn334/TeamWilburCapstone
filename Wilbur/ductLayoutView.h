#pragma once

#ifndef DUCTLAYOUTVIEW_H
#define DUCTLAYOUTVIEW_H

//Header Files
#include "ductButtonView.h"
#include "inputDirector.h" // includes enum def of buttonType

#include <QLabel>
#include <QWidget>
#include <QLineEdit>

//Forward Declaration of buttonType
enum buttonType;

class DuctLayoutView : public QWidget
{
	Q_OBJECT

public:
	// constructor
	explicit DuctLayoutView(QWidget* parent = nullptr);

	// destructor
	~DuctLayoutView();

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
	DuctButtonView* buttonOne;
	DuctButtonView* buttonTwo;
	DuctButtonView* buttonThree;

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
	QHBoxLayout* createButtonLayout(const QString& labelText, DuctButtonView** button, QLineEdit** lineEdit, QLabel** unitLabel, buttonType valveType);

};

#endif // DUCTLAYOUTVIEW_H
