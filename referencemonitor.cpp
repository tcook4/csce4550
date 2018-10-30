#include "referencemonitor.h"

ReferenceMonitor::ReferenceMonitor()
{

}

// Add a subject to the vector of subjects
void ReferenceMonitor::addSubject(Instruction inst, vector<Subject> &subjects)
{
    // Create and push back the subject
    Subject temp(inst.getSubject_name());
    subjects.push_back(temp);

    // Get the index of our newly pushed subject
    Subject vecptr;
    vecptr = subjects.at(subjects.size()-1);

    // Add the mapping of subject to security level
    subject_levels.insert({&temp, inst.getSec_level()});

    cout << "Subject Added : " << inst.getCommand_ref() << endl;
}

// Add an object to the vector of objects
void ReferenceMonitor::addObject(Instruction inst, vector<Object> &objects)
{
    Object temp(inst.getObject_name());
    objects.push_back(temp);

    // Add mapping of object to security level
    object_levels.insert({&temp, inst.getSec_level()});

    cout << "Object Added : " << inst.getCommand_ref() << endl;
}

// Execute a read of an object
// For BLPD, no read up is enforced - subject must be higher than object
void ReferenceMonitor::executeRead(Instruction inst, vector<Subject> &subjects, vector<Object> &objects)
{
    // Storage for applicable objects
    Subject *sub = NULL;
    Object *obj = NULL;
    security_level sub_level, obj_level;
    map<Object*, security_level>::iterator obj_iter;
    map<Subject*, security_level>::iterator sub_iter;

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

    // Look up our security levels from our map
    obj_iter = object_levels.find(obj);
    if (obj_iter != object_levels.end())
    {
        cout << "Found object!!\n";
    }
    else
    {
        cout << "Didn't work" << endl;
        cout << "trying to find " << sub << obj << endl;
    }
    sub_iter = subject_levels.find(sub);
    if (sub_iter != subject_levels.end())
    {
        cout << "Found subject\n";
    }


    /*  // Determine if our security level allows us to read the object
    if (sub->getSec_level() >= obj->getSec_level())
    {
        sub->READ(*obj);
        cout << "Access Granted : " << inst.getCommand_ref() << endl;
    }
    else
    {
        cout << "Access Denied : " << inst.getCommand_ref() << endl;

    }*/
}

// Execute a write on an object
// For BLPD, no write down is enforced
void ReferenceMonitor::executeWrite(Instruction inst, vector<Subject> &subjects, vector<Object> &objects)
{
    // Storage for applicable objects
    Subject *sub = NULL;
    Object *obj = NULL;
    security_level sub_level, obj_level;
    map<Object*, security_level>::iterator obj_iter;
    map<Subject*, security_level>::iterator sub_iter;


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


    // Look up our security levels from our map
    obj_iter = object_levels.find(obj);
    if (obj_iter != object_levels.end())
    {
        cout << "Found object!!\n";
        obj_level = obj_iter->second;
    }
    else
    {
        cout << "Didnt work\n";
    }
    sub_iter = subject_levels.find(sub);
    if (sub_iter != subject_levels.end())
    {
        cout << "Found subject\n";
        sub_level = sub_iter->second;
    }
    else
    {
        cout << "Didnt work\n";
    }

/*
    // Determine if our security level allows us to write to the object
    if (sub->getSec_level() <= obj->getSec_level())
    {
        sub->WRITE(*obj, inst.getValue());
        cout << "Access Granted : " << sub->getName() << " writes " << inst.getValue() << " to " << obj->getName() << endl;
    }
    else
    {
        cout << "Access Denied : " << inst.getCommand_ref() << endl;
    } */
}

// Evaluate and perform the operation in an instruction object
void ReferenceMonitor::evaluate(Instruction command, vector<Subject> &subjects, vector<Object> &objects)
{
    // Add a new subject
    if (command.getCommand() == "ADDSUB")
    {
        addSubject(command, subjects);
    }

    // Add an object
    else if (command.getCommand() == "ADDOBJ")
    {
        addObject(command, objects);
    }

    // Read an object
    else if (command.getCommand() == "READ")
    {
        executeRead(command, subjects, objects);
    }

    // Write to an object
    else if (command.getCommand() == "WRITE")
    {
        executeWrite(command, subjects, objects);
    }
}

// Print the stack of objects and subjects
void ReferenceMonitor::printState(vector<Subject> &subjects, vector<Object> &objects, int final)
{
    // Check if this is our final output
    if (final)
    {
        cout  << endl << "+" << string(4, '*') << "  Final State  " <<  string(4, '*') <<"+" << endl;
    }
    else
    {
        cout  << endl << "+" << string(4, '*') << " Current State " <<  string(4, '*') <<"+" << endl;
    }

    // Print the stack of subjects
    cout << "|---Subject------Temp---|" << endl;
    for (vector<Subject>::iterator it = subjects.begin(); it != subjects.end(); it++)
    {
        cout << left << "| " << it->getName() << " | " << setw(14) ;
        cout << right << setw(11) << it->getTemp() << " |" << endl;
    }

    // Print the stack of objects
    cout << "|---Object------Value---|" << endl;
    for (vector<Object>::iterator it = objects.begin(); it != objects.end(); it++)
    {
        cout << left << "| " << it->getName() << " | " << setw(14) ;
        cout << right << setw(11) << it->getValue() << " |" << endl;
    }
    cout << "+" << string(23, '-') << "+" << endl << endl;
}
