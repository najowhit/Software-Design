/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Add_Expr_Node.h"

Add_Expr_Node::Add_Expr_Node(void)
{

}
	
Add_Expr_Node::~Add_Expr_Node(void)
{

}

void Add_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Addition_Node (*this);
}

/**
* Priority value according to Shunting Yard Algorithm
*/
int Add_Expr_Node::get_priority(void)
{
	return 2;
}
