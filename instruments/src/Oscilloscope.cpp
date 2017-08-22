#include "instruments/include/Oscilloscope.h"

Oscilloscope::Oscilloscope(ConnectionType pConectionType, std::string pAddress, std::string pName):
    Instrument(InstrumentType::Oscilloscope, pConectionType, pAddress, pName)
{
    ;
}

void Oscilloscope::Initialize() {
    SetStatus(StatusType::Ready);
}
