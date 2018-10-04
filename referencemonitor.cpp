#include "referencemonitor.h"

ReferenceMonitor::ReferenceMonitor()
{

}

void ReferenceMonitor::add_object()
{

}

void ReferenceMonitor::add_subject()
{

}

void ReferenceMonitor::execute_read()
{

}

void ReferenceMonitor::execute_write()
{

}

void ReferenceMonitor::evaluate(Instruction command, vector<Subject> &subjects, vector<Object> &objects)
{
    // Evaluate and perform the operation in the command
    // Add a new subject
    if (command.getCommand() == "ADDSUB")
    {
        Subject temp(command.getSubject_name(), command.getSec_level());
        subjects.push_back(temp);
    }

    // Add an object
    else if (command.getCommand() == "ADDOBJ")
    {
        Object temp(command.getObject_name(), command.getSec_level());
        objects.push_back(temp);
    }

    // Read an object
    else if (command.getCommand() == "READ")
    {

    }

    // Write to an object
    else if (command.getCommand() == "WRITE")
    {

    }
}

