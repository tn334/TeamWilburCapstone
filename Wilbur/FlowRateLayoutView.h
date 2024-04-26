#pragma once
#ifndef FLOWRATELAYOUTVIEW_H
#define FLOWRATELAYOUTVIEW_H

// Header Files
#include "ConnectionButtonView.h"
#include "InputDirectorViewModel.h" // includes enum def of buttonType

#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

class FlowRateLayoutView : public QWidget
{
	Q_OBJECT
public:
	explicit FlowRateLayoutView(ConnectionButtonView* connectionButton, QWidget* parent = nullptr);
	~FlowRateLayoutView();

	QDoubleSpinBox *getSpinBox() const;

	QLabel *getUnitLabel() const;

	void handleValueChanged();

private:
	// create connection object
	ConnectionButtonView* connectButton;

	// create flow rate labels
	QLabel* flowUnitLabel;

	// create value input labels
	QDoubleSpinBox* flowSpinBox;

	double spinBoxValue = 0;
};

#endif // FLOWRATELAYOUTVIEW_H

