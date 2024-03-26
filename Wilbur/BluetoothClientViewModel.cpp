// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

//https://doc.qt.io/qt-6/qtbluetooth-le-overview.html

// Coded in tandem with AI
#include "BluetoothClientViewModel.h"

// Declaring Logging object cite: https://doc.qt.io/qt-6.5/qloggingcategory.html
Q_LOGGING_CATEGORY(m_bluetooth, "bluetooth")
Q_LOGGING_CATEGORY(m_controller_error, "bluetooth.controller.error")
Q_LOGGING_CATEGORY(m_controller_state, "bluetooth.controller.state")

BluetoothClient::BluetoothClient(QObject* parent)
    : QObject(parent), m_controller(nullptr), 
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
    // Clean up resources (e.g., delete m_controller, disconnect signals, etc.)
    if (m_controller) {
        m_controller->disconnectFromDevice();
        m_controller->deleteLater();
    }
    delete m_service;
}

void BluetoothClient::send(const QString& message)
{
    qCDebug(m_bluetooth) << "Attempting to send" << message ;
    if (m_controller && m_controller->state() == QLowEnergyController::ConnectedState) {
        QByteArray data = message.toUtf8();
        //qCDebug(m_bluetooth) << "list of services: " << m_controller->services(); empty qlist
        

        //m_controller->writeCharacteristic(data);
        // Write data to the characteristic
        //controller->writeCharacteristic(characteristic, data);
        //characteristic is assumed to be your QLowEnergyCharacteristic object representing the characteristic you want to write to.
    }
}

void BluetoothClient::deviceDiscovered(const QBluetoothDeviceInfo& device)
{
    if (device.name() == "Nipple Robot") {
        //const QBluetoothUuid uuid = m_service->serviceUuid();

        qCDebug(m_bluetooth) << "Found device:" << device.name() << " device address:" << device.address();

        // store device info
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
        qCDebug(m_bluetooth) << "Device information is valid";
        //m_controller = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
         
        //FIX
        // Look for services
        // Connect serviceDiscovered signal to onServiceDiscovered
        connect(m_controller, &QLowEnergyController::serviceDiscovered, this, &BluetoothClient::onServiceDiscovered);
        connect(m_controller, &QLowEnergyController::discoveryFinished, this, &BluetoothClient::serviceScanDone);

        m_controller = QLowEnergyController::createCentral(m_deviceInfo, this);
        // Connect connected signal to onConnected
        connect(m_controller, &QLowEnergyController::connected, this, &BluetoothClient::onConnected);
        // Connect disconnected signal to onDisconnected
        connect(m_controller, &QLowEnergyController::disconnected, this, &BluetoothClient::onDisconnected);

        // Connect signal to function
        connect(m_controller, &QLowEnergyController::stateChanged, this, &BluetoothClient::getState);
        // Connect signal to function
        connect(m_controller, &QLowEnergyController::errorOccurred, this, &BluetoothClient::onErrorOccurred);
        
        // Connect to the discovered device
            // Create Service UUID
        //const QBluetoothUuid serviceUuid("9A48ECBA-2E92-082F-C079-9E75AAE428B1");
            // Connect to service UUID
        //m_controller->discoverServices(); moved tp onConnected
        m_controller->connectToDevice();
        
        
    }
}

void BluetoothClient::getState(QLowEnergyController::ControllerState state)
{
    //resource for ControllerState values and desscription: https://doc.qt.io/qt-6/qlowenergycontroller.html#ControllerState-enum
    switch (state)
    {
    case QLowEnergyController::UnconnectedState: // value 0
        qCDebug(m_controller_state) << "The controller is not connected to a remote device.";
        break;

    case QLowEnergyController::ConnectingState: // value 1
        qCDebug(m_controller_state) << "The controller is attempting to connect to a remote device.";
        break;

    case QLowEnergyController::ConnectedState: // value 2
        qCDebug(m_controller_state) << "The controller is connected to a remote device.";
        break;

    case QLowEnergyController::DiscoveringState: // value 3
        qCDebug(m_controller_state) << "The controller is retrieving the list of services offered by the remote device.";
        break;

    case QLowEnergyController::DiscoveredState: // value 4
        qCDebug(m_controller_state) << "The controller has discovered all services offered by the remote device.";
        break;

    case QLowEnergyController::ClosingState: //value 5
        qCDebug(m_controller_state) << "The controller is about to be disconnected from the remote device.";
        break;

    case QLowEnergyController::AdvertisingState: // value 6
        qCDebug(m_controller_state) << "The controller is currently advertising data.";
        break;
    default:
        qCDebug(m_controller_state) << "Unknown Controller State";
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
        qCDebug(m_controller_error) << "No error has occurred. Used for testing";
        break;
    case QLowEnergyController::UnknownError: // error code value 1
        qCDebug(m_controller_error) << "An unknown error has occurred.";
        break;
    case QLowEnergyController::UnknownRemoteDeviceError: // error code value 2
        qCDebug(m_controller_error) << "The remote Bluetooth Low Energy device with the address passed to the constructor of this class cannot be found.";
        break;
    case QLowEnergyController::NetworkError: // error code value 3
        qCDebug(m_controller_error) << "The attempt to read from or write to the remote device failed.";
        break;

    case QLowEnergyController::InvalidBluetoothAdapterError: // error code value 4
        qCDebug(m_controller_error) << "The local Bluetooth device with the address passed to the constructor of this class cannot be found or there is no local Bluetooth device.";
        break;
    case QLowEnergyController::ConnectionError: // error code value 5
        qCDebug(m_controller_error) << "The attempt to connect to the remote device failed.";
        break;
    case QLowEnergyController::AdvertisingError: // error code value 6
        qCDebug(m_controller_error) << "The attempt to start advertising failed.";
        break;
    case QLowEnergyController::RemoteHostClosedError: // error code value 7
        qCDebug(m_controller_error) << "The remote device closed the connection.";
        break;
    case QLowEnergyController::AuthorizationError: // error code value 8
        qCDebug(m_controller_error) << "The local Bluetooth device closed the connection due to insufficient authorization.";
        break;
    case QLowEnergyController::MissingPermissionsError: // error code value 9
        qCDebug(m_controller_error) << "The operating system requests permissions which were not granted by the user.";
        break;
    case QLowEnergyController::RssiReadError: // error code value 10
        qCDebug(m_controller_error) << "An attempt to read RSSI (received signal strength indicator) of a remote device finished with error.";
        break;
    default:
        qCDebug(m_controller_error) << "Unknown/unHandled error";
        break;
    }
}

void BluetoothClient::onConnected()
{
    m_controller->discoverServices();
    qCDebug(m_bluetooth) << "Connected to device Service UUID:" << m_deviceInfo.name();
    // Create characteristic UUID
    const QBluetoothUuid charUuid("2D2F88C4-F244-5A80-21F1-EE0224E80658");
    // Connect to service UUID
    m_controller->connectToDevice();
    qCDebug(m_bluetooth) << "Connected to device Characteristic UUID:" << m_deviceInfo.name()<< m_deviceInfo.address();
    // emit signal for connected
    emit connected();
}

void BluetoothClient::onDisconnected()
{
    // if controller initiated
    if (m_controller)
    {
        m_controller->disconnectFromDevice();
    }
    // device initiated
    else {
        delete m_service;
        m_service = nullptr;
    }
    qCDebug(m_bluetooth) << "Disconnected from device:" << m_deviceInfo.name() << m_deviceInfo.address();

    //emit disconnected();
}

void BluetoothClient::readSocket()
{
  //todo not needed for tech demo
}
// Handler Function
void BluetoothClient::onServiceDiscovered(const QBluetoothUuid& newService)
{
    // Check if the discovered service matches the one you're interested in
    QBluetoothUuid test("9A48ECBA-2E92-082F-C079-9E75AAE428B1");

    if (newService == test) 
    {
        // set flag to true
        // Retrieve the service
        m_service = m_controller->createServiceObject(newService, this);
        if (m_service)
        {
            // Connect to the service's stateChanged signal
            connect(m_service, &QLowEnergyService::stateChanged, this, &BluetoothClient::onServiceStateChanged);
        }


        // Discover the details of the service, including its characteristics
        m_service->discoverDetails();
    }
}

void BluetoothClient::onServiceStateChanged(QLowEnergyService::ServiceState newState)
{
    if (newState == QLowEnergyService::ServiceDiscovered) {
        // Service has been discovered, now you can interact with its characteristics

        // Retrieve the desired characteristic within the service
        QBluetoothUuid test("2D2F88C4-F244-5A80-21F1-EE0224E80658");

        m_characteristic = m_service->characteristic(test);

        // Now you can read from or write to the characteristic as needed
    }
}

void BluetoothClient::serviceScanDone()
{
    // Delete old service if available
    if (m_service) 
    {
        delete m_service;
        m_service = nullptr;
    }
}
