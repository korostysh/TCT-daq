#ifndef OSCILLOSCOPE_H
#define OSCILLOSCOPE_H

#include "include/Definition.h"
#include "include/Instrument.h"

class Oscilloscope : public Instrument
{


public:
    Oscilloscope(ConnectionType pConectionType, std::string pAddress, std::string pName);
    ~Oscilloscope() {
        ;
    }
    void Initialize();

};

#endif // OSCILLOSCOPE_H
