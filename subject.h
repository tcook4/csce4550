#ifndef SUBJECT_H
#define SUBJECT_H

#include "object.h"
#include <string>

using namespace std;

class Subject
{
public:
    Subject();
    Subject(string str);
    void READ(Object &obj);
    void WRITE(Object &obj, int value);

    string getName() const;
    int getTemp() const;

private:
    string name; // Name of the subject
    int temp;    // Temp value of the subject
};

#endif // SUBJECT_H
