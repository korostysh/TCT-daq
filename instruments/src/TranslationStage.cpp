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
PositionType TranslationStage::GetStartPosition(){
    return fStartPosition;
}

StageSpeedType TranslationStage::GetStageSpeed(){
    return fStageSpeed;
}

PositionNumofSteps TranslationStage::GetPositionNumofSteps(){
    return fPositionNumofSteps;
}

PositionStep TranslationStage::GetPositionStep(){
    return fPositionStep;
}

PositionStep TranslationStage::GetPositionStepDAQ(){
    return fPositionStepDAQ;
}

float TranslationStage::GetStageDelay(){
    return fStageDelay;
}


//Setters
void TranslationStage::SetPosition(PositionType pPosition){
    fPosition = pPosition;
}

void TranslationStage::SetStartPosition(PositionType pStartPosition){
    fStartPosition = pStartPosition;
}

void TranslationStage::SetStageSpeed(StageSpeedType pStageSpeed){
    fStageSpeed = pStageSpeed;
}

void TranslationStage::SetPositionNumofSteps(PositionNumofSteps pPositionNumofSteps){
    fPositionNumofSteps = pPositionNumofSteps;
}

void TranslationStage::SetPositionStep(PositionStep pPositionStep){
    fPositionStep = pPositionStep;
}

void TranslationStage::SetPositionStepDAQ(PositionStep pPositionStepDAQ){
    fPositionStepDAQ = pPositionStepDAQ;
}

void TranslationStage::SetStageDelay(float pStageDelay){
    fStageDelay = pStageDelay;
}


