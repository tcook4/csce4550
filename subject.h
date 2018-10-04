#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include "object.h"

using namespace std;

class Subject
{
public:
    Subject();
    Subject(string str, security_level level);
    void READ(Object &obj);
    void WRITE(Object &obj, int value);

private:
    string name;
    int temp;
    security_level sec_level;
};

#endif // SUBJECT_H
