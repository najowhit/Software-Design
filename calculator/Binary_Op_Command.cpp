/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Binary_Op_Command.h"
#include <iostream>


Binary_Op_Command::Binary_Op_Command(void)
{

}

Binary_Op_Command::~Binary_Op_Command(void)
{

}

/**
* All binary operations will go through the same operations of
* push-pop push-pop. The evaluate method is a virtual method that
* each command will implement specefic to what the operator is.
*/
bool Binary_Op_Command::execute(Stack <int> & s)
{
    int n2 = s.top();
    s.pop();
    int n1 = s.top ();
    s.pop();

    int result = this->evaluate (n1, n2);
    s.push (result);

    return true;
}
