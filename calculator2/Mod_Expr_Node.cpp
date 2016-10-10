/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Mod_Expr_Node.h"

Mod_Expr_Node::Mod_Expr_Node(void)
{

}
	
Mod_Expr_Node::~Mod_Expr_Node(void)
{

}

void Mod_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Modulus_Node (*this);
}

/**
* Priority value according to Shunting Yard Algorithm
*/
int Mod_Expr_Node::get_priority(void)
{
	return 3;
}