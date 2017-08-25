#ifndef CONVERTOR_H
#define CONVERTOR_H
#include "Definition.h"


class Convertor
{
public:
    Convertor();
    ConnectionType ConnectionStringToEnum(QString string);
    InstrumentType InstrumentStringToEnum(QString string);
    QString        InstrumentEnumToString(InstrumentType instrument);
    QString        ConnectionEnumToString(ConnectionType instrument);

private:
    ConnectionType ConnectionStringConvert;
    InstrumentType InstrumentStringConvert;
    QString        result;

};
#endif // CONVERTOR_H
