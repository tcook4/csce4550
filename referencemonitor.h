#ifndef REFERENCEMONITOR_H
#define REFERENCEMONITOR_H

#include <subject.h>
#include <instruction.h>
#include <vector>
#include "security_levels.h"


class ReferenceMonitor
{
public:
    ReferenceMonitor();
    void add_object(Instruction command, vector<Object> &objects);
    void add_subject(Instruction command, vector<Subject> &subjects);
    void execute_read(Instruction command, vector<Subject> &subjects, vector<Object> &objects);
    void execute_write(Instruction command, vector<Subject> &subjects, vector<Object> &objects);
    void evaluate(Instruction command, vector<Subject> &subjects, vector<Object> &objects);
};

#endif // REFERENCEMONITOR_H
