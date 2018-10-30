#include "subject.h"

Subject::Subject()
{
    name = "";
    temp = 0;
}

Subject::Subject(string str)
{
    name = str;
    temp = 0;
}

void Subject::READ(Object &obj)
{
    temp = obj.getValue();
}

void Subject::WRITE(Object &obj, int value)
{
    obj.set_value(value);
}

string Subject::getName() const
{
    return name;
}

int Subject::getTemp() const
{
    return temp;
}

