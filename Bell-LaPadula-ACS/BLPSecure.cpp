// Author: Tyler Cook
// Date: 10/15/2018
// Course: UNT CSCE 4550.001
// Description: This program is a simple implementation of Bell-LaPadula security model. It takes a file of text commands
// as input, parses the instructions line by line, and if the instruction is valid, passes it to a reference monitor which
// executes the command. Commands consist of add subject, add object, read, and write.

#include <iostream>
#include <fstream>
#include <vector>
#include "subject.h"
#include "instruction.h"
#include "referencemonitor.h"

using namespace std;

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
        cout << "Error: please provide a filename in the syntax ./" << argv[0] << " filename" << endl;
        return 1;
    }

    // Open the instructions file for reading
    instructions.open(argv[1], ifstream::in);
    if (!instructions)
    {
        cout << "Error opening file" << endl;
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
            monitor.printState(subjects, objects, 0);
            status_counter = 0;
        }
    }

    // Close file when we're done with it
    instructions.close();

    // Print final state before exiting
    monitor.printState(subjects, objects, 1);

    return 0;
}

