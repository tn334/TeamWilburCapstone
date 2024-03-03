#pragma once

#include <QObject>
#include <QDebug>
#include "QtBluetooth/QBluetoothDeviceDiscoveryAgent"
#include "QtBluetooth/QBluetoothSocket" 

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

    /*
    void send(const QString& message)
    {
        if (m_socket && m_socket->isOpen()) {
            m_socket->write(message.toUtf8());
            m_socket->waitForBytesWritten();
        }
    }
    */
private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo& info); // implementation in cpp file

    void connectToDevice(); // implementation in cpp file

    void onConnected(); // implementation in cpp file

    void onDisconnected(); // implementation in cpp file

    void readSocket(); // implementation in cpp file

private:
    QBluetoothDeviceDiscoveryAgent* m_discoveryAgent;
    QBluetoothDeviceInfo m_deviceInfo;
    QBluetoothSocket* m_socket;
};
