/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Calculator.h"
#include "Eval_Expr_Tree.h"
#include "Expr_Tree_Builder.h"

#include <cstring>
#include <cstdlib>


using namespace std;

Calculator::Calculator(void)
{

}
    
Calculator::~Calculator(void)
{

}
    
bool Calculator::parse_expr(const std::string & infix, Expr_Builder &b)
{
	
	istringstream input (infix);
	string token; 
		
	while (!input.eof ()) 
	{      
		input >> token;        
		
		if (token == "+")
		{ 
			b.build_add_operator();
		}

		else if (token == "-")
		{
			b.build_subtract_operator();
		}

		else if (token == "/")
		{
			b.build_divide_operator();
		}

		else if (token == "%" || token == "mod")
		{
			b.build_mod_operator();
		}

		else if (token == "*")
		{
			b.build_multiplication_operator();
		}

		else if (token == ")")
		{
			b.build_close_parenthesis_operator();
		}

        else if (isdigit(token[0]))
        {
            int int_number;
            istringstream int_token(token);
            int_token >> int_number;

            b.build_number(int_number);
        }

	}

	b.build_expression();

	return true;
}
    
bool Calculator::evaluate_expr(const std::string &infix)
{
	Expr_Tree_Builder builder;   
	Eval_Expr_Tree visitor;

	if (!this->parse_expr (infix, builder))
	{    
		return false;
	}

  	Expr_Node * expr = builder.get_expression();

	if (0 == expr) 
  	{    
  		return false;
  	}
  
	expr->accept(visitor); 
	int result = visitor.result();

	cout << "Result: " << result << endl; 

	delete expr;

  	return true;
}





