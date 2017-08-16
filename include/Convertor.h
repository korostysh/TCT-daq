#ifndef CONVERTOR_H
#define CONVERTOR_H
#include "Definition.h"


class Convertor
{
public:
    Convertor();
    ConnectionType ConnectionStringToEnum(QString string);
    InstrumentType InstrumentStringToEnum(QString string);

private:
    ConnectionType ConnectionStringConvert;
    InstrumentType InstrumentStringConvert;

};
#endif // CONVERTOR_H
