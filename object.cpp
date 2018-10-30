#include "object.h"

Object::Object()
{
    name = "";
    value = 0;
}

Object::Object(string str)
{
    name = str;
    value = 0;
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

