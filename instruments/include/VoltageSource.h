#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H
#include "include/Instrument.h"
#include "include/Definition.h"

class VoltageSource : public Instrument
{
private:
    VoltageSourceStruct fVoltageParametrs;
    VoltageDAQ          fVoltageDAQ;

public:
    VoltageSource(ConnectionType pConectionType, std::string pAddress, std::string pName);
    VoltageSource(InstrumentType pInstrumentType, ConnectionType pConectionType, std::string pAddress, std::string pName);
    ~VoltageSource() {
        ;
    }
    void Initialize();
    //Getters
    VoltageSourceStruct GetVoltageParaemetrs();
    VoltageDAQ          GetVoltageDAQParaemetrs();

    //Setters

    void SetVoltageParametrs(VoltageSourceStruct pVoltageParametrs);
    void SetVoltageDAQParametrs(VoltageDAQ pVoltageDAQ);
    void SetBias(float startvoltage, float finalvoltage, VoltageSourceStruct *pVoltageParametrs);




};

#endif // VOLTAGESOURCE_H
