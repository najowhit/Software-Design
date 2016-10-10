/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _SUBTRACT_EXPR_NODE_H_
#define _SUBTRACT_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Subtract_Expr_Node : public Binary_Expr_Node
{
public:
	
	Subtract_Expr_Node(void);
	
	virtual ~Subtract_Expr_Node(void);
	
	void accept (Expr_Node_Visitor & v);

 	int get_priority(void);

};

#endif