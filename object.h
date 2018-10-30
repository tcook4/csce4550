#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "security_levels.h"

using namespace std;

class Object
{
public:
    Object();
    Object(string str);
    void set_value(int val);

    string getName() const; // Simple getter for reference monitor usage
    int getValue() const;   // Simple getter for reference monitor usage

private:
    string name; // Name of the object
    int value;   // Value heald by the object
};

#endif // OBJECT_H
