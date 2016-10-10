/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"

class Divide_Command : public Binary_Op_Command
{
public:

    Divide_Command(void);

    ~Divide_Command(void);

    int evaluate (int n1, int n2);

};


#endif
