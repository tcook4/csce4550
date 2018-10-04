#include "subject.h"

Subject::Subject()
{
    name = "";
    temp = 0;
}

Subject::Subject(string str, security_level level)
{
    name = str;
    sec_level = level;
}

void Subject::READ(Object &obj)
{
    temp = obj.get_value();
}

void Subject::WRITE(Object &obj, int value)
{
    obj.set_value(value);
}

