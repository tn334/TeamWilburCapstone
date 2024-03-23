#include "BluetoothServiceInfoModel.h"

using namespace Qt::StringLiterals;

Q_LOGGING_CATEGORY(m_service_info, "bluetooth.service.info")
Q_LOGGING_CATEGORY(m_service_error, "bluetooth.service.error")
Q_LOGGING_CATEGORY(m_service_state, "bluetooth.service.state")
BluetoothServiceInfoModel::BluetoothServiceInfoModel(QLowEnergyService* service) :
	m_service(service)
{
	m_service->setParent(this);

    // Connect the stateChanged signal to your slot/function
    connect(m_service, &QLowEnergyService::stateChanged, this, &BluetoothServiceInfoModel::onServiceState);

    // Connect the errorOccurred signal to your slot/function
    connect(m_service, &QLowEnergyService::errorOccurred, this, &BluetoothServiceInfoModel::onServiceError);
}

QLowEnergyService* BluetoothServiceInfoModel::service() const
{
	return m_service;
}

QList<QBluetoothUuid> BluetoothServiceInfoModel::getUuid() const
{
    if (!m_service)
    {
        QList<QBluetoothUuid> emptyList;
        return emptyList;
    }
    
    // Get UUIDs from device
    QList<QBluetoothUuid> uuids = m_service->includedServices();

    // Print out the UUIDs
    for (const auto& uuid : uuids) {
        qDebug(m_service_info) << "UUID: " << uuid.toString();
    }
    return uuids;

}

void BluetoothServiceInfoModel::onServiceError(QLowEnergyService::ServiceError error)
{
    // error code resource: https://doc.qt.io/qt-6/qlowenergyservice.html#ServiceError-enum
    switch (error)
    {
    case QLowEnergyService::NoError: // error value 0
        qCDebug(m_service_error) << "No error has occurred.";
        break;
    case QLowEnergyService::OperationError: // error value 1
        qCDebug(m_service_error) << "An operation was attempted while the service was not ready.";
        break;
    case QLowEnergyService::CharacteristicWriteError: // error value 2
        qCDebug(m_service_error) << "An attempt to write a new value to a characteristic failed.";
        break;
    case QLowEnergyService::DescriptorWriteError: // error value 3
        qCDebug(m_service_error) << "An attempt to write a new value to a descriptor failed.";
        break;
    case QLowEnergyService::UnknownError: // error value 4
        qCDebug(m_service_error) << "An unknown error occurred when interacting with the service.";
        break;
    case QLowEnergyService::CharacteristicReadError: // error value 5
        qCDebug(m_service_error) << "An attempt to read a characteristic value failed.";
        break;
    case QLowEnergyService::DescriptorReadError: // error value 6
        qCDebug(m_service_error) << "An attempt to read a descriptor value failed.";
        break;
    default:
        qCDebug(m_service_error) << "Unknown/unhandled error occured";
        break;
    }
}

void BluetoothServiceInfoModel::onServiceState(QLowEnergyService::ServiceState state)
{
    // state code resource: https://doc.qt.io/qt-6/qlowenergyservice.html#ServiceState-enum
    switch (state)
    {
    case QLowEnergyService::InvalidService: // state value 0
        qCDebug(m_service_state) << "Service has become invalid.";
        break;
    case QLowEnergyService::RemoteService: // error value 1
        qCDebug(m_service_state) << "he service details are yet to be discovered by calling discoverDetails().";
        break;
    case QLowEnergyService::RemoteServiceDiscovering: // error value 2
        qCDebug(m_service_state) << "The service details are being discovered.";
        break;
    case QLowEnergyService::RemoteServiceDiscovered: // error value 3
        qCDebug(m_service_error) << "	The service details have been discovered.";
        break;
    case QLowEnergyService::LocalService: // error value 4
        qCDebug(m_service_state) << "The service is associated with a controller object in the peripheral role. ";
        break;
    default:
        qCDebug(m_service_state) << "Unknown/unhandled state occured";
        break;
    }
}