/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"

class Number_Command : public Expr_Command
{
public:

    Number_Command (int n);

    ~Number_Command (void);

    bool execute (Stack <int> & s);

private:
    int n_;

};




#endif
