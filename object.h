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
    void set_value(int val);

    string getName() const;
    int getValue() const;
    security_level getSec_level() const;

private:
    string name;
    int value;
    security_level sec_level;
};

#endif // OBJECT_H
