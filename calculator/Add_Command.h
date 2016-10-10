/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

// Nathan, the +, -, /, %, * commands should have a proper way to handle precedence. Please handle this in all of them.
/**
* I created a precedence class that returns all of the precedence values for the operators.
*/
class Add_Command : public Binary_Op_Command
{
public:

    Add_Command(void);

    ~Add_Command(void);

    int evaluate (int n1, int n2);

};

#endif
