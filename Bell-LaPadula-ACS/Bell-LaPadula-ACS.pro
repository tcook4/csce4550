TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    subject.cpp \
    referencemonitor.cpp \
    object.cpp \
    instruction.cpp \
    BLPSecure.cpp

SUBDIRS += \
    Project1.pro

DISTFILES += \
    Project1.pro.user \
    requirements \
    outputCompare \
    instructions \
    instList \
    expectedOutput

HEADERS += \
    subject.h \
    security_levels.h \
    referencemonitor.h \
    object.h \
    instruction.h

