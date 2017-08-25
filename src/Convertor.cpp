#include "include/Convertor.h"

Convertor::Convertor()
{

}


ConnectionType Convertor::ConnectionStringToEnum(QString string){
    if (string == "GPIB") ConnectionStringConvert = ConnectionType::GPIB;
    else if (string == "USB") ConnectionStringConvert = ConnectionType::USB;
    else if (string == "TCPIP") ConnectionStringConvert = ConnectionType::TCPIP;
    else if (string == "VICP") ConnectionStringConvert = ConnectionType::VICP;
    else ConnectionStringConvert = ConnectionType::UNKNOWN;
    return ConnectionStringConvert;
}

InstrumentType Convertor::InstrumentStringToEnum(QString string){
    if (string == "VoltageSource1"){ InstrumentStringConvert = InstrumentType::VoltageSource1;}
    else if (string == "VoltageSource2"){ InstrumentStringConvert = InstrumentType::VoltageSource2;}
    else if (string == "Oscilloscope"){ InstrumentStringConvert = InstrumentType::Oscilloscope;}
    else if (string == "TranslationStage"){ InstrumentStringConvert = InstrumentType::TranslationStage;}
    else if (string == "RotationStage") {InstrumentStringConvert = InstrumentType::RotationStage;}
    else if (string == "Laser") {InstrumentStringConvert = InstrumentType::Laser;}
    else if (string == "TemperatureController") {InstrumentStringConvert = InstrumentType::TemperatureController;}
    else InstrumentStringConvert = InstrumentType::Unknown;
    return InstrumentStringConvert;
}

QString  Convertor::InstrumentEnumToString(InstrumentType instrument){
    if (instrument == InstrumentType::VoltageSource1){ result =  "VoltageSource1";}
    else if (instrument == InstrumentType::VoltageSource2){ result =  "VoltageSource2";}
    else if (instrument == InstrumentType::Oscilloscope){ result =  "Oscilloscope";}
    else if (instrument == InstrumentType::TranslationStage){ result =  "TranslationStage";}
    else if (instrument == InstrumentType::RotationStage) {result =  "RotationStage";}
    else if (instrument == InstrumentType::Laser) {result =  "Laser";}
    else if (instrument == InstrumentType::TemperatureController) {result =  "TemperatureController";}
    else result = "Unknown";
    return result;
}
QString  Convertor::ConnectionEnumToString(ConnectionType conection){
    if (conection ==ConnectionType::GPIB) result = "GPIB";
    else if (conection == ConnectionType::USB ) result =  "USB";
    else if (conection == ConnectionType::TCPIP) result =  "TCPIP";
    else if (conection == ConnectionType::VICP) result =  "VICP";
    else result = "UNKNOWN";
    return result;
}
