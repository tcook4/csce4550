#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>


class Instruction
{
public:
    Instruction();
    void clear();

private:
    string command; // Command word to execute
    string object_name; // Object name of a command
    string subject_name; // Subject Name of a command
    int security_level; // Security level of an operation
};

#endif // INSTRUCTION_H
