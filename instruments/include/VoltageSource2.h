#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H
#include "include/Instrument.h"
#include "include/Definition.h"

class VoltageSource1 : public Instrument
{
private:
    VoltageSourceStruct fVoltageParametrs;

public:
    VoltageSource1(ConnectionType pConectionType, std::string pAddress, std::string pName);
    ~VoltageSource1() {
        ;
    }
    void Initialize();
    //Getters
    VoltageSourceStruct GetVoltageParaemetrs();

    //Setters

    void SetVoltageParametrs(VoltageSourceStruct pVoltageParametrs);
    void SetBias(float startvoltage, float finalvoltage, VoltageSourceStruct pVoltageParametrs);




};

#endif // VOLTAGESOURCE_H
