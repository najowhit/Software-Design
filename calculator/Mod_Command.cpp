/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Mod_Command.h"


Mod_Command::Mod_Command(void)
{

}

Mod_Command::~Mod_Command(void)
{

}


// Nathan, your code will break if there is a divide by zero.
/**
* I threw an exception if the second number was equal to zero
*/
int Mod_Command::evaluate(int n1, int n2)
{
    if (n2 == 0)
    {
        throw std::exception();
    }

    else
    {
        return n1 % n2;
    }
}

