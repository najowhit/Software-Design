/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Multiplication_Expr_Node.h"

Multiplication_Expr_Node::Multiplication_Expr_Node(void)
{

}
	
Multiplication_Expr_Node::~Multiplication_Expr_Node(void)
{

}

void Multiplication_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Multiplication_Node(*this);
}

/**
* Priority value according to Shunting Yard Algorithm
*/
int Multiplication_Expr_Node::get_priority(void)
{
	return 3;
}