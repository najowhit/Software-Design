/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _ADD_EXPR_NODE_H_
#define _ADD_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Add_Expr_Node : public Binary_Expr_Node
{
public:
	
	Add_Expr_Node(void);
	
	virtual ~Add_Expr_Node(void);
	
	void accept (Expr_Node_Visitor & v);

 	int get_priority(void);

};

#endif