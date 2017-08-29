#include "instruments/include/TranslationStage.h"
#include "instruments/include/standa.h"

TranslationStage::TranslationStage(ConnectionType pConectionType, std::string pAddress, std::string pName):
    Instrument(InstrumentType::TranslationStage, pConectionType, pAddress, pName)
{
    ;
}

void TranslationStage::Initialize() {
    SetStatus(StatusType::Ready);
}

//Getters
PositionType TranslationStage::GetExpectedPosition(){
    return fPosition;
}

PositionType TranslationStage::GetRealPosition(Standa *XAxis, Standa *YAxis, Standa *ZAxis){
    PositionType pRealPosition;
    pRealPosition.x = XAxis->getCurrentPosition()*0.156;
    pRealPosition.y = YAxis->getCurrentPosition()*0.156;
    pRealPosition.z = ZAxis->getCurrentPosition()*0.156;
    return pRealPosition;
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
void TranslationStage::SetPosition(TranslationStage *pStage, Standa *XAxis, Standa *YAxis, Standa *ZAxis, PositionType pPosition, StageSpeedType pStageSpeed){


                pStage->SetCoordinate(XAxis, pPosition.x, pStageSpeed.xSpeed);
                pStage->SetCoordinate(YAxis, pPosition.y, pStageSpeed.ySpeed);
                pStage->SetCoordinate(ZAxis, pPosition.z, pStageSpeed.zSpeed);





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

void TranslationStage::SetExpectredPosition(PositionType pPosition){
    fPosition = pPosition;
}

void TranslationStage::SetCoordinate (Standa *Axis, float pFinalPosition, int pSpeed){
    float pCurrentPosition;
    pCurrentPosition = Axis->getCurrentPosition();

    float Steps = pFinalPosition/0.156 - pCurrentPosition;

    int intsteps = (int)(Steps + 0.5);

    int DestinationStep = intsteps+pCurrentPosition;
    Axis->setNewPosition(DestinationStep, pSpeed);
    int CurentStep = Axis->getCurrentPosition();
    if (Axis->GetTrailler()) Axis->Stop();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    while(Axis->IsMoving()){
        bool a = Axis->IsMoving();
        if (Axis->GetTrailler()) Axis->Stop();

    }
    if (Axis->GetTrailler()) Axis->Stop();
    pCurrentPosition = Axis->getCurrentPosition()*0.156;


}


