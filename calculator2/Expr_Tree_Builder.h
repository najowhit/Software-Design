/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:

	Expr_Tree_Builder(void);

	~Expr_Tree_Builder(void);

	void build_expression(void);   

	void build_number(int n);   

	void build_add_operator(void);

	void build_subtract_operator(void);

	void build_divide_operator(void);

	void build_mod_operator(void);

	void build_multiplication_operator(void);

	void build_close_parenthesis_operator(void);

	Expr_Node * get_expression(void);

	void check_precedence(Expr_Node * node);


private:

	Expr_Node * tree_;
	Stack <Expr_Node *> operand_stack_;
	Stack <Expr_Node *> operator_stack_;

};

#endif