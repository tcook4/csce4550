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

