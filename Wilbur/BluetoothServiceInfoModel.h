#pragma once
// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// resource: https://code.qt.io/cgit/qt/qtconnectivity.git/tree/examples/bluetooth/lowenergyscanner/serviceinfo.cpp?h=6.6

#ifndef BLUETOOTHSERVICEINFOMODEL_H
#define BLUETOOTHSERVICEINFOMODEL_H

#include <QObject>
#include <QLoggingCategory>
#include <QLowEnergyService>
#include <QtBluetooth/qbluetoothuuid.h>
#include <QtBluetooth/qlowenergyservice.h>

Q_DECLARE_LOGGING_CATEGORY(m_service_info)
Q_DECLARE_LOGGING_CATEGORY(m_service_error)
Q_DECLARE_LOGGING_CATEGORY(m_service_state)

class BluetoothServiceInfoModel : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString serviceUuid READ getUuid NOTIFY serviceChanged)

public:
    BluetoothServiceInfoModel() = default;
    BluetoothServiceInfoModel(QLowEnergyService* service);
    QLowEnergyService* service() const;
    QList<QBluetoothUuid> getUuid() const;


Q_SIGNALS:
    void serviceChanged();

private slots:
    void onServiceState(QLowEnergyService::ServiceState state);
    void onServiceError(QLowEnergyService::ServiceError error);

private:
    QLowEnergyService* m_service = nullptr;

};
#endif // BLUETOOTHSERVICEINFOMODEL_H
