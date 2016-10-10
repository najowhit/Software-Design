/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Divide_Expr_Node.h"

Divide_Expr_Node::Divide_Expr_Node(void)
{

}
	
Divide_Expr_Node::~Divide_Expr_Node(void)
{

}

void Divide_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Division_Node (*this);
}

/**
* Priority value according to Shunting Yard Algorithm
*/
int Divide_Expr_Node::get_priority(void)
{
	return 3;
}