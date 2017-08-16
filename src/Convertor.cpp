#include "include/Convertor.h"

Convertor::Convertor()
{

}


ConnectionType Convertor::ConnectionStringToEnum(QString string){
    if (string == "GPIB\n") ConnectionStringConvert = ConnectionType::GPIB;
    if (string == "USB\n") ConnectionStringConvert = ConnectionType::USB;
    if (string == "TCPIP\n") ConnectionStringConvert = ConnectionType::TCPIP;
    if (string == "VICP\n") ConnectionStringConvert = ConnectionType::VICP;
    return ConnectionStringConvert;
}

InstrumentType Convertor::InstrumentStringToEnum(QString string){
    if (string == "VoltageSource\n"){ InstrumentStringConvert = InstrumentType::VoltageSource;}
    else if (string == "Osciloscope\n"){ InstrumentStringConvert = InstrumentType::Osciloscope;}
    else if (string == "TranslationStage\n"){ InstrumentStringConvert = InstrumentType::TranslationStage;}
    else if (string == "RotationStage\n") {InstrumentStringConvert = InstrumentType::RotationStage;}
    else if (string == "Laser\n") {InstrumentStringConvert = InstrumentType::Laser;}
    else if (string == "TemperatureController\n") {InstrumentStringConvert = InstrumentType::TemperatureController;}
    else InstrumentStringConvert = InstrumentType::Unknown;
    return InstrumentStringConvert;
}
