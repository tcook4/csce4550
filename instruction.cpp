#include "instruction.h"

Instruction::Instruction()
{
    command = "";
    object_name = "";
    subject_name = "";
    security_level = "";
    value = 0;
}

void Instruction::clear()
{
    command = "";
    object_name = "";
    subject_name = "";
    security_level = "";
    value = 0;
}

bool Instruction::load(string commandStr)
{
    stringstream ss; // Stringstream used to separate values

    cout << "Command str is : " << commandStr << endl;

    // Load the stream with the line read from input
    ss << commandStr;
    ss >> command;

    // Convert to uppercase
    to_upper(command
             );

    // Check and perform command as given
    // Add Subject
    if (command.compare("addsub"))
    {
        ss >> subject_name >> security_level;

        // Verify command is valid




        cout << "Subject Added: " << command << " " << subject_name << " " << security_level << endl;
    }

    // Add Object
    else if (command.compare("addobj"))
    {
        ss >> object_name >> security_level;
        cout << "Object Added: " << command << " " << object_name << " " << security_level << endl;
    }

    // Read an object
    else if (command.compare("read"))
    {
        cout << "In read\n";
        ss >> subject_name >> object_name;
        cout << "Object Added: " << command << " " << object_name << " " << security_level << endl;
    }

    // Write to an object
    else if (command.compare("write"))
    {
        ss >> subject_name >> object_name >> value;
    }
    else
    {
        cout << "Bad Command: " << commandStr << endl;
        clear();
        return false;
    }
    return true;
}

// Convert string to uppercase
// TODO: might not need this
void Instruction::to_upper(string &str)
{
    for (int i = 0; str[i] != 0; i++)
    {
        if(str[i] <= 'z' && str[i] >= 'a')
        {
            str[i]-=32;
        }
    }
}

