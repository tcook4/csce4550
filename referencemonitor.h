#ifndef REFERENCEMONITOR_H
#define REFERENCEMONITOR_H

#include "subject.h"
#include "instruction.h"
#include "security_levels.h"
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
};

#endif // REFERENCEMONITOR_H
