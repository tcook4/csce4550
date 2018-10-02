#include <iostream>
#include <fstream>
#include "subject.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream instructions; // File stream to read instructions file
    string line; // Line of input

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




        cout << "Bad instruction found" << endl;
    }






    instructions.close();
    return 0;
}

