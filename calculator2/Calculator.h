/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include "Expr_Builder.h"

#include <iostream>
#include <string>
#include <sstream>

class Calculator
{
public:

	Calculator(void);
    
    ~Calculator(void);
    
    bool parse_expr (const std::string & infix, Expr_Builder &b);
    
    bool evaluate_expr(const std::string &infix);

};

#endif