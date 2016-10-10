/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Number_Expr_Node.h"

Number_Expr_Node::Number_Expr_Node(void)
: n_(0)
{

}

Number_Expr_Node::Number_Expr_Node(int n)
: n_(n)
{

}

Number_Expr_Node::~Number_Expr_Node(void)
{

}

int Number_Expr_Node::eval(void)
{
	return this->n_;
} 

void Number_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Number_Node(*this);
}

int Number_Expr_Node::get_priority(void)
{
	return 0;
}