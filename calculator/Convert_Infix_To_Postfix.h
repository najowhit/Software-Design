/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _CONVERT_INFIX_TO_POSTFIX_H_
#define _CONVERT_INFIX_TO_POSTFIX_H_

#include "Expr_Command.h"
#include "Expr_Command_Factory.h"
#include "Expr_Iterator.h"
#include "Precedence.h"

#include <iostream>
#include <string>
#include <sstream>

class Convert_Infix_To_Postfix
{
public:

    Convert_Infix_To_Postfix(void);

    ~Convert_Infix_To_Postfix(void);

    bool infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);

    bool evaluate_postfix (Expr_Iterator<Expr_Command *> & iter, int & result);

   // void compare_precedence(Stack <Expr_Command *> temp, Expr_Command * cmd);

};

#endif
