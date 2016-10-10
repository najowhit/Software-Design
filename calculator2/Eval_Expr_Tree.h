/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"
#include "Number_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Multiplication_Expr_Node.h"

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:

	Eval_Expr_Tree(void);

	virtual ~Eval_Expr_Tree(void);
	
	void Visit_Number_Node(Number_Expr_Node & node);

	void Visit_Addition_Node(Add_Expr_Node & node);

	void Visit_Subtraction_Node(Subtract_Expr_Node & node);

	void Visit_Division_Node(Divide_Expr_Node & node);

	void Visit_Modulus_Node(Mod_Expr_Node & node);

	void Visit_Multiplication_Node(Multiplication_Expr_Node & node);

	int result(void);

private:

	int result_;
};

#endif