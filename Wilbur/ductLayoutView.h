#pragma once

#ifndef DUCTLAYOUTVIEW_H
#define DUCTLAYOUTVIEW_H

//Header Files
#include "DuctButtonView.h"
#include "FlowRateLayoutView.h"
#include "InputDirectorViewModel.h" // includes enum def of buttonType

#include <QDoubleSpinBox>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>

class DuctLayoutView : public QWidget
{
	Q_OBJECT

public:
	// constructor
	explicit DuctLayoutView(QWidget* parent = nullptr);

	// destructor
	~DuctLayoutView();

	void callExecuteControl(buttonType button, int newValue);
	//void callExecuteFlowRateControl(buttonType button, double newValue);

signals:
	void ductButtonClicked(buttonType button, int newValue);
	//void ductFlowRateChanged(buttonType button, double newValue);

private:
	// create button label variables
	QLabel* buttonLabelOne;
	QLabel* buttonLabelTwo;
	QLabel* buttonLabelThree;

	// create duct button variables
	DuctButtonView* buttonOne;
	DuctButtonView* buttonTwo;
	DuctButtonView* buttonThree;

	// create value input box
	FlowRateLayoutView* flowRateOne;
	FlowRateLayoutView* flowRateTwo;
	FlowRateLayoutView* flowRateThree;

	// create layout variable
	QHBoxLayout* layoutButtonOne;
	QHBoxLayout* layoutButtonTwo;
	QHBoxLayout* layoutButtonThree;
	QVBoxLayout* verticalDuctLayout;
	QHBoxLayout* buttonLayout;

	// functions
	QHBoxLayout* createButtonLayout(const QString& labelText, DuctButtonView** button, FlowRateLayoutView** flowLayout, buttonType valveType);

};

#endif // DUCTLAYOUTVIEW_H
