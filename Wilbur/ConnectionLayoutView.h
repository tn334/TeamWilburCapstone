#pragma once

#ifndef CONNECTIONLAYOUTVIEW_H
#define CONNECTIONLAYOUTVIEW_H

#include "ConnectionButtonView.h"
#include "EnumsAndConstants.h"

#include <QLabel>
#include <QWidget>
//#include "BluetoothClientViewModel.h"

class ConnectionLayoutView : public QWidget
{
	Q_OBJECT

public:
	explicit ConnectionLayoutView(QWidget* parent = nullptr);
	~ConnectionLayoutView();

	// Declare Objects
	ConnectionButtonView* connectionButton;

	// Functions
	void callExecuteControl(buttonType button, int newValue);

	//void toggleBluetoothConnection(bool isConnected);

signals:
	void connectionButtonClicked(buttonType button, int newValue);

private:
	
	QLabel* connectionLabel;
	QGridLayout* layout;

};

#endif // CONNECTIONLAYOUTVIEW_H