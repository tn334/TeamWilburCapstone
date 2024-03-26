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
Q_DECLARE_LOGGING_CATEGORY(m_controller_error)
Q_DECLARE_LOGGING_CATEGORY(m_controller_state)

class BluetoothClient : public QObject
{
    Q_OBJECT

public:
    explicit BluetoothClient(QObject* parent = nullptr); 
    ~BluetoothClient();

signals:
    void connected();
    void disconnected();
    void messageReceived(const QString& message);

public slots:

    void send(const QString& message); 

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo& info);

    void connectToDevice();

    void onConnected(); 

    void onDisconnected();

    void getState(QLowEnergyController::ControllerState state);

    void onErrorOccurred(QLowEnergyController::Error error);

    void readSocket(); 

    void onServiceDiscovered(const QBluetoothUuid& newService);

    void onServiceStateChanged(QLowEnergyService::ServiceState newState);

    void serviceScanDone();

//Q_SIGNALS:
//    void serviceChanged();

private:
    QLowEnergyCharacteristic m_characteristic; // Define the characteristic

    QBluetoothDeviceDiscoveryAgent* m_discoveryAgent;
    QBluetoothDeviceInfo m_deviceInfo;
    QBluetoothAddress device_address;
    QLowEnergyController* m_controller;
    // bluetooth service variables
    QLowEnergyService* m_service;
    //QLowEnergyService *m_service = nullptr;
};

#endif // BLUETOOTHCLIENTVIEWMODEL_H
