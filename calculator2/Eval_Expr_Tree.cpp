/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Eval_Expr_Tree.h"
#include <iostream>
#include <exception>

Eval_Expr_Tree::Eval_Expr_Tree(void)
: result_(0)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree(void)
{

}
	
void Eval_Expr_Tree::Visit_Number_Node(Number_Expr_Node & node)
{
	result_ = node.eval();
}

void Eval_Expr_Tree::Visit_Addition_Node(Add_Expr_Node & node)
{
	node.get_left().accept(*this);
	int left_result = this->result_;

	node.get_right().accept(*this);
	int right_result = this->result_;

	this->result_ = left_result + right_result;
}

void Eval_Expr_Tree::Visit_Subtraction_Node(Subtract_Expr_Node & node)
{
	node.get_left().accept(*this);
	int left_result = this->result_;

	node.get_right().accept(*this);
	int right_result = this->result_;

	this->result_ = left_result - right_result;
}

void Eval_Expr_Tree::Visit_Division_Node(Divide_Expr_Node & node)
{
	node.get_left().accept(*this);
	int left_result = this->result_;

	node.get_right().accept(*this);
	int right_result = this->result_;

	try
	{
		if(right_result == 0)
		{
			throw std::exception();
		}

		this->result_ = left_result / right_result;
	}

	catch(std::exception &e)
	{
		std::cerr << "Error: Division by 0" << std::endl;
	}

}

void Eval_Expr_Tree::Visit_Modulus_Node(Mod_Expr_Node & node)
{
	node.get_left().accept(*this);
	int left_result = this->result_;

	node.get_right().accept(*this);
	int right_result = this->result_;

	try
	{
		if(right_result == 0)
		{
			throw std::exception();
		}

		this->result_ = left_result % right_result;
	}

	catch(std::exception &e)
	{
		std::cerr << "Error: Divison by 0" << std::endl;
	}

}

void Eval_Expr_Tree::Visit_Multiplication_Node(Multiplication_Expr_Node & node)
{
	node.get_left().accept(*this);
	int left_result = this->result_;

	node.get_right().accept(*this);
	int right_result = this->result_;

	this->result_ = left_result * right_result;	
}


int Eval_Expr_Tree::result(void)
{
	return result_;
}