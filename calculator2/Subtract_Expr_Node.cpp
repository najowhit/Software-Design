/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Subtract_Expr_Node.h"

Subtract_Expr_Node::Subtract_Expr_Node(void)
{

}
	
Subtract_Expr_Node::~Subtract_Expr_Node(void)
{

}

void Subtract_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Subtraction_Node (*this);
}

/**
* Priority value according to Shunting Yard Algorithm
*/
int Subtract_Expr_Node::get_priority(void)
{
	return 2;
}