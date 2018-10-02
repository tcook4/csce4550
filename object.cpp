#include "object.h"

Object::Object()
{
    name = "";
    value = 0;
}

int Object::get_value()
{
    return value;
}

void Object::set_value(int val)
{
    value = val;
}

