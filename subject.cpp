#include "subject.h"

Subject::Subject()
{
    name = "";
    temp = 0;
    sec_level = UNAUTHENTICATED;
}

Subject::Subject(string str, security_level level)
{
    name = str;
    temp = 0;
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

string Subject::getName() const
{
    return name;
}

int Subject::getTemp() const
{
    return temp;
}

security_level Subject::getSec_level() const
{
    return sec_level;
}

