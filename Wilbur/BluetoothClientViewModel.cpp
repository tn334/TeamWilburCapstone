// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

//https://doc.qt.io/qt-6/qtbluetooth-le-overview.html

// Coded in tandem with AI
#include "BluetoothClientViewModel.h"

// Declaring Logging object cite: https://doc.qt.io/qt-6.5/qloggingcategory.html
Q_LOGGING_CATEGORY(m_bluetooth, "bluetooth")

BluetoothClient::BluetoothClient(QObject* parent)
    : QObject(parent), m_socket(nullptr), 
    m_service(nullptr)
{
    // Initialize Bluetooth device discovery agent
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
        this, &BluetoothClient::deviceDiscovered);

    // Start device discovery
    m_discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
};

BluetoothClient::~BluetoothClient()
{
    // Clean up resources (e.g., delete m_socket, disconnect signals, etc.)
    if (m_socket) {
        m_socket->disconnectFromDevice();
        m_socket->deleteLater();
    }
    delete m_service;
}

void BluetoothClient::send(const QString& message)
{
    //qCDebug(m_bluetooth) << "Attempting to send" << message ;
    if (m_socket && m_socket->state() == QLowEnergyController::ConnectedState) {
        QByteArray data = message.toUtf8();
        //m_socket->writeCharacteristic(data);
        // Write data to the characteristic
        //controller->writeCharacteristic(characteristic, data);
        //characteristic is assumed to be your QLowEnergyCharacteristic object representing the characteristic you want to write to.
    }
}

void BluetoothClient::deviceDiscovered(const QBluetoothDeviceInfo& device)
{
    if (device.name() == "Nipple Robot") {
        qCDebug(m_bluetooth) << "Found device:" << device.name() << device.address();
        m_deviceInfo = device;
        device_address = device.address();
        m_discoveryAgent->stop();
        connectToDevice();
    }
}

void BluetoothClient::connectToDevice()
{
    if (m_deviceInfo.isValid()) {
        // Create a Bluetooth socket
        qCDebug(m_bluetooth) << "Create socket";
        //m_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
         
        //FIX
        /*m_socket = new QLowEnergyController:CSALCAT1(this);*/
        m_socket = QLowEnergyController::createCentral(m_deviceInfo, this);
        connect(m_socket, &QLowEnergyController::connected, this, &BluetoothClient::onConnected);
        connect(m_socket, &QLowEnergyController::disconnected, this, &BluetoothClient::onDisconnected);
        //connect(m_socket, &QLowEnergyController::error, this, &BluetoothClient::onErrorOccurred);
        
        // Connect to the discovered device
            // Create Service UUID
        //const QBluetoothUuid serviceUuid("9A48ECBA-2E92-082F-C079-9E75AAE428B1");
        const QBluetoothUuid serviceUuid("0E9322C4-7513-40AB-AE21-E423DFC08BB7");
            // Connect to service UUID
        m_socket->connectToDevice();
        //qCDebug(m_bluetooth) << "Connected to device Service UUID:" << m_deviceInfo.name();
        
        /*bool connected = (m_socket->state() == QAbstractSocket::ConnectedState);
        if (connected)
        {
            qCDebug(m_bluetooth) << "Socket created and connected to device:" << m_deviceInfo.name();
        }*/
    }
}

void BluetoothClient::getState(QLowEnergyController::ControllerState state)
{
    //resource for ControllerState values and desscription: https://doc.qt.io/qt-6/qlowenergycontroller.html#ControllerState-enum
    switch (state)
    {
    case QLowEnergyController::UnconnectedState: // value 0
        qCDebug(m_bluetooth) << "The controller is not connected to a remote device.";
        break;

    case QLowEnergyController::ConnectingState: // value 1
        qCDebug(m_bluetooth) << "The controller is attempting to connect to a remote device.";
        break;

    case QLowEnergyController::ConnectedState: // value 2
        qCDebug(m_bluetooth) << "The controller is connected to a remote device.";
        break;

    case QLowEnergyController::DiscoveringState: // value 3
        qCDebug(m_bluetooth) << "The controller is retrieving the list of services offered by the remote device.";
        break;

    case QLowEnergyController::DiscoveredState: // value 4
        qCDebug(m_bluetooth) << "The controller has discovered all services offered by the remote device.";
        break;

    case QLowEnergyController::ClosingState: //value 5
        qCDebug(m_bluetooth) << "The controller is about to be disconnected from the remote device.";
        break;

    case QLowEnergyController::AdvertisingState: // value 6
        qCDebug(m_bluetooth) << "The controller is currently advertising data.";
        break;
    default:
        qCDebug(m_bluetooth) << "Unknown Controller State";
        break;
    }

}

void BluetoothClient::onErrorOccurred(QLowEnergyController::Error error)
{
    // resource https://doc.qt.io/qt-6/qlowenergycontroller.html#Error-enum
    // Error debug messages 
    switch (error)
    {
    case QLowEnergyController::NoError: // error code value 0
        qCDebug(m_bluetooth) << "No error has occurred. Used for testing";
        break;
    case QLowEnergyController::UnknownError: // error code value 1
        qCDebug(m_bluetooth) << "An unknown error has occurred.";
        break;
    case QLowEnergyController::UnknownRemoteDeviceError: // error code value 2
        qCDebug(m_bluetooth) << "The remote Bluetooth Low Energy device with the address passed to the constructor of this class cannot be found.";
        break;
    case QLowEnergyController::NetworkError: // error code value 3
        qCDebug(m_bluetooth) << "The attempt to read from or write to the remote device failed.";
        break;

    case QLowEnergyController::InvalidBluetoothAdapterError: // error code value 4
        qCDebug(m_bluetooth) << "The local Bluetooth device with the address passed to the constructor of this class cannot be found or there is no local Bluetooth device.";
        break;
    case QLowEnergyController::ConnectionError: // error code value 5
        qCDebug(m_bluetooth) << "The attempt to connect to the remote device failed.";
        break;
    case QLowEnergyController::AdvertisingError: // error code value 6
        qCDebug(m_bluetooth) << "The attempt to start advertising failed.";
        break;
    case QLowEnergyController::RemoteHostClosedError: // error code value 7
        qCDebug(m_bluetooth) << "The remote device closed the connection.";
        break;
    case QLowEnergyController::AuthorizationError: // error code value 8
        qCDebug(m_bluetooth) << "The local Bluetooth device closed the connection due to insufficient authorization.";
        break;
    case QLowEnergyController::MissingPermissionsError: // error code value 9
        qCDebug(m_bluetooth) << "The operating system requests permissions which were not granted by the user.";
        break;
    case QLowEnergyController::RssiReadError: // error code value 10
        qCDebug(m_bluetooth) << "An attempt to read RSSI (received signal strength indicator) of a remote device finished with error.";
        break;
    default:
        qCDebug(m_bluetooth) << "Unknown/unHandled error";
        break;
    }
}

void BluetoothClient::onConnected()
{
    qCDebug(m_bluetooth) << "Connected to device Service UUID:" << m_deviceInfo.name();
    // Create characteristic UUID
    const QBluetoothUuid charUuid("E05B7FCC-1920-465C-8BF9-AFB2BF45C25B");
    // Connect to service UUID
    m_socket->connectToDevice();
    qCDebug(m_bluetooth) << "Connected to device Characteristic UUID:" << m_deviceInfo.name()<< m_deviceInfo.address();
    // emit signal for connected
    emit connected();
}

void BluetoothClient::onDisconnected()
{
    qCDebug(m_bluetooth) << "Disconnected from device:" << m_deviceInfo.name() << m_deviceInfo.address();
    emit disconnected();
}

void BluetoothClient::readSocket()
{
  //todo not needed for tech demo
}
