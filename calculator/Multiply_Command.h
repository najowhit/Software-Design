/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command
{
public:

    Multiply_Command(void);

    ~Multiply_Command(void);

    int evaluate (int n1, int n2);


};


#endif
