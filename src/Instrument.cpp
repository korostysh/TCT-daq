#include "include/Instrument.h"


Instrument::Instrument(InstrumentType pInstrumentType, ConnectionType pConnectionType, std::string pAddress, std::string pName):
    fInstrumentType(pInstrumentType), fConnectionType(pConnectionType), fAddress(pAddress), fName(pName), fStatus(StatusType::Uninitialized)
{
    ;
}









