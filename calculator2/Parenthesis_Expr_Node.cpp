/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Parenthesis_Expr_Node.h"

Parenthesis_Expr_Node::Parenthesis_Expr_Node(void)
{

}

Parenthesis_Expr_Node::~Parenthesis_Expr_Node(void)
{

}

void Parenthesis_Expr_Node::accept(Expr_Node_Visitor & v)
{

}

int Parenthesis_Expr_Node::get_priority(void)
{
	return 5;
}