/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Number_Command.h"


Number_Command::Number_Command(int n)
: n_ (n)
{

}

Number_Command::~Number_Command(void)
{

}

bool Number_Command::execute(Stack <int> & s)
{
    s.push (this->n_);
    return true;
}


