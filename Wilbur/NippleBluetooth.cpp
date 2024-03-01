#include <QObject>
#include <QDebug>
#include "QtBluetooth/qbluetoothserver.h"
#include "QtBluetooth/qbluetoothsocket.h"
#include "QtBluetooth/qbluetoothaddress.h"

class BluetoothServer : public QObject
{
    Q_OBJECT

public:
    explicit BluetoothServer(QObject* parent = nullptr)
        : QObject(parent), m_server(nullptr), m_socket(nullptr)
    {
        // Initialize Bluetooth server
        m_server = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol, this);

        connect(m_server, &QBluetoothServer::newConnection, this, &BluetoothServer::clientConnected);

        // Start listening
        bool success = m_server->listen(QBluetoothAddress(Address));
        if (!success) {
            qDebug() << "Failed to start server:";
        }
        else {
            qDebug() << "Server started, waiting for connections...";
        }
    }

    ~BluetoothServer()
    {
        if (m_socket) {
            m_socket->close();
            delete m_socket;
        }
        if (m_server) {
            m_server->close();
            delete m_server;
        }
    }

signals:
    void messageReceived(const QString& message);

private slots:
    void clientConnected()
    {
        m_socket = m_server->nextPendingConnection();
        connect(m_socket, &QBluetoothSocket::readyRead, this, &BluetoothServer::readSocket);

        qDebug() << "Client connected:" << m_socket->peerName();
    }

    void readSocket()
    {
        if (m_socket->canReadLine()) {
            QString message = QString::fromUtf8(m_socket->readLine()).trimmed();
            qDebug() << "Received message:" << message;

            // Emit signal for received message
            emit messageReceived(message);
        }
    }

private:
    QBluetoothServer* m_server;
    QBluetoothSocket* m_socket;
    QString Address = "17:06:42:11:69:91"; 

};
