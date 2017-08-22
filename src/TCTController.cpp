#include "include/TCTController.h"
#include "instruments/include/TranslationStage.h"
#include "include/Definition.h"

TCTController::TCTController()
{
    if(fInstruments==0) fInstruments = new std::vector<Instrument*>;
}

void TCTController::Initialize(std::vector<DAQConfig *> *pDAQConfigs)
{
    if(!pDAQConfigs->empty()) {

        if(!fInstruments->empty()) {
            for(auto pInstrument: *fInstruments) delete pInstrument;
            fInstruments->clear();
        }

        fDAQConfigs = pDAQConfigs;
        for(auto config_word : *fDAQConfigs) {
            Instrument *pInstrument = 0;

            ConnectionType pConnectionType = config_word->connection_type;
            std::string pAddress = config_word->address;
            std::string pName = config_word->name;

            if (config_word->instrument_type == InstrumentType::TranslationStage) {
                //init translation stage
                pInstrument = (Instrument*) new TranslationStage(pConnectionType,pAddress,pName);
            }
            else if (config_word->instrument_type == InstrumentType::Oscilloscope) {
                //init oscilloscope
                pInstrument = (Instrument*) new Oscilloscope(pConnectionType,pAddress,pName);
            }
            if(pInstrument != 0) {
                pInstrument->Initialize();
                fInstruments->push_back(pInstrument);
            }
        }

    }
}

TCTController::~TCTController()
{
    if(!fInstruments->empty()) {
        for(auto pInstrument: *fInstruments) delete pInstrument;
        fInstruments->clear();
    }
}

TranslationStage* TCTController::GetTranslationStage() {
    for (auto pInstrument : *fInstruments) {
        if (pInstrument->GetInstrumentType() == InstrumentType::TranslationStage) {
            return (TranslationStage*)pInstrument;
        }
    }
    return 0;
}

Oscilloscope* TCTController::GetOscilloscope() {
    for (auto pInstrument : *fInstruments) {
        if (pInstrument->GetInstrumentType() == InstrumentType::Oscilloscope) {
            return (Oscilloscope*)pInstrument;
        }
    }
    return 0;
}

