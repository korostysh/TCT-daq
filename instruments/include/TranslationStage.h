#ifndef TRANSLATIONSTAGE_H
#define TRANSLATIONSTAGE_H

#include "include/Definition.h"
#include "include/Instrument.h"

class TranslationStage : public Instrument
{
private:
     PositionType   fPosition;
     StageSpeedType fStageSpeed;

public:
    TranslationStage(ConnectionType pConectionType, std::string pAddress, std::string pName);
    //Getters
    PositionType     GetPosition();
    StageSpeedType   GetStageSpeed();

    //Setters
    void SetPosition          (PositionType pPosition);
    void SetStageSpeed      (StageSpeedType pStageSpeed);
};

#endif // TRANSLATIONSTAGE_H
