#include "instruments/include/TranslationStage.h"

TranslationStage::TranslationStage(ConnectionType pConectionType, std::string pAddress, std::string pName):
    Instrument(InstrumentType::TranslationStage, pConectionType, pAddress, pName)
{
    ;
}

void TranslationStage::Initialize() {
    SetStatus(StatusType::Ready);
}

//Getters
PositionType TranslationStage::GetPosition(){
    return fPosition;
}

StageSpeedType TranslationStage::GetStageSpeed(){
    return fStageSpeed;
}

//Setters
void TranslationStage::SetPosition(PositionType pPosition){
    fPosition = pPosition;
}

void TranslationStage::SetStageSpeed(StageSpeedType pStageSpeed){
    fStageSpeed = pStageSpeed;
}
