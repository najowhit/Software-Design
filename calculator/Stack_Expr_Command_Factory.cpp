/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Stack_Expr_Command_Factory.h"


Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(void)
{

}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(void)
{

}

Number_Command * Stack_Expr_Command_Factory::create_number_command(int number)
{
    return new Number_Command(number);
}

Add_Command * Stack_Expr_Command_Factory::create_add_command(void)
{
    return new Add_Command();
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command(void)
{
    return new Subtract_Command();
}

Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command(void)
{
    return new Multiply_Command();
}

Divide_Command * Stack_Expr_Command_Factory::create_divide_command(void)
{
    return new Divide_Command();
}

Mod_Command * Stack_Expr_Command_Factory::create_mod_command(void)
{
    return new Mod_Command();
}

Parenthesis_Command * Stack_Expr_Command_Factory::create_parenthesis_command(void)
{
    return new Parenthesis_Command();
}

