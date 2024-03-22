// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// Include header files
#include "WilburApplicationView.h"
#include "BluetoothClientViewModel.h"

// https://doc.qt.io/qt-6/qgridlayout.html

//CONFIG += console

// Main Wilbur Application Primer
int main(int argc, char *argv[])
{
    
    //Simulator vs Prototype Mode
    int simMode = 1;
    // set up and show widgets
    QApplication app(argc, argv);

    if (argc > 1)
    {
        // read first char of second command line arg, 'cast' to int
        simMode = argv[1][0] - '0';
    }

    // Create an instance of BluetoothClient
    BluetoothClient bluetoothClient;

    // Connect to signals to receive notifications
    QObject::connect(&bluetoothClient, &BluetoothClient::connected, [&]() {
        qDebug() << "Connected to Bluetooth device.";

        // Once connected, send a message to the peripheral
        bluetoothClient.send("Hello, Arduino!");
        });

    QObject::connect(&bluetoothClient, &BluetoothClient::disconnected, [&]() {
        qDebug() << "Disconnected from Bluetooth device.";
        });

    QObject::connect(&bluetoothClient, &BluetoothClient::messageReceived, [&](const QString& message) {
        qDebug() << "Received message:" << message;
        });

    // Enabling all QtBluetooth Logging
    QLoggingCategory::setFilterRules("bluetooth.debug=true"); // enables debug for bluetooth category
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true")); // enables logging for 
                                                                              //broader category of all 
                                                                              // things starting with 'qt.bluetooth'

    // Wilbur widgets - initialize object
    WilburApplicationView wilbur(nullptr, simMode);

	// Show Wilbur main window
    wilbur.show();

    // call the application
    return app.exec();
}
