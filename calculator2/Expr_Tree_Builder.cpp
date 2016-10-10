/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"
#include "Number_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Multiplication_Expr_Node.h"

// Comment: You need to build a tree with all the supported operations, and also
// handle parenthesis.
/**
* I added support for all operations and parenthesis
*/
Expr_Tree_Builder::Expr_Tree_Builder(void)
: tree_(0)
{

}

Expr_Tree_Builder::~Expr_Tree_Builder(void)
{

}

/**
* To build the mathematical expression, we need to set an Binary_Expression node (+ , - , * , etc.) as the root
* and then set the top of the operand stack (the last number entered by the user) as the right child, and then the next
* Number_Expr_Node on the stack as the left node. Then root of the expression will accept the visitor. 

* If the operator and operand stacks are the same size, there is an empty node. The previously evaluated expression
* will be pushed to the stack.
*/

// Comment: The name of this method is misleading because, you are calling it at the end from your calculator.
/**
* I changed the name of this method to "build_expression" as that is a more accurate description of the method's role in the 
* program
*/
void Expr_Tree_Builder::build_expression(void)
{
	Eval_Expr_Tree evaluate_tree;
	
	while (operand_stack_.size() != 0)
	{
		Binary_Expr_Node * expression = (Binary_Expr_Node*) operator_stack_.top();
		
		this->operator_stack_.pop();
    	expression->set_right(this->operand_stack_.top());
        this->operand_stack_.pop();

        if (operand_stack_.size() == operator_stack_.size())
		{
			operand_stack_.push(tree_);
		}

		expression->set_left(this->operand_stack_.top());
       	this->operand_stack_.pop();
     
		 // Comment: The accept method should be called from the visitor and not the builder.
       	/*
       	* I removed the statement "expression->accept(evaluate_tree);" as it did not belong in the builder.
       	*/
		
		tree_ = expression;
	}
	
}

void Expr_Tree_Builder::build_number(int n)
{
	Expr_Node * node = new Number_Expr_Node(n);
	operand_stack_.push(node);
}  

/**
* Once precedence is implemented, this method will need to adjust and the operator_stack_ will not have
* the node pushed in the build method(s)
*/
void Expr_Tree_Builder::build_add_operator(void)
{
	Expr_Node * node = new Add_Expr_Node();
	check_precedence(node);
}

void Expr_Tree_Builder::build_subtract_operator(void)
{
	Expr_Node * node = new Subtract_Expr_Node();
	check_precedence(node);
}

void Expr_Tree_Builder::build_divide_operator(void)
{
	Expr_Node * node = new Divide_Expr_Node();
	check_precedence(node);
}

void Expr_Tree_Builder::build_mod_operator(void)
{
	Expr_Node * node = new Mod_Expr_Node();
	check_precedence(node);
}

void Expr_Tree_Builder::build_multiplication_operator(void)
{
	Expr_Node * node = new Multiplication_Expr_Node();
	check_precedence(node);
}

void Expr_Tree_Builder::build_close_parenthesis_operator(void)
{
	build_expression();
}

/**
* This method will return the expression to be evaluated in the Calculator class.
*/
Expr_Node * Expr_Tree_Builder::get_expression (void)
{
	return this->tree_;
}

void Expr_Tree_Builder::check_precedence(Expr_Node * node)
{
	if(operator_stack_.is_empty())
	{
		operator_stack_.push(node);
	}

	else if(node->get_priority() > operator_stack_.top()->get_priority())
	{
		operator_stack_.push(node);
	}

	else if(node->get_priority() <= operator_stack_.top()->get_priority())
	{
		build_expression();
		operator_stack_.push(node);
	}

}





