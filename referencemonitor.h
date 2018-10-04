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
    void add_object();
    void add_subject();
    void execute_read();
    void execute_write();
    void evaluate(Instruction command, vector<Subject> &subjects, vector<Object> &objects);
};

#endif // REFERENCEMONITOR_H
