#pragma once

#ifndef BLUETOOTHCLIENTVIEWMODEL_H
#define BLUETOOTHCLIENTVIEWMODEL_H

#include <QObject>
#include <QDebug>
#include "QtBluetooth/QBluetoothDeviceDiscoveryAgent"
#include "QtBluetooth/QBluetoothSocket" 
#include <QBluetoothUuid>
#include <QBluetoothDeviceInfo>
#include <QLoggingCategory>
#include <QLowEnergyController>
#include <QLowEnergyService>


// declaring logging objects citation:https://doc.qt.io/qt-6.5/qloggingcategory.html
Q_DECLARE_LOGGING_CATEGORY(m_bluetooth)

class BluetoothClient : public QObject
{
    Q_OBJECT

public:
    explicit BluetoothClient(QObject* parent = nullptr); // implementation in cpp file
    ~BluetoothClient();

signals:
    void connected();
    void disconnected();
    void messageReceived(const QString& message);

public slots:

    void send(const QString& message); // implementation in cpp file

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo& info); // implementation in cpp file

    void connectToDevice(); // implementation in cpp file

    void onConnected(); // implementation in cpp file

    void onDisconnected(); // implementation in cpp file

    void getState(QBluetoothSocket::SocketState state);

    void onErrorOccurred(QBluetoothSocket::SocketError error);

    void readSocket(); // implementation in cpp file

private:
    QBluetoothDeviceDiscoveryAgent* m_discoveryAgent;
    QBluetoothDeviceInfo m_deviceInfo;
    QBluetoothAddress device_address;
    QLowEnergyController* m_socket;
    QLowEnergyService* m_service;
};

#endif // BLUETOOTHCLIENTVIEWMODEL_H
