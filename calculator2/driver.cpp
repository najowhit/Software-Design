/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Calculator.h"
#include "Expr_Node.h"
#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{
    int result;
    string user_input;

    Calculator calculate;

    bool keepGoing = true;
    while(keepGoing)
    {
    	cout << "Enter an expression: ";
        getline(cin,user_input);

        if (user_input == "QUIT" || user_input == "quit")
        {
            keepGoing = false;
            return 0;
        }

        calculate.evaluate_expr(user_input);
	}

}