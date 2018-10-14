TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    subject.cpp \
    object.cpp \
    referencemonitor.cpp \
    instruction.cpp \
    BLPSecure.cpp

DISTFILES += \
    requirements \
    instructions \
    instList \
    expectedOutput \
    outputCompare

HEADERS += \
    subject.h \
    object.h \
    referencemonitor.h \
    instruction.h \
    security_levels.h

