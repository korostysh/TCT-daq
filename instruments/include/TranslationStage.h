#ifndef TRANSLATIONSTAGE_H
#define TRANSLATIONSTAGE_H

#include "include/Definition.h"
#include "include/Instrument.h"

class TranslationStage : public Instrument
{
private:
     PositionType       fPosition;
     PositionType       fStartPosition;
     StageSpeedType     fStageSpeed;
     PositionStep       fPositionStep;
     PositionStep       fPositionStepDAQ;
     PositionNumofSteps fPositionNumofSteps;
     float              fStageDelay;

public:
    TranslationStage(ConnectionType pConectionType, std::string pAddress, std::string pName);
    ~TranslationStage() {}
    void Initialize();

    //Getters
    PositionType        GetPosition();
    PositionType        GetStartPosition();
    StageSpeedType      GetStageSpeed();
    PositionStep        GetPositionStep();
    PositionStep        GetPositionStepDAQ();
    PositionNumofSteps  GetPositionNumofSteps();
    float               GetStageDelay();



    //Setters
    void SetPosition              (PositionType pPosition);
    void SetStartPosition         (PositionType pStartPosition);
    void SetStageSpeed            (StageSpeedType pStageSpeed);
    void SetPositionStep          (PositionStep pPositionStep);
    void SetPositionStepDAQ       (PositionStep pPositionStepDAQ);
    void SetPositionNumofSteps    (PositionNumofSteps pPositionNumofSteps);
    void SetStageDelay            (float pStageDelay);
};

#endif // TRANSLATIONSTAGE_H
