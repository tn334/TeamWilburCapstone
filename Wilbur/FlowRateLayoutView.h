#pragma once
#ifndef FLOWRATELAYOUTVIEW_H
#define FLOWRATELAYOUTVIEW_H

// Header Files
#include "InputDirectorViewModel.h" // includes enum def of buttonType

#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QLabel>

class FlowRateLayoutView : public QWidget
{
	Q_OBJECT
public:
	explicit FlowRateLayoutView(QWidget* parent = nullptr);
	~FlowRateLayoutView();

	QDoubleSpinBox *getSpinBox() const;

	QLabel *getUnitLabel() const;

	void handleValueChanged();

private:
	// create flow rate labels
	QLabel* flowUnitLabel;

	// create value input labels
	QDoubleSpinBox* flowSpinBox;

};

#endif // FLOWRATELAYOUTVIEW_H

