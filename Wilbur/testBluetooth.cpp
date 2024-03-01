#include <QCoreApplication>
#include <QLowEnergyServer>
#include <QLowEnergyService>
#include <QLowEnergyCharacteristic>
#include <QDebug>

#include <QDataStream> // for serialization/deserialization

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create a Bluetooth server
    QLowEnergyServer server("MyBluetoothServer", a);
    if (!server.listen(QLowEnergyServer::NonSecureMode)) {
        qDebug() << "Error: Cannot start server.";
        return 1;
    }

    // Create a Bluetooth service
    QLowEnergyService *service = new QLowEnergyService(server);

    // Create a characteristic for the service
    QLowEnergyCharacteristic characteristic(
        QBluetoothUuid::SerialPort,
        QLowEnergyCharacteristic::Read | QLowEnergyCharacteristic::Write,
        QBluetoothUuid::CharacteristicUserDescription,
        QByteArray("MyCharacteristic")
    );
    service->addCharacteristic(characteristic);

    // Handle incoming connections
    QObject::connect(&server, &QLowEnergyServer::newConnection, [&](QLowEnergyConnectionParameters params) {
        QLowEnergyService *newService = server.addService(QBluetoothUuid::SerialPort);
        if (!newService) {
            qDebug() << "Error: Cannot add new service.";
            return;
        }

        QObject::connect(newService, &QLowEnergyService::characteristicRead, [&](const QLowEnergyCharacteristic &c, const QByteArray &value) {
            qDebug() << "Characteristic Read:" << c.uuid() << "Value:" << value;

            // Deserialize the received byte array into an integer
            QDataStream stream(value);
            int intValue;
            stream >> intValue;
            qDebug() << "Received integer:" << intValue;
        });

        QObject::connect(newService, &QLowEnergyService::characteristicWritten, [&](const QLowEnergyCharacteristic &c, const QByteArray &value) {
            qDebug() << "Characteristic Written:" << c.uuid() << "Value:" << value;

            // Deserialize the received byte array into an integer
            QDataStream stream(value);
            int intValue;
            stream >> intValue;
            qDebug() << "Received integer:" << intValue;

            // Example: Write data back to the client
            int responseData = 42; // Example integer to send
            QByteArray responseByteArray;
            QDataStream responseStream(&responseByteArray, QIODevice::WriteOnly);
            responseStream << responseData;
            newService->writeCharacteristic(characteristic, responseByteArray);
        });
    });

    qDebug() << "Bluetooth server started.";

    return a.exec();
}
