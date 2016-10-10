/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

class Number_Expr_Node;
class Add_Expr_Node;
class Subtract_Expr_Node;
class Divide_Expr_Node;
class Mod_Expr_Node;
class Multiplication_Expr_Node;

class Expr_Node_Visitor
{
public:

	Expr_Node_Visitor(void);
	
	virtual ~Expr_Node_Visitor (void);

	virtual void Visit_Number_Node(Number_Expr_Node & node) = 0;

	virtual void Visit_Addition_Node(Add_Expr_Node & node) = 0;

	virtual void Visit_Subtraction_Node(Subtract_Expr_Node & node) = 0;

	virtual void Visit_Division_Node(Divide_Expr_Node & node) = 0;

	virtual void Visit_Modulus_Node(Mod_Expr_Node & node) = 0;

	virtual void Visit_Multiplication_Node(Multiplication_Expr_Node & node) = 0;

};

#endif