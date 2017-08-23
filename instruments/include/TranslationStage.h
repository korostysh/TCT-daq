#ifndef TRANSLATIONSTAGE_H
#define TRANSLATIONSTAGE_H

#include "include/Definition.h"
#include "include/Instrument.h"

class TranslationStage : public Instrument
{
private:
     PositionType       fPosition;
     StageSpeedType     fStageSpeed;
     PositionStep       fPositionStep;
     PositionNumofSteps fPositionNumofSteps;

public:
    TranslationStage(ConnectionType pConectionType, std::string pAddress, std::string pName);
    ~TranslationStage() {}
    void Initialize();

    //Getters
    PositionType        GetPosition();
    StageSpeedType      GetStageSpeed();
    PositionStep        GetPositionStep();
    PositionNumofSteps  GetPositionNumofSteps();


    //Setters
    void SetPosition              (PositionType pPosition);
    void SetStageSpeed            (StageSpeedType pStageSpeed);
    void SetPositionStep          (PositionStep pPositionStep);
    void SetPositionNumofSteps    (PositionNumofSteps pPositionNumofSteps);
};

#endif // TRANSLATIONSTAGE_H
