/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Divide_Command.h"
#include <exception>

Divide_Command::Divide_Command(void)
{

}

Divide_Command::~Divide_Command(void)
{

}


/**
* Exception is thrown due to divison by zero.
*/
int Divide_Command::evaluate(int n1, int n2)
{
    if (n2 == 0)
    {
        throw std::exception();
    }

    else
    {
        return n1 / n2;
    }

}


