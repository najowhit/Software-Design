/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Expr_Command
{
public:

    Binary_Op_Command(void);

    virtual ~Binary_Op_Command(void);

    bool execute (Stack <int> & s);

    virtual int evaluate(int n1, int n2) = 0;

};

#endif
