#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialConnection : public QObject
{
    Q_OBJECT

public:
    explicit SerialConnection(QObject* parent = nullptr);
    ~SerialConnection();

    bool open(const QString& portName, qint32 baudRate);
    void close();
    qint64 write(const QString& data);
    char readSingleChar();

signals:
    void dataReceived(const QByteArray &data);

private slots:
    void readData();

private:
    QSerialPort* serialPort;
};

#endif // SERIALCONNECTION_H
