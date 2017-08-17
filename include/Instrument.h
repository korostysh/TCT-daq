#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "include/Definition.h"
#include <iostream>
#include <string>

class Instrument
{
private:

    ConnectionType fConnectionType;
    InstrumentType fInstrumentType;
    std::string fAddress;
    std::string fName;

    StatusType fStatus;

public:

    Instrument(InstrumentType pInstrumentType, ConnectionType pConnectionType, std::string pAddress, std::string pName);
    virtual ~Instrument() {}
    virtual void Initialize() = 0;

    //Getters
    ConnectionType   GetConnectionType() { return fConnectionType; }
    InstrumentType   GetInstrumentType() { return fInstrumentType; }
    std::string      GetAddress() { return fAddress; }
    std::string      GetName() { return fName; }
    StatusType       GetStatus() { return fStatus; }


    //Setters
    void SetConnectionType    (ConnectionType pConnectionType) { fConnectionType = pConnectionType; }
    void SetInstrumentType    (InstrumentType pInstrumentType) { fInstrumentType = pInstrumentType; }
    void SetAddress           (std::string pAddress) { fAddress = pAddress; }
    void SetName              (std::string pName) { fName = pName; }
    void SetStatus            (StatusType pStatus) { fStatus = pStatus; }


};

#endif // INSTRUMENT_H
