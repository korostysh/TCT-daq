#include "instruments/include/VoltageSource.h"
#include "include/Instrument.h"
#include "include/Definition.h"


VoltageSource::VoltageSource(ConnectionType pConectionType, std::string pAddress, std::string pName):
    Instrument(InstrumentType::VoltageSource1, pConectionType, pAddress, pName)
{
    ;
}

VoltageSource::VoltageSource(InstrumentType pInstrumentType, ConnectionType pConectionType, std::string pAddress, std::string pName):
    Instrument(pInstrumentType, pConectionType, pAddress, pName)
{
    ;
}



void VoltageSource::Initialize() {
    SetStatus(StatusType::Ready);
}

VoltageSourceStruct VoltageSource::GetVoltageParaemetrs(){
    return fVoltageParametrs;
}

VoltageDAQ VoltageSource::GetVoltageDAQParaemetrs(){
    return fVoltageDAQ;
}

void VoltageSource::SetVoltageDAQParametrs(VoltageDAQ pVoltageDAQ){
    fVoltageDAQ = pVoltageDAQ;
}

void VoltageSource::SetVoltageParametrs(VoltageSourceStruct pVoltageParametrs){
     fVoltageParametrs = pVoltageParametrs;
}


void VoltageSource::SetBias(float startvoltage, float finalvoltage, VoltageSourceStruct *pVoltageParametrs){
    int milisecondDelay =  static_cast<int>(pVoltageParametrs->delay*1000);
    if (startvoltage <= finalvoltage){
        float Voltage = startvoltage;
        while (Voltage < finalvoltage + pVoltageParametrs->increase_step){
            Voltage += pVoltageParametrs->increase_step;
            std::this_thread::sleep_for(std::chrono::milliseconds(milisecondDelay));
            //send signal to voltage source
        }
        Voltage = finalvoltage;
        std::this_thread::sleep_for(std::chrono::milliseconds(milisecondDelay));
        ;
    }
    else if (startvoltage > finalvoltage){
        float Voltage = startvoltage;
        while (Voltage > finalvoltage - pVoltageParametrs->increase_step){
            Voltage -= pVoltageParametrs->increase_step;
            std::this_thread::sleep_for(std::chrono::milliseconds(milisecondDelay));
            //send signal to voltage source
        }
        Voltage = finalvoltage;
        std::this_thread::sleep_for(std::chrono::milliseconds(milisecondDelay));
        ;
    }
}
