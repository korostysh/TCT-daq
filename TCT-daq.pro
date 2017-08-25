#-------------------------------------------------
#
# Project created by QtCreator 2017-08-11T15:34:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCT-daq
TEMPLATE = app





unix:CONFIG += no_keywords # Python redefines some qt keywords
unix:INCLUDEPATH += /usr/include/python2.7
unix:LIBS += -lpython2.7

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/MainWindow.cpp \
    src/Instrument.cpp \
    instruments/src/TranslationStage.cpp \
    src/TCTController.cpp \
    src/Convertor.cpp \
    instruments/src/Oscilloscope.cpp \
    instruments/src/VoltageSource.cpp

HEADERS += \
        include/MainWindow.h \
    include/Instrument.h \
    instruments/include/TranslationStage.h \
    include/TCTController.h \
    include/Definition.h \
    include/Convertor.h \
    instruments/include/Oscilloscope.h \
    instruments/include/VoltageSource.h

FORMS += \
        forms/MainWindow.ui
