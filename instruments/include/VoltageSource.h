#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H
#include "include/Instrument.h"
#include "include/Definition.h"

class VoltageSource : public Instrument
{
public:
    VoltageSource(ConnectionType pConectionType, std::string pAddress, std::string pName);
    ~VoltageSource() {
        ;
    }
    void Initialize();
    //Getters
    VoltageSource GetVoltageParaemetrs();

    //Setters

    void SetVoltageParametrs(VoltageSourceStruct pVoltageParametrs);
    void SetBias(float startvoltage, float finalvoltage, VoltageSourceStruct pVoltageParametrs);




};

#endif // VOLTAGESOURCE_H
