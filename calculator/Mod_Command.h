/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Binary_Op_Command.h"

class Mod_Command : public Binary_Op_Command
{
public:

    Mod_Command(void);

    ~Mod_Command(void);

    int evaluate (int n1, int n2);


};


#endif
