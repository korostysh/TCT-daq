#ifndef TCTCONTROLLER_H
#define TCTCONTROLLER_H
#include "vector"
#include "include/Definition.h"
#include "include/Instrument.h"
#include "instruments/include/TranslationStage.h"
#include "instruments/include/Oscilloscope.h"

class TCTController
{
public:
    TCTController();
    ~TCTController();
    void Initialize(std::vector<DAQConfig *> *pDAQConfigs);

    const std::vector<Instrument*>* GetInstruments() { return fInstruments; }
    TranslationStage* GetTranslationStage();
    Oscilloscope* GetOscilloscope();

private:
    std::vector<DAQConfig*> *fDAQConfigs = 0;
    std::vector<Instrument*> *fInstruments = 0;

};

#endif // TCTCONTROLLER_H
