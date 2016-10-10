/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _NUMBER_EXPR_NODE_H_
#define _NUMBER_EXPR_NODE_H_

#include "Expr_Node.h"

class Number_Expr_Node : public Expr_Node  
{
public:
	
	Number_Expr_Node(void);

	Number_Expr_Node(int n);

    ~Number_Expr_Node(void);

    int eval(void);

    void accept(Expr_Node_Visitor & v);

    int get_priority(void);

private:
    int n_;

};

#endif