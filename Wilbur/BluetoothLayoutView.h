#pragma once

#ifndef BLUETOOTHLAYOUTVIEW_H
#define BLUETOOTHLAYOUTVIEW_H

#include "BluetoothButtonView.h"
#include "InputDirectorViewModel.h" // includes enum def of buttonType
#include <QLabel>
#include <QWidget>

//Forward Declaration of buttonType
enum buttonType;

class BluetoothLayoutView : public QWidget
{
	Q_OBJECT

public:
	explicit BluetoothLayoutView(QWidget* parent = nullptr);
	~BluetoothLayoutView();

	void callExecuteControl(buttonType button, int newValue);

	BluetoothButtonView* bluetoothButton;

signals:
	void bluetoothButtonClicked(buttonType button, int newValue);

private:
	
	QLabel* bluetoothLabel;
	QGridLayout* layout;


};

#endif // BLUETOOTHLAYOUTVIEW_H