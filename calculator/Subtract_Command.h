/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

class Subtract_Command : public Binary_Op_Command
{
public:

    Subtract_Command(void);

    ~Subtract_Command(void);

    int evaluate (int n1, int n2);



};


#endif

