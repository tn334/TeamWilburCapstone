//#include "BluetoothClientViewModel.h"
//
//// Declaring Logging object cite: https://doc.qt.io/qt-6.5/qloggingcategory.html
//Q_LOGGING_CATEGORY(m_bluetooth, "bluetooth")
//
//BluetoothClient::BluetoothClient(QObject* parent)
//    : QObject(parent), m_controller(nullptr)
//{
//    // Initialize Bluetooth device discovery agent
//    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
//    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
//        this, &BluetoothClient::deviceDiscovered);
//
//    // Start device discovery
//    m_discoveryAgent->start();
//};
//
//BluetoothClient::~BluetoothClient()
//{
//    // Clean up resources (e.g., delete m_controller, disconnect signals, etc.)
//    if (m_controller) {
//        m_controller->disconnectFromDevice();
//        m_controller->deleteLater();
//    }
//}
//
//void BluetoothClient::send(const QString& message)
//{
//    if (m_controller && m_controller->state() == QLowEnergyController::ConnectedState) {
//        QByteArray data = message.toUtf8();
//        // Write data to the characteristic
//        m_controller->writeCharacteristic(m_characteristic, data);
//    }
//}
//
//void BluetoothClient::deviceDiscovered(const QBluetoothDeviceInfo& info)
//{
//    if (info.name() == "Nipple Robot") {
//        qCDebug(m_bluetooth) << "Found device:" << info.name() << info.address();
//        m_deviceInfo = info;
//        connectToDevice();
//    }
//}
//
//void BluetoothClient::connectToDevice()
//{
//    if (m_deviceInfo.isValid()) {
//        // Create a Bluetooth Low Energy controller
//        qCDebug(m_bluetooth) << "Create controller";
//        m_controller = new QLowEnergyController(m_deviceInfo.address(), this);
//        connect(m_controller, &QLowEnergyController::connected, this, &BluetoothClient::onConnected);
//        connect(m_controller, &QLowEnergyController::disconnected, this, &BluetoothClient::onDisconnected);
//
//        // Connect to the discovered device
//        m_controller->connectToDevice();
//        qCDebug(m_bluetooth) << "Controller created and connected to device:" << m_deviceInfo.name();
//    }
//}
//
//void BluetoothClient::onConnected()
//{
//    qCDebug(m_bluetooth) << "Connected to device:" << m_deviceInfo.name() << m_deviceInfo.address();
//    // Discover services once connected
//    m_controller->discoverServices();
//}
//
//void BluetoothClient::onDisconnected()
//{
//    qCDebug(m_bluetooth) << "Disconnected from device:" << m_deviceInfo.name() << m_deviceInfo.address();
//    emit disconnected();
//}
//
//void BluetoothClient::serviceDiscovered(const QBluetoothUuid& uuid)
//{
//    QLowEnergyService* service = m_controller->createServiceObject(uuid);
//    if (service) {
//        // Discover characteristics of the service
//        service->discoverDetails();
//    }
//}
//
//void BluetoothClient::serviceDetailsDiscovered(QLowEnergyService::ServiceState state)
//{
//    if (state == QLowEnergyService::ServiceDiscovered) {
//        QLowEnergyService* service = qobject_cast<QLowEnergyService*>(sender());
//        if (service) {
//            // Find and store the desired characteristic
//            QList<QLowEnergyCharacteristic> characteristics = service->characteristics();
//            for (const QLowEnergyCharacteristic& characteristic : characteristics) {
//                if (characteristic.uuid() == QBluetoothUuid("{2D2F88C4-F244-5A80-21F1-EE0224E80658}")) {
//                    m_characteristic = characteristic;
//                    qCDebug(m_bluetooth) << "Found desired characteristic.";
//                    break;
//                }
//            }
//        }
//    }
//}
//
//void BluetoothClient::readCharacteristic()
//{
//    if (m_characteristic.isValid() && m_characteristic.properties() & QLowEnergyCharacteristic::Notify) {
//        m_controller->readCharacteristic(m_characteristic);
//    }
//}
//
//void BluetoothClient::characteristicChanged(const QLowEnergyCharacteristic& characteristic, const QByteArray& newValue)
//{
//    if (characteristic == m_characteristic) {
//        QString message = QString::fromUtf8(newValue);
//        qCDebug(m_bluetooth) << "Received message:" << message;
//        emit messageReceived(message);
//    }
//}
