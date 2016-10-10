/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _MOD_EXPR_NODE_H_
#define _MOD_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Mod_Expr_Node : public Binary_Expr_Node
{
public:
	
	Mod_Expr_Node(void);
	
	virtual ~Mod_Expr_Node(void);
	
 	void accept(Expr_Node_Visitor & v);

 	int get_priority(void);

};

#endif