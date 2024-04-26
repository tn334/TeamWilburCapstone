#pragma once

#ifndef CONNECTIONLAYOUTVIEW_H
#define CONNECTIONLAYOUTVIEW_H

#include "ConnectionButtonView.h"
#include "EnumsAndConstants.h"

#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QEvent>

//#include "BluetoothClientViewModel.h"

class ConnectionLayoutView : public QWidget
{
	Q_OBJECT

public:
	explicit ConnectionLayoutView(ConnectionButtonView* connectionButton, QWidget* parent = nullptr);
	~ConnectionLayoutView();

	// Declare Objects
	ConnectionButtonView* connectButton;

	// Functions
	void callExecuteControl(buttonType button, int newValue);

	//void toggleBluetoothConnection(bool isConnected);

private:
	
	QLabel* connectionLabel;
	QGridLayout* layout;

signals:
	void connectionButtonClicked(buttonType button, int newValue);
};

#endif // CONNECTIONLAYOUTVIEW_H