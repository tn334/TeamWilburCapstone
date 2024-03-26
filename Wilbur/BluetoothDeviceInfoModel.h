#pragma once
// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#ifndef BLUETOOTHDEVICEINFOMODEL_H
#define BLUETOOTHDEVICEINFOMODEL_H

#include <QtBluetooth/qbluetoothdeviceinfo.h>
#include <QBluetoothUuid>
#include <QBluetoothAddress>
#include <QString>
#include <QObject>

class BluetoothDeviceInfoModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString deviceName READ getName NOTIFY deviceChanged)
    Q_PROPERTY(QString deviceAddress READ getAddress NOTIFY deviceChanged)

public:
    BluetoothDeviceInfoModel() = default;
    BluetoothDeviceInfoModel(const QBluetoothDeviceInfo& d);
    QString getAddress() const;
    QString getName() const;
    QBluetoothDeviceInfo getDevice();
    void setDevice(const QBluetoothDeviceInfo& dev);

signals:
    void deviceChanged();

private:
    QBluetoothDeviceInfo device;
};

#endif // !BLUETOOTHDEVICEINFOMODEL_H


