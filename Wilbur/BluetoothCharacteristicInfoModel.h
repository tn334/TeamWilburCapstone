#pragma once
#ifndef BLUETOOTHCHARACTERISTICINFOMODEL_H
#define BLUETOOTHCHARACTERISTICINFOMODEL_H

#include <qbluetoothuuid.h>
#include <QByteArray>
#include <QLowEnergyCharacteristic>
#include <QObject>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(m_characteristic_info)

class BluetoothCharacteristicInfoModel : public QObject
{
    Q_OBJECT

public:
    BluetoothCharacteristicInfoModel() = default;
    BluetoothCharacteristicInfoModel(const QLowEnergyCharacteristic& characteristic);
    void setCharacteristic(const QLowEnergyCharacteristic& characteristic);
    QString getName() const;
    QString getUuid() const;
    QString getValue() const;
    QString getPermission() const;
    QLowEnergyCharacteristic getCharacteristic() const;

Q_SIGNALS:
    void characteristicChanged();

private:
    QLowEnergyCharacteristic m_characteristic;
};

#endif // !BLUETOOTHCHARACTERISTICINFOMODEL_H


