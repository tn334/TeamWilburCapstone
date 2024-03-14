#pragma once

#ifndef BLUETOOTHLAYOUTVIEW_H
#define BLUETOOTHLAYOUTVIEW_H

#include "BluetoothButtonView.h"
#include "EnumsAndConstants.h"

#include <QLabel>
#include <QWidget>
//#include "BluetoothClientViewModel.h"

class BluetoothLayoutView : public QWidget
{
	Q_OBJECT

public:
	explicit BluetoothLayoutView(QWidget* parent = nullptr);
	~BluetoothLayoutView();

	// Declare Objects
	BluetoothButtonView* bluetoothButton;

	// Functions
	void callExecuteControl(buttonType button, int newValue);

	//void toggleBluetoothConnection(bool isConnected);

signals:
	void bluetoothButtonClicked(buttonType button, int newValue);

private:
	
	QLabel* bluetoothLabel;
	QGridLayout* layout;

};

#endif // BLUETOOTHLAYOUTVIEW_H