//// BluetoothLE.h
//
//#ifndef BLUETOOTHLE_H
//#define BLUETOOTHLE_H
//
//#include <QObject>
//#include <QBluetoothDeviceInfo>
//#include <QBluetoothDeviceDiscoveryAgent>
//#include <QLowEnergyController>
//#include <QLowEnergyService>
//#include <QLowEnergyCharacteristic>
//
//class BluetoothLE : public QObject
//{
//    Q_OBJECT
//
//public:
//    explicit BluetoothLE(QObject* parent = nullptr);
//    ~BluetoothLE();
//
//    void startDeviceDiscovery();
//    void stopDeviceDiscovery();
//    void connectToDevice(const QBluetoothDeviceInfo& deviceInfo);
//    void disconnectFromDevice();
//    void send(const QString& message);
//
//signals:
//    void deviceDiscovered(const QBluetoothDeviceInfo& deviceInfo);
//    void deviceConnected();
//    void deviceDisconnected();
//    void messageReceived(const QString& message);
//
//private slots:
//    void deviceDiscoveredHandler(const QBluetoothDeviceInfo& deviceInfo);
//    void deviceConnectedHandler();
//    void deviceDisconnectedHandler();
//    void serviceDiscoveredHandler(const QBluetoothUuid& newService);
//    void characteristicChangedHandler(const QLowEnergyCharacteristic& characteristic, const QByteArray& newValue);
//
//private:
//    QBluetoothDeviceDiscoveryAgent m_deviceDiscoveryAgent;
//    QLowEnergyController* m_controller;
//    QLowEnergyService* m_service;
//    QLowEnergyCharacteristic m_characteristic;
//};
//
//#endif // BLUETOOTHLE_H
