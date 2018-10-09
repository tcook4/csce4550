#include "object.h"

Object::Object()
{
    name = "";
    value = 0;
    sec_level = UNAUTHENTICATED;
}

Object::Object(string str, security_level level)
{
    name = str;
    value = 0;
    sec_level = level;
}

void Object::set_value(int val)
{
    value = val;
}

string Object::getName() const
{
    return name;
}

int Object::getValue() const
{
    return value;
}

security_level Object::getSec_level() const
{
    return sec_level;
}

