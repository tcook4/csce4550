#include "object.h"

Object::Object()
{
    name = "";
    value = 0;
}

Object::Object(string str, security_level level)
{
    name = str;
    sec_level = level;
}

int Object::get_value()
{
    return value;
}

void Object::set_value(int val)
{
    value = val;
}

