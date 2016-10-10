/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node  
{
public:
	
	Binary_Expr_Node(void);
	
	virtual ~Binary_Expr_Node(void);

	void set_left(Expr_Node * node);
    
    void set_right(Expr_Node * node);

	Expr_Node & get_right(void);

    Expr_Node & get_left(void);

	virtual void accept (Expr_Node_Visitor & v) = 0;

	virtual int get_priority(void) = 0;

protected:
	Expr_Node * right_;
  	Expr_Node * left_;

};

#endif