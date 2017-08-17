#ifndef DEFINITION_H
#define DEFINITION_H
#include <string>
#include "QString"

enum class ConnectionType {GPIB, USB, TCPIP, VICP, UNKNOWN};
enum class InstrumentType {VoltageSource, Osciloscope, TranslationStage, RotationStage, Laser, TemperatureController,Unknown};
enum class StatusType {Uninitialized, Ready, Error};

struct PositionType{
    float x;
    float y;
    float z;
};

struct StageSpeedType{
    float xSpeed;
    float ySpeed;
    float zSpeed;
};

struct DAQConfig {
    InstrumentType instrument_type;
    ConnectionType connection_type;
    std::string address;
    std::string name;
};



#endif // DEFINITION_H
