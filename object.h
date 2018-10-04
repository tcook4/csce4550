#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "security_levels.h"

using namespace std;

class Object
{
public:
    Object();
    Object(string str, security_level level);
    int get_value();
    void set_value(int val);

private:
    string name;
    int value;
    security_level sec_level;
};

#endif // OBJECT_H
