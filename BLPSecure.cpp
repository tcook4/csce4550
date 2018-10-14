// Author: Tyler Cook
// Date: 10/15/2018
// Course: UNT CSCE 4550.001
// Description: This program is a simple implementation of Bell-LaPadula security model. It takes a file of text commands
// as input and executes the commands as given.


#include <iostream>
#include <fstream>
#include <vector>
#include "subject.h"
#include "instruction.h"
#include "referencemonitor.h"

using namespace std;

void print_status(vector<Subject> &subjects, vector<Object> &objects);

int main(int argc, char *argv[])
{
    ifstream instructions; // File stream to read instructions file
    string line; // Line of input
    Instruction command;
    int status_counter = 0; // Used to track output lines and print status
    ReferenceMonitor monitor; // Monitor object which checks access and executes commands
    vector <Subject> subjects; // Collection of subjects loaded in the system
    vector <Object> objects; // Collection of objects loaded in the system

    int debug = 0;
    string dbg;
    // Verify we got a parameter to check
    if (argc != 2)
    {
        if (debug)
        {
            cout << "Enter a filename: ";
            cin >> dbg;
        }
        else
        {
            cout << "Error: please provide a filename in the syntax ./" << argv[0] << " filename\n";
            return 1;
        }
    }

    // Open the instructions file for reading
    if (debug)
    {
        instructions.open(dbg, ifstream::in);
    }
    else
    {
        instructions.open(argv[1], ifstream::in);
    }
    if (!instructions)
    {
        cout << "Error opening file";
        return 1;
    }

    // Process instructions file
    while (getline(instructions, line))
    {
        // Pass instruction to instruction object
        if (command.load(line))
        {
            monitor.evaluate(command, subjects, objects);
        }

        // Increment display counter and display if we've completed 10 instructions
        status_counter++;
        if (status_counter == 10)
        {
            print_status(subjects, objects);
            status_counter = 0;
        }
    }


    // Close file when we're done with it
    instructions.close();
    return 0;
}

// Print the stack of objects
void print_status(vector<Subject> &subjects, vector<Object> &objects)
{
    cout << "+ *** Current State *** +" << endl;
    cout << "|---Subject------Temp---|" << endl;
    for (vector<Subject>::iterator it = subjects.begin(); it != subjects.end(); ++it)
    {
        cout << "| " << it->getName() << " | " << it->getTemp() << " |" << endl;
    }

    cout << "|---Object-------Temp---|" << endl;
    for (vector<Object>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        cout << "| " << it->getName() << " | "  << it->getValue() << " |" << endl;
    }
    cout << "+-----------------------|" << endl;
}
