#ifndef REFERENCEMONITOR_H
#define REFERENCEMONITOR_H

#include <vector>
#include "subject.h"
#include "instruction.h"
#include "security_levels.h"

using namespace std;

class ReferenceMonitor
{
public:
    ReferenceMonitor();
    void add_object(Instruction inst, vector<Object> &objects);
    void add_subject(Instruction inst, vector<Subject> &subjects);
    void execute_read(Instruction inst, vector<Subject> &subjects, vector<Object> &objects);
    void execute_write(Instruction inst, vector<Subject> &subjects, vector<Object> &objects);
    void evaluate(Instruction inst, vector<Subject> &subjects, vector<Object> &objects);
};

#endif // REFERENCEMONITOR_H
