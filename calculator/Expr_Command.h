/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack.h"

class Expr_Command
{
public:

    Expr_Command(void);

    virtual ~Expr_Command (void);

    virtual bool execute (Stack <int> & s) = 0;

};


#endif
