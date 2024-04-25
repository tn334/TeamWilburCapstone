#include "SerialConnection.h"
#include <QDebug>

SerialConnection::SerialConnection(QObject* parent)
    : QObject(parent),
    serialPort(new QSerialPort(this))
{
    connect(serialPort, &QSerialPort::readyRead, this, &SerialConnection::readData);
}

SerialConnection::~SerialConnection()
{
    close();
}

bool SerialConnection::open(const QString& portName, qint32 baudRate)
{
    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial port" << portName << "opened successfully.";
        return true;
    }
    else {
        qDebug() << "Failed to open serial port" << portName;
        return false;
    }
}

void SerialConnection::close()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Serial port closed.";
    }
}

qint64 SerialConnection::write(const QString& data)
{
    QByteArray toBeWritten = data.toUtf8();
    return serialPort->write(toBeWritten);
}

void SerialConnection::readData()
{
    QByteArray data = serialPort->readAll();
    qDebug() << "Read data:" << QString(data);

    emit dataReceived(data);
}

char SerialConnection::readSingleChar()
{
    char readChar = '\0';
    int numBytesRead = serialPort->read(&readChar, 1);

    if (numBytesRead > 0)
    {
        return readChar;
    }

    return '\0';
}
