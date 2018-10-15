// Author: Tyler Cook
// Date: 10/15/2018
// Course: UNT CSCE 4550.001
// Description: This program is a simple implementation of Bell-LaPadula security model. It takes a file of text commands
// as input, parses the instructions line by line, and if the instruction is valid, passes it to a reference monitor which
// executes the command. Commands consist of add subject, add object, read, and write.

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "subject.h"
#include "instruction.h"
#include "referencemonitor.h"

using namespace std;

void print_status(vector<Subject> &subjects, vector<Object> &objects, int final);

int main(int argc, char *argv[])
{
    ifstream instructions;          // File stream to read instructions file
    string line;                    // Line of input
    Instruction command;            // Parsed instruction passed to reference monitor to execute
    int status_counter = 0;         // Used to track output lines and print status
    ReferenceMonitor monitor;       // Monitor object which checks access and executes commands
    vector <Subject> subjects;      // Collection of subjects loaded in the system
    vector <Object> objects;        // Collection of objects loaded in the system

    // Verify we got a filename in command line arguments
    if (argc != 2)
    {
        cout << "Error: please provide a filename in the syntax ./" << argv[0] << " filename\n";
        return 1;
    }

    // Open the instructions file for reading
    instructions.open(argv[1], ifstream::in);
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
            // If command is valid, pass to reference monitor
            monitor.evaluate(command, subjects, objects);
        }

        // Increment display counter and display if we've completed 10 instructions
        status_counter++;
        if (status_counter == 10)
        {
            print_status(subjects, objects, 0);
            status_counter = 0;
        }
    }

    // Close file when we're done with it
    instructions.close();

    // Print final state before exiting
    print_status(subjects, objects, 1);

    return 0;
}

// Print the stack of objects and subjects
void print_status(vector<Subject> &subjects, vector<Object> &objects, int final)
{
    // Check if this is our final output
    if (final)
    {
        cout  << "+" << string(4, '*') << "  Final State  " <<  string(4, '*') <<"+" << endl;
    }
    else
    {
        cout  << "+" << string(4, '*') << " Current State " <<  string(4, '*') <<"+" << endl;
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
    cout << "+" << string(23, '-') << "+" << endl;
}
