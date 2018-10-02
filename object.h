#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>


class Object
{
public:
    Object();
    int get_value();
    void set_value(int val);

private:
    std::string name;
    int value;
};

#endif // OBJECT_H
