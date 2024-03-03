
#include <QObject>
#include <QDebug>
#include "QtBluetooth/QBluetoothDeviceDiscoveryAgent"
#include "QtBluetooth/QBluetoothSocket"

class BluetoothClient : public QObject
{
    Q_OBJECT

public:
    explicit BluetoothClient(QObject* parent = nullptr)
        : QObject(parent), m_socket(nullptr)
    {
        // Initialize Bluetooth device discovery agent
        m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
        connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothClient::deviceDiscovered);

        // Start device discovery
        m_discoveryAgent->start();
    }

signals:
    void connected();
    void disconnected();
    void messageReceived(const QString& message);

public slots:
    
    void send(const QString& message)
    {
        if (m_socket && m_socket->isOpen()) {
            QByteArray data = message.toUtf8();
            m_socket->write(data);
        }
    }

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
    void deviceDiscovered(const QBluetoothDeviceInfo& info)
    {
        if (info.address().toString() == "17:06:42:11:69:91") {
            qDebug() << "Found device:" << info.name() << info.address();
            m_deviceInfo = info;
            connectToDevice();
        }
    }


    void connectToDevice()
    {
        if (m_deviceInfo.isValid()) {
            // Create a Bluetooth socket
            m_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
            connect(m_socket, &QBluetoothSocket::connected, this, &BluetoothClient::onConnected);
            connect(m_socket, &QBluetoothSocket::disconnected, this, &BluetoothClient::onDisconnected);
            connect(m_socket, &QBluetoothSocket::readyRead, this, &BluetoothClient::readSocket);

            // Connect to the discovered device
            m_socket->connectToService(m_deviceInfo.address(), QBluetoothUuid(QString("{00001101-0000-1000-8000-00805F9B34FB}")));
        }
    }

    void onConnected()
    {
        qDebug() << "Connected to device:" << m_deviceInfo.name() << m_deviceInfo.address();
        emit connected();
    }

    void onDisconnected()
    {
        qDebug() << "Disconnected from device:" << m_deviceInfo.name() << m_deviceInfo.address();
        emit disconnected();
    }

    void readSocket()
    {
        if (m_socket && m_socket->canReadLine()) {
            QString message = QString::fromUtf8(m_socket->readLine()).trimmed();
            qDebug() << "Received message:" << message;
            emit messageReceived(message);
        }
    }

private:
    QBluetoothDeviceDiscoveryAgent* m_discoveryAgent;
    QBluetoothDeviceInfo m_deviceInfo;
    QBluetoothSocket* m_socket;
};
