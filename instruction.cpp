#include "instruction.h"

Instruction::Instruction()
{
    command = "";
    object_name = "";
    subject_name = "";
    security_level = 0;
}

void Instruction::clear()
{
    command = "";
    object_name = "";
    subject_name = "";
    security_level = 0;
}

void Instruction::load(string commandStr)
{
    string operation; // The operation we're performing
    string subject; // The subject of the operation
    string object; // The object of the operation
    string value; // the value of the write operation

    stringstream ss; // Stringstream used to separate values

    // Load the stream with the line read from input
    ss << commandStr;
    ss >> operation;

    // Convert to uppercase
    //to_upper(operation);

    if (operation.compare("addsub"))
    {
        cout << "In addsub\n";
    }
    else if (operation.compare("addobj"))
    {
        cout << "In addobj\n";

    }
    else if (operation.compare("read"))
    {
        cout << "In read\n";
    }
    else if (operation.compare("write"))
    {
        cout << "In write\n";
        ss >> subject >> object >> value;
        cout << "For write, got operation:" << operation << " subject " << subject << " object " << object << " and value " << value << endl;
    }
    else
    {
        cout << "Error: Bad Command\n";
    }

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

