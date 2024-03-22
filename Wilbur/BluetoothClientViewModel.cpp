//// Copyright (C) 2016 The Qt Company Ltd.
//// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
//
////https://doc.qt.io/qt-6/qtbluetooth-le-overview.html
//
//// Coded in tandem with AI
//#include "BluetoothClientViewModel.h"
//
//// Declaring Logging object cite: https://doc.qt.io/qt-6.5/qloggingcategory.html
//Q_LOGGING_CATEGORY(m_bluetooth, "bluetooth")
//
//BluetoothClient::BluetoothClient(QObject* parent)
//    : QObject(parent), m_socket(nullptr)
//{
//    // Initialize Bluetooth device discovery agent
//    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
//    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
//        this, &BluetoothClient::deviceDiscovered);
//
//    // Start device discovery
//    m_discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
//};
//
//BluetoothClient::~BluetoothClient()
//{
//    // Clean up resources (e.g., delete m_socket, disconnect signals, etc.)
//    if (m_socket) {
//        m_socket->disconnectFromDevice();
//        m_socket->deleteLater();
//    }
//}
//
//void BluetoothClient::send(const QString& message)
//{
//    //qCDebug(m_bluetooth) << "Attempting to send" << message ;
//    if (m_socket && m_socket->state() == QLowEnergyController::ConnectedState) {
//        QByteArray data = message.toUtf8();
//        //m_socket->writeCharacteristic(data);
//        // Write data to the characteristic
//        //controller->writeCharacteristic(characteristic, data);
//        //characteristic is assumed to be your QLowEnergyCharacteristic object representing the characteristic you want to write to.
//    }
//}
//
//void BluetoothClient::deviceDiscovered(const QBluetoothDeviceInfo& device)
//{
//    if (device.name() == "Blank") {
//        qCDebug(m_bluetooth) << "Found device:" << device.name() << device.address();
//        m_deviceInfo = device;
//        device_address = device.address();
//        m_discoveryAgent->stop();
//        connectToDevice();
//    }
//}
//
//void BluetoothClient::connectToDevice()
//{
//    if (m_deviceInfo.isValid()) {
//        // Create a Bluetooth socket
//        qCDebug(m_bluetooth) << "Create socket";
//        //m_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
//         
//        //FIX
//        /*m_socket = new QLowEnergyController:CSALCAT1(this);*/
//        m_socket = new QLowEnergyController(this);
//        connect(m_socket, &QLowEnergyController::connected, this, &BluetoothClient::onConnected);
//        connect(m_socket, &QLowEnergyController::disconnected, this, &BluetoothClient::onDisconnected);
//
//        //connect(m_socket, &QLowEnergyService::stateChanged, this, &BluetoothClient::getState);
//        //connect(m_socket, &QLowEnergyService::characteristicChanged, this, &BluetoothClient::readSocket);
//        connect(m_socket, &QLowEnergyController::error, this, &BluetoothClient::onErrorOccurred);
//        
//        // Connect to the discovered device
//            // Create Service UUID
//        //const QBluetoothUuid serviceUuid("9A48ECBA-2E92-082F-C079-9E75AAE428B1");
//        const QBluetoothUuid serviceUuid("0E9322C4-7513-40AB-AE21-E423DFC08BB7");
//            // Connect to service UUID
//        m_socket->connectToDevice();
//        //qCDebug(m_bluetooth) << "Connected to device Service UUID:" << m_deviceInfo.name();
//        
//        /*bool connected = (m_socket->state() == QAbstractSocket::ConnectedState);
//        if (connected)
//        {
//            qCDebug(m_bluetooth) << "Socket created and connected to device:" << m_deviceInfo.name();
//        }*/
//    }
//}
//void BluetoothClient::getState(QBluetoothSocket::SocketState state)
//{
//    switch (state)
//    {
//        //state value 0
//    case QBluetoothSocket::SocketState::UnconnectedState:
//        qCDebug(m_bluetooth) << "Socket is not connected.";
//        break;
//
//    // state value 1
//    case QBluetoothSocket::SocketState::ServiceLookupState:
//        qCDebug(m_bluetooth) << "Socket is querying connection parameters";
//        break;
//
//    case QBluetoothSocket::SocketState::ConnectingState:
//        qCDebug(m_bluetooth) << "Socket is attempting to connect to a device.";
//        break;
//
//    case QBluetoothSocket::SocketState::ConnectedState:
//        qCDebug(m_bluetooth) << "Socket is connected to device";
//        break;
//
//    case QBluetoothSocket::SocketState::BoundState:
//        qCDebug(m_bluetooth) << "Socket is bound to a local address and port";
//        break;
//
//        // state val 5
//    case QBluetoothSocket::SocketState::ClosingState:
//        qCDebug(m_bluetooth) << "Socket is connected and will be closed once all pending data is written to the socket";
//        break;
//
//    case QBluetoothSocket::SocketState::ListeningState:
//        qCDebug(m_bluetooth) << "Socket is listening for incoming connections";
//        break;
//    default:
//        qCDebug(m_bluetooth) << "Unknown Socket State";
//        break;
//    }
//
//}
//void BluetoothClient::onErrorOccurred(QBluetoothSocket::SocketError error)
//{
//    // resource https://doc.qt.io/qt-6/qlowenergycontroller.html#Error-enum
//    // Error debug messages 
//    // resource: https://doc.qt.io/qt-6/qbluetoothsocket.html#SocketError-enum
//    switch (error)
//    {
//    case QBluetoothSocket::SocketError::NoSocketError: // error code value 0
//        qCDebug(m_bluetooth) << "No error. Used for testing";
//        break;
//    case QBluetoothSocket::SocketError::UnknownSocketError: // error code value 1
//        qCDebug(m_bluetooth) << "Unknown error occured.";
//        break;
//    case QBluetoothSocket::SocketError::RemoteHostClosedError: // error code value 2
//        qCDebug(m_bluetooth) << "Remote host closed the connection.";
//        break;
//    case QBluetoothSocket::SocketError::HostNotFoundError: // error code value 3
//        qCDebug(m_bluetooth) << "Host not found.";
//        break;
//    
//    case QBluetoothSocket::SocketError::ServiceNotFoundError: // error code value 4
//        qCDebug(m_bluetooth) << "Could not find the service UUID on remote host";
//        break;
//    case QBluetoothSocket::SocketError::NetworkError: // error code value 5
//        qCDebug(m_bluetooth) << "Attempt to read or write from socket returned an error";
//        break;
//    case QBluetoothSocket::SocketError::UnsupportedProtocolError: // error code value 6
//        qCDebug(m_bluetooth) << "The Protocol is not supported on this platform.";
//        break;
//    case QBluetoothSocket::SocketError::OperationError: // error code value 7
//        qCDebug(m_bluetooth) << "An operation was attempted while the socket was in a state that did not permit it";
//        break;
//    case QBluetoothSocket::SocketError::MissingPermissionsError: // error code value 8
//        qCDebug(m_bluetooth) << "The operating system requests permissions which were not granted by the user.";
//        break;
//    default:
//        qCDebug(m_bluetooth) << "Unknown/unHandled socket error";
//        break;
//    }
//}
//
//void BluetoothClient::onConnected()
//{
//    qCDebug(m_bluetooth) << "Connected to device Service UUID:" << m_deviceInfo.name();
//    // Create characteristic UUID
//    const QBluetoothUuid charUuid("E05B7FCC-1920-465C-8BF9-AFB2BF45C25B");
//    // Connect to service UUID
//    m_socket->connectToDevice();
//    qCDebug(m_bluetooth) << "Connected to device Characteristic UUID:" << m_deviceInfo.name()<< m_deviceInfo.address();
//    // emit signal for connected
//    emit connected();
//}
//
//void BluetoothClient::onDisconnected()
//{
//    qCDebug(m_bluetooth) << "Disconnected from device:" << m_deviceInfo.name() << m_deviceInfo.address();
//    emit disconnected();
//}
//
//void BluetoothClient::readSocket()
//{
//  //todo not needed for tech demo
//}
