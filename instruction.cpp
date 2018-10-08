#include "instruction.h"

Instruction::Instruction()
{
    command = "";
    object_name = "";
    subject_name = "";
    security_str = "";
    command_ref = "";
    value = 0;
}

void Instruction::clear()
{
    command = "";
    object_name = "";
    subject_name = "";
    security_str = "";
    command_ref = "";
    value = 0;
}

bool Instruction::load(string commandStr)
{
    stringstream ss; // Stringstream used to separate values
    clear(); // Clear any previous values

    // Load the stream with the line read from input
    ss << commandStr;
    ss >> command;

    // Convert the command to uppercase
    to_upper(command);

    // Check and perform command as given
    // Add Subject
    if (command == "ADDSUB")
    {
        ss >> subject_name >> security_str;
        to_upper(security_str);

        // Verify security level valid and stream is empty
        if ((!(security_str == "LOW" || security_str == "MEDIUM" || security_str == "HIGH")) || (!ss.eof()))
        {
            cout << "Bad Command: " << commandStr << endl;
            return false;
        }

        // Store the command for printing by reference monitor
        command_ref = command + " " + subject_name + " " + security_str;
    }

    // Add Object
    else if (command == "ADDOBJ")
    {
        ss >> object_name >> security_str;
        to_upper(security_str);

        // Verify security level valid and stream is empty
        if ((!(security_str == "LOW" || security_str == "MEDIUM" || security_str == "HIGH")) || (!ss.eof()))
        {
            cout << "Bad Command: " << commandStr << endl;
            return false;
        }

        // Store the command for printing by reference monitor
        command_ref = command + " " + object_name + " " + security_str;
    }

    // Read an object
    else if (command == "READ")
    {
        ss >> subject_name >> object_name;

        // Make sure nothing left in stream
        if (!ss.eof())
        {
            cout << "Bad Command: " << commandStr << endl;
            return false;
        }

        // Store the command for printing by reference monitor
        command_ref = command + " " + subject_name + " " + object_name;
    }

    // Write to an object
    else if (command == "WRITE")
    {
        ss >> subject_name >> object_name >> value;

        // TODO: CHeck that value is an int

        // Make sure nothing left in stream
        if (!ss.eof())
        {
            cout << "Bad Command: " << commandStr << endl;
            return false;
        }

        // Store the command for printing by reference monitor
        command_ref = command + " " + subject_name + " " + object_name + " " + to_string(value);
    }

    // If we get here, we have a bad command
    else
    {
        cout << "Bad Command: " << commandStr << endl;
        clear();
        return false;
    }
    return true;
}

// Convert string to uppercase
void Instruction::to_upper(string &str)
{
    for (int i = 0; str[i] != 0; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i]-=32;
        }
    }
}

// Set the security enum based on the string representation loaded
void Instruction::set_security(string sec)
{
    if (sec == "HIGH")
    {
        sec_level = HIGH;
    }
    else if (sec == "MEDIUM")
    {
        sec_level = MEDIUM;
    }
    else if (sec == "LOW")
    {
        sec_level = LOW;
    }
}

// Getters for reference monitor usage
string Instruction::getCommand() const
{
    return command;
}

string Instruction::getObject_name() const
{
    return object_name;
}

string Instruction::getSubject_name() const
{
    return subject_name;
}

security_level Instruction::getSec_level() const
{
    return sec_level;
}

string Instruction::getCommand_ref() const
{
    return command_ref;
}

