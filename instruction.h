#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <sstream>
using namespace std;


class Instruction
{
public:
    Instruction();
    void clear();
    void load(string commandStr);
    void to_upper(string &str);

private:
    string command; // Command word to execute
    string object_name; // Object name of a command
    string subject_name; // Subject Name of a command
    int security_level; // Security level of an operation
};

#endif // INSTRUCTION_H
