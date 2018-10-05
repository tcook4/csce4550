#include "referencemonitor.h"

ReferenceMonitor::ReferenceMonitor()
{

}

// Add a subject to the vector of subjects
void ReferenceMonitor::add_subject(Instruction command, vector<Subject> &subjects)
{
    Subject temp(command.getSubject_name(), command.getSec_level());
    subjects.push_back(temp);
}

// Add an object to the vector of objects
void ReferenceMonitor::add_object(Instruction command, vector<Object> &objects)
{
    Object temp(command.getObject_name(), command.getSec_level());
    objects.push_back(temp);
}

// Execute a read of an object
void ReferenceMonitor::execute_read(Instruction command, vector<Subject> &subjects, vector<Object> &objects)
{

}

// Execute a write on an object
void ReferenceMonitor::execute_write(Instruction command, vector<Subject> &subjects, vector<Object> &objects)
{

}

// Evaluate and perform the operation in an instruction object
void ReferenceMonitor::evaluate(Instruction command, vector<Subject> &subjects, vector<Object> &objects)
{
    // Add a new subject
    if (command.getCommand() == "ADDSUB")
    {
        add_subject(command, subjects);
    }

    // Add an object
    else if (command.getCommand() == "ADDOBJ")
    {
        add_object(command, objects);
    }

    // Read an object
    else if (command.getCommand() == "READ")
    {
        execute_read(command, subjects, objects);
    }

    // Write to an object
    else if (command.getCommand() == "WRITE")
    {
        execute_write(command, subjects, objects);
    }
}

