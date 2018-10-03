#ifndef REFERENCEMONITOR_H
#define REFERENCEMONITOR_H

#include <subject.h>


class ReferenceMonitor
{
public:
    ReferenceMonitor();
    void add_object();
    void add_subject();
    void execute_read();
    void execute_write();
};

#endif // REFERENCEMONITOR_H
