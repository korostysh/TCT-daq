#include "include/Instrument.h"


Instrument::Instrument(InstrumentType pInstrumentType, ConnectionType pConectionType, std::string pAddress, std::string pName):
    fInstrumentType(pInstrumentType), fConectionType(pConectionType), fAddress(pAddress), fName(pName)
{
    ;
}

void Instrument::Initialize(){

}

//Setters

void Instrument::SetConnectionType(ConnectionType pConnectionType){

    fConectionType = pConnectionType;
}

void  Instrument::SetInstrumentType(InstrumentType pInstrumentType){
    fInstrumentType = pInstrumentType;
}

void  Instrument::SetAddress(std::string pAddress){
    fAddress = pAddress;
}

void  Instrument::SetName(std::string pName){
    fName = pName;
}



    //Getters
ConnectionType Instrument::GetConnectionType(){
    return fConectionType;
}

InstrumentType Instrument::GetInstrumentType(){
    return fInstrumentType;
}

std::string Instrument::GetAddress(){
    return fAddress;
}

std::string Instrument::GetName(){
    return fName;
}












