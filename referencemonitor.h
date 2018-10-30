#ifndef REFERENCEMONITOR_H
#define REFERENCEMONITOR_H

#include "subject.h"
#include "instruction.h"
#include "security_levels.h"
#include <map>
#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;

class ReferenceMonitor
{
public:
    ReferenceMonitor();
    void addObject(Instruction inst, vector<Object> &objects);
    void addSubject(Instruction inst, vector<Subject> &subjects);
    void executeRead(Instruction inst, vector<Subject> &subjects, vector<Object> &objects);
    void executeWrite(Instruction inst, vector<Subject> &subjects, vector<Object> &objects);
    void evaluate(Instruction inst, vector<Subject> &subjects, vector<Object> &objects);
    void printState(vector<Subject> &subjects, vector<Object> &objects, int final);

private:
    map<Object*, security_level> object_levels; // Map of Object security levels
    map<Subject*, security_level> subject_levels; // Map of Subject security levels
};

#endif // REFERENCEMONITOR_H
