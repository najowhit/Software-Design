/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _DIVIDE_EXPR_NODE_H_
#define _DIVIDE_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Divide_Expr_Node : public Binary_Expr_Node
{
public:
	
	Divide_Expr_Node(void);
	
	virtual ~Divide_Expr_Node(void);
	
	void accept (Expr_Node_Visitor & v);

 	int get_priority(void);

};

#endif