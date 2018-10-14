#include "referencemonitor.h"

ReferenceMonitor::ReferenceMonitor()
{

}

// Add a subject to the vector of subjects
void ReferenceMonitor::add_subject(Instruction inst, vector<Subject> &subjects)
{
    Subject temp(inst.getSubject_name(), inst.getSec_level());
    subjects.push_back(temp);
    cout << "Subject Added : " << inst.getCommand_ref() << endl;
}

// Add an object to the vector of objects
void ReferenceMonitor::add_object(Instruction inst, vector<Object> &objects)
{
    Object temp(inst.getObject_name(), inst.getSec_level());
    objects.push_back(temp);
    cout << "Object Added : " << inst.getCommand_ref() << endl;
}

// Execute a read of an object
// For BLPD, no read up is enforced - subject must be higher than object
void ReferenceMonitor::execute_read(Instruction inst, vector<Subject> &subjects, vector<Object> &objects)
{
    // Storage for applicable objects
    Subject *sub = NULL;
    Object *obj = NULL;

    // Find the subject and object of the operation
    for (vector<Subject>::iterator it = subjects.begin(); it != subjects.end(); ++it)
    {
        if (it->getName() == inst.getSubject_name())
        {
            sub = &*it;
            break;
        }
    }
    for (vector<Object>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        if (it->getName() == inst.getObject_name())
        {
            obj = &*it;
            break;
        }
    }

    // Verify we found subjects and objects to operate on
    if (sub == NULL || obj == NULL)
    {
        cout << "Access Denied : " << inst.getCommand_ref() << endl;
        return;
    }

    // Determine if our security level allows us to read the object
    if (sub->getSec_level() >= obj->getSec_level())
    {
        sub->READ(*obj);
        cout << "Access Granted : " << inst.getCommand_ref() << endl;
    }
    else
    {
        cout << "Access Denied : " << inst.getCommand_ref() << endl;

    }
}

// Execute a write on an object
// For BLPD, no write down is enforced
void ReferenceMonitor::execute_write(Instruction inst, vector<Subject> &subjects, vector<Object> &objects)
{
    // Storage for applicable objects
    Subject *sub = NULL;
    Object *obj = NULL;

    // Find the subject and object of the operation
    for (vector<Subject>::iterator it = subjects.begin(); it != subjects.end(); ++it)
    {
        if (it->getName() == inst.getSubject_name())
        {
            sub = &*it;
            break;
        }
    }
    for (vector<Object>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        if (it->getName() == inst.getObject_name())
        {
            obj = &*it;
            break;
        }
    }

    // Verify we found subjects and objects to operate on
    if (sub == NULL || obj == NULL)
    {
        cout << "Access Denied : " << inst.getCommand_ref() << endl;
        return;
    }

    // Determine if our security level allows us to write to the object
    if (sub->getSec_level() <= obj->getSec_level())
    {
        sub->WRITE(*obj, inst.getValue());
        cout << "Access Granted : " << sub->getName() << " writes " << inst.getValue() << " to " << obj->getName() << endl;
    }
    else
    {
        cout << "Access Denied : " << inst.getCommand_ref() << endl;
    }
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

