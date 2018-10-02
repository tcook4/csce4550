TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    subject.cpp \
    object.cpp \
    referencemonitor.cpp \
    instruction.cpp

DISTFILES += \
    requirements \
    instructions

HEADERS += \
    subject.h \
    object.h \
    referencemonitor.h \
    instruction.h

