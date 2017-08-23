#include "include/Convertor.h"

Convertor::Convertor()
{

}


ConnectionType Convertor::ConnectionStringToEnum(QString string){
    if (string == "GPIB\n") ConnectionStringConvert = ConnectionType::GPIB;
    else if (string == "USB\n") ConnectionStringConvert = ConnectionType::USB;
    else if (string == "TCPIP\n") ConnectionStringConvert = ConnectionType::TCPIP;
    else if (string == "VICP\n") ConnectionStringConvert = ConnectionType::VICP;
    else ConnectionStringConvert = ConnectionType::UNKNOWN;
    return ConnectionStringConvert;
}

InstrumentType Convertor::InstrumentStringToEnum(QString string){
    if (string == "VoltageSource1\n"){ InstrumentStringConvert = InstrumentType::VoltageSource1;}
    else if (string == "VoltageSource2\n"){ InstrumentStringConvert = InstrumentType::VoltageSource2;}
    else if (string == "Oscilloscope\n"){ InstrumentStringConvert = InstrumentType::Oscilloscope;}
    else if (string == "TranslationStage\n"){ InstrumentStringConvert = InstrumentType::TranslationStage;}
    else if (string == "RotationStage\n") {InstrumentStringConvert = InstrumentType::RotationStage;}
    else if (string == "Laser\n") {InstrumentStringConvert = InstrumentType::Laser;}
    else if (string == "TemperatureController\n") {InstrumentStringConvert = InstrumentType::TemperatureController;}
    else InstrumentStringConvert = InstrumentType::Unknown;
    return InstrumentStringConvert;
}
