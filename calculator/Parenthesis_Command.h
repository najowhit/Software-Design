/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include "Binary_Op_Command.h"

class Parenthesis_Command : public Binary_Op_Command
{
public:

    Parenthesis_Command(void);

    ~Parenthesis_Command(void);

    int evaluate (int n1, int n2);


};


#endif

