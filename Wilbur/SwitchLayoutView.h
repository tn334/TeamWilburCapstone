#pragma once

#ifndef SWITCHLAYOUTVIEW_H
#define SWITCHLAYOUTVIEW_H

//Header Files
#include "ConnectionButtonView.h"
#include "SwitchButtonView.h"
#include "FlowRateLayoutView.h"
#include "InputDirectorViewModel.h" // includes enum def of buttonType

#include <QDoubleSpinBox>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QMessageBox>

class SwitchLayoutView : public QWidget
{
	Q_OBJECT

public:
	// constructor
	explicit SwitchLayoutView(ConnectionButtonView* connectionButton, QWidget* parent = nullptr);

	// destructor
	~SwitchLayoutView();

	void callExecuteControl(buttonType button, int newValue);
	void callExecuteFlowRateControl(buttonType button, double newValue);

signals:
	void switchButtonClicked(buttonType button, int newValue);
	void switchFlowRateChanged(buttonType button, double newValue);

private:
	// create connectionButton object
	ConnectionButtonView* connectButton;
	// create title variable
	QLabel* switchLabel;
	QLabel* viscosityLabel;
	QLabel* buttonLabel;

	// create button label variables
	QLabel* buttonLabelOne;
	QLabel* buttonLabelTwo;
	QLabel* buttonLabelThree;

	// create Switch button variables
	SwitchButtonView* buttonOne;
	SwitchButtonView* buttonTwo;
	SwitchButtonView* buttonThree;

	// create value input box
	FlowRateLayoutView* flowRateOne;
	FlowRateLayoutView* flowRateTwo;
	FlowRateLayoutView* flowRateThree;
	double previousValue = 0;

	// create layout variable
	QHBoxLayout* horizontalLabelLayout;
	QGridLayout* labelLayout;
	QHBoxLayout* layoutButtonOne;
	QHBoxLayout* layoutButtonTwo;
	QHBoxLayout* layoutButtonThree;
	QVBoxLayout* verticalSwitchLayout;
	QHBoxLayout* buttonLayout;

	// functions
	QHBoxLayout* createButtonLayout(const QString& labelText, SwitchButtonView** button, FlowRateLayoutView** flowLayout, buttonType valveType);

};

#endif // SWITCHLAYOUTVIEW_H
