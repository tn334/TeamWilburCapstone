#include "BluetoothDeviceInfoModel.h"

BluetoothDeviceInfoModel::BluetoothDeviceInfoModel(const QBluetoothDeviceInfo& d)
{
    device = d;
}

QString BluetoothDeviceInfoModel::getAddress() const
{
    return device.address().toString();
}

QString BluetoothDeviceInfoModel::getName() const
{
    return device.name();
}

QBluetoothDeviceInfo BluetoothDeviceInfoModel::getDevice()
{
    return device;
}

void BluetoothDeviceInfoModel::setDevice(const QBluetoothDeviceInfo& dev)
{
    device = QBluetoothDeviceInfo(dev);
    emit deviceChanged();
}