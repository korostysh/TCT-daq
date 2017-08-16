#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "include/Definition.h"
#include <iostream>
#include <string>

class Instrument
{
private:

    ConnectionType fConectionType;
    InstrumentType fInstrumentType;
    std::string fAddress;
    std::string fName;
public:

    Instrument(InstrumentType pInstrumentType, ConnectionType pConectionType, std::string pAddress, std::string pName);
    void Initialize();

    //Getters
    ConnectionType   GetConnectionType() ;
    InstrumentType   GetInstrumentType() ;
    std::string      GetAddress();
    std::string      GetName() ;


    //Setters

    void SetConnectionType    (ConnectionType pConnectionType);
    void SetInstrumentType    (InstrumentType pInstrumentType);
    void SetAddress            (std::string pAddress);
    void SetName              (std::string pName);




};

#endif // INSTRUMENT_H
