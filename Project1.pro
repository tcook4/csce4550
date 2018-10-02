TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    subject.cpp \
    object.cpp

DISTFILES += \
    requirements

HEADERS += \
    subject.h \
    object.h

