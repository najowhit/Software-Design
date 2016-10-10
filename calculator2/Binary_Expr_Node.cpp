/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Binary_Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node(void)
: right_(0),
  left_(0)
{

}

Binary_Expr_Node::~Binary_Expr_Node(void)
{
	delete left_;
	delete right_;
}

void Binary_Expr_Node::set_left(Expr_Node * node)
{
	this->left_ = node; 
}
    
void Binary_Expr_Node::set_right(Expr_Node * node)
{
	this->right_ = node;
}
	
Expr_Node & Binary_Expr_Node::get_left(void)
{
	return *this->left_;
}

Expr_Node & Binary_Expr_Node::get_right(void)
{
	return *this->right_;
}
