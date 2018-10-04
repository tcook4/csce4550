// Author: Tyler Cook
// Date: 10/15/2018
// Course: UNT CSCE 4550.001
// Description: This program is a simple implementation of Bell-LaPadula security model. It takes a file of text commands
// as input and executes the commands as given.


#include <iostream>
#include <fstream>
#include "subject.h"
#include "instruction.h"
#include "referencemonitor.h"

using namespace std;

void print_status();

int main(int argc, char *argv[])
{
    ifstream instructions; // File stream to read instructions file
    string line; // Line of input
    Instruction command;
    int status_counter = 0; // Used to track output lines and print status

    // Verify we got a parameter to check
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
        command.load(line);


        // Increment display counter and display if we've completed 10 instructions
        status_counter++;
        if (status_counter == 10)
        {
            print_status();
            status_counter = 0;
        }
    }



    // Close file when we're done with it
    instructions.close();
    return 0;
}

// Print the stack of objects
void print_status()
{
    cout << "\nI am the status message!\n\n";
}
