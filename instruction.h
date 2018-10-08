#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <sstream>
#include "security_levels.h"

using namespace std;

class Instruction
{
public:
    Instruction();

    void clear();
    bool load(string commandStr);
    void to_upper(string &str);
    void set_security(string sec);
    void print();

    string getCommand() const;
    string getObject_name() const;
    string getSubject_name() const;
    string getCommand_ref() const;
    security_level getSec_level() const;

private:
    string command; // Command word to execute
    string object_name; // Object name of a command
    string subject_name; // Subject Name of a command
    string security_str; // Security level of an operation
    string command_ref; // Storage for original command as given
    security_level sec_level; // Security enum of an operation
    int value; // Value to write to an object
};

#endif // INSTRUCTION_H
