#ifndef TRANSLATIONSTAGE_H
#define TRANSLATIONSTAGE_H

#include "include/Definition.h"
#include "include/Instrument.h"
#include "instruments/include/standa.h"

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
    PositionType        GetExpectedPosition();
    PositionType        GetRealPosition(Standa *XAxis, Standa *YAxis, Standa *ZAxis);
    PositionType        GetStartPosition();
    StageSpeedType      GetStageSpeed();
    PositionStep        GetPositionStep();
    PositionStep        GetPositionStepDAQ();
    PositionNumofSteps  GetPositionNumofSteps();
    float               GetStageDelay();



    //Setters
    void SetExpectredPosition   (PositionType pPosition);
    void SetPosition              (TranslationStage *pStage, Standa *XAxis, Standa *YAxis, Standa *ZAxis, PositionType pPosition, StageSpeedType pStageSpeed);
    void SetStartPosition         (PositionType pStartPosition);
    void SetStageSpeed            (StageSpeedType pStageSpeed);
    void SetPositionStep          (PositionStep pPositionStep);
    void SetPositionStepDAQ       (PositionStep pPositionStepDAQ);
    void SetPositionNumofSteps    (PositionNumofSteps pPositionNumofSteps);
    void SetStageDelay            (float pStageDelay);
    void SetCoordinate            (Standa *Axis, float pFinalPosition, int pSpeed);


};

#endif // TRANSLATIONSTAGE_H
