#include "subject.h"

Subject::Subject()
{
    name = "";
    temp = 0;
}

void Subject::READ(Object &obj)
{
    temp = obj.get_value();
}

void Subject::WRITE(Object &obj, int value)
{
    obj.set_value(value);
}

