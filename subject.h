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

    string getName() const;
    int getTemp() const;
    security_level getSec_level() const;

private:
    string name;
    int temp;
    security_level sec_level;
};

#endif // SUBJECT_H
