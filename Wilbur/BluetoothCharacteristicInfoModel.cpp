#include "BluetoothCharacteristicInfoModel.h"

Q_LOGGING_CATEGORY(m_characteristic_info, "bluetooth.characteristic.info")

using namespace Qt::StringLiterals;

BluetoothCharacteristicInfoModel::BluetoothCharacteristicInfoModel(const QLowEnergyCharacteristic& characteristic) :
    m_characteristic(characteristic)
{
}

void BluetoothCharacteristicInfoModel::setCharacteristic(const QLowEnergyCharacteristic& characteristic)
{
    m_characteristic = characteristic;
    emit characteristicChanged();
}

QString BluetoothCharacteristicInfoModel::getName() const
{
    //! [les-get-descriptors]
    QString name = m_characteristic.name();
    if (!name.isEmpty())
        return name;

    // find descriptor with CharacteristicUserDescription
    const QList<QLowEnergyDescriptor> descriptors = m_characteristic.descriptors();
    for (const QLowEnergyDescriptor& descriptor : descriptors) {
        if (descriptor.type() == QBluetoothUuid::DescriptorType::CharacteristicUserDescription) {
            name = descriptor.value();
            break;
        }
    }
    //! [les-get-descriptors]

    if (name.isEmpty())
        name = u"Unknown"_s;

    return name;
}

QString BluetoothCharacteristicInfoModel::getUuid() const
{
    const QBluetoothUuid uuid = m_characteristic.uuid();
    bool success = false;
    quint16 result16 = uuid.toUInt16(&success);
    if (success)
        return u"0x"_s + QString::number(result16, 16);

    quint32 result32 = uuid.toUInt32(&success);
    if (success)
        return u"0x"_s + QString::number(result32, 16);

    return uuid.toString().remove('{'_L1).remove('}'_L1);
}

QString BluetoothCharacteristicInfoModel::getValue() const
{
    // Show raw string first and hex value below
    QByteArray a = m_characteristic.value();
    QString result;
    if (a.isEmpty()) {
        result = u"<none>"_s;
        return result;
    }

    result = a;
    result += '\n'_L1;
    result += a.toHex();

    return result;
}

QString BluetoothCharacteristicInfoModel::getPermission() const
{
    QString properties = u"( "_s;
    uint permission = m_characteristic.properties();
    if (permission & QLowEnergyCharacteristic::Read)
        properties += u" Read"_s;
    if (permission & QLowEnergyCharacteristic::Write)
        properties += u" Write"_s;
    if (permission & QLowEnergyCharacteristic::Notify)
        properties += u" Notify"_s;
    if (permission & QLowEnergyCharacteristic::Indicate)
        properties += u" Indicate"_s;
    if (permission & QLowEnergyCharacteristic::ExtendedProperty)
        properties += u" ExtendedProperty"_s;
    if (permission & QLowEnergyCharacteristic::Broadcasting)
        properties += u" Broadcast"_s;
    if (permission & QLowEnergyCharacteristic::WriteNoResponse)
        properties += u" WriteNoResp"_s;
    if (permission & QLowEnergyCharacteristic::WriteSigned)
        properties += u" WriteSigned"_s;
    properties += u" )"_s;
    return properties;
}

QLowEnergyCharacteristic BluetoothCharacteristicInfoModel::getCharacteristic() const
{
    return m_characteristic;
}
