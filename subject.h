#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>

#include "object.h"

class Subject
{
public:
    Subject();
    void READ(Object &obj);
    void WRITE(Object &obj, int value);

private:
    std::string name;
    int temp;
};

#endif // SUBJECT_H
