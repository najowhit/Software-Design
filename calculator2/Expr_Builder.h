/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include "Binary_Expr_Node.h"
#include "Number_Expr_Node.h"

class Expr_Builder 
{
public:

	Expr_Builder(void);

	virtual ~Expr_Builder(void);

	virtual void build_expression(void) = 0;   

	virtual void build_number(int n) = 0;   

	virtual void build_add_operator(void) = 0;

	virtual void build_subtract_operator(void) = 0;

	virtual void build_divide_operator(void) = 0;

	virtual void build_mod_operator(void) = 0;

	virtual void build_multiplication_operator(void) = 0;

	virtual void build_close_parenthesis_operator(void) = 0;

	virtual Expr_Node * get_expression(void) = 0;

	virtual void check_precedence(Expr_Node * node) = 0;


};

#endif