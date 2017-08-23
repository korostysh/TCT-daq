#ifndef DEFINITION_H
#define DEFINITION_H
#include <string>
#include "QString"

enum class ConnectionType {GPIB, USB, TCPIP, VICP, UNKNOWN};
enum class InstrumentType {VoltageSource1, VoltageSource2, Oscilloscope, TranslationStage, RotationStage, Laser, TemperatureController,Unknown};
enum class StatusType {Uninitialized, Ready, Error};

struct PositionType{
    float x;
    float y;
    float z;
};

struct VoltageSourceStruct {
    float bias;
    float increase_step;
    float delay;
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

struct PositionStep {
    float xStep;
    float yStep;
    float zStep;
};

struct PositionNumofSteps{
    int xNumofSteps;
    int yNumOfSteps;
    int zNumOfSteps;
};

struct WaveForm {
    float Source1Voltage;
    float Source2Voltage;
    float x;
    float y;
    float z;
    std::vector<float> DataArray;
};



#endif // DEFINITION_H
