#include "instruments/include/VoltageSource.h"
#include "include/Instrument.h"

VoltageSource::VoltageSource(ConnectionType pConectionType, std::string pAddress, std::string pName):
    Instrument(InstrumentType::TranslationStage, pConectionType, pAddress, pName)
{
    ;
}

void VoltageSource::Initialize() {
    SetStatus(StatusType::Ready);
}
