// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "BluetoothClientViewModel.h"

// Declaring Logging object cite: https://doc.qt.io/qt-6.5/qloggingcategory.html
Q_LOGGING_CATEGORY(m_bluetooth, "bluetooth")

BluetoothClient::BluetoothClient(QObject* parent)
    : QObject(parent), m_socket(nullptr)
{
    // Initialize Bluetooth device discovery agent
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
        this, &BluetoothClient::deviceDiscovered);

    // Start device discovery
    m_discoveryAgent->start();
};

BluetoothClient::~BluetoothClient()
{
    // Clean up resources (e.g., delete m_socket, disconnect signals, etc.)
    if (m_socket) {
        m_socket->disconnectFromService();
        m_socket->deleteLater();
    }
}

void BluetoothClient::send(const QString& message)
{
    if (m_socket && m_socket->isOpen()) {
        QByteArray data = message.toUtf8();
        m_socket->write(data);
    }
}

void BluetoothClient::deviceDiscovered(const QBluetoothDeviceInfo& info)
{
    if (info.name() == "Nipple Robot") {
        qCDebug(m_bluetooth) << "Found device:" << info.name() << info.address();
        m_deviceInfo = info;
        connectToDevice();
    }
}

void BluetoothClient::connectToDevice()
{
    if (m_deviceInfo.isValid()) {
        // Create a Bluetooth socket
        qCDebug(m_bluetooth) << "Create socket";
        m_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
        connect(m_socket, &QBluetoothSocket::connected, this, &BluetoothClient::onConnected);
        connect(m_socket, &QBluetoothSocket::disconnected, this, &BluetoothClient::onDisconnected);

        connect(m_socket, &QBluetoothSocket::readyRead, this, &BluetoothClient::readSocket);
        connect(m_socket, &QBluetoothSocket::errorOccurred, this, &BluetoothClient::onErrorOccurred);
        
        // Connect to the discovered device
        const QBluetoothUuid rfcommUuid("{2D2F88C4-F244-5A80-21F1-EE0224E80658}");
        m_socket->connectToService(m_deviceInfo.address(), rfcommUuid);
        qCDebug(m_bluetooth) << "Socket created and connected to device:" << m_deviceInfo.name();
    }
}

void BluetoothClient::onErrorOccurred(QBluetoothSocket::SocketError error)
{
    // Error debug messages 
    // resource: https://doc.qt.io/qt-6/qbluetoothsocket.html#SocketError-enum
    switch (error)
    {
    case QBluetoothSocket::SocketError::RemoteHostClosedError:
        qCDebug(m_bluetooth) << "Remote host closed the connection.";
        break;
    case QBluetoothSocket::SocketError::HostNotFoundError:
        qCDebug(m_bluetooth) << "Host not found.";
        break;
    default:
        qCDebug(m_bluetooth) << "Unknown error occured.";
    }
}

void BluetoothClient::onConnected()
{
    qCDebug(m_bluetooth) << "Connected to device:" << m_deviceInfo.name() << m_deviceInfo.address();
    emit connected();
}

void BluetoothClient::onDisconnected()
{
    qCDebug(m_bluetooth) << "Disconnected from device:" << m_deviceInfo.name() << m_deviceInfo.address();
    emit disconnected();
}

void BluetoothClient::readSocket()
{
    if (m_socket && m_socket->canReadLine()) {
        QString message = QString::fromUtf8(m_socket->readLine()).trimmed();
        qCDebug(m_bluetooth) << "Received message:" << message;
        emit messageReceived(message);
    }
}
