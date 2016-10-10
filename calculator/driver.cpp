/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Array.h"
#include "Convert_Infix_To_Postfix.h"
#include "Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "Stack_Expr_Command_Factory.h"

#include <iostream>
#include <algorithm>

using namespace std;

int main (int argc, const char * argv[])
{
    int result;
    string user_input;

    Convert_Infix_To_Postfix commandObj;

    bool keepGoing = true;
    while(keepGoing)
    {
        Stack_Expr_Command_Factory factory;

        cout << "Enter an expression: ";
        getline(cin,user_input);
        string temp_input = user_input;

        if (user_input == "QUIT")
        {
            keepGoing = false;
            return 0;
        }

        temp_input.erase(remove(temp_input.begin(),temp_input.end(),' '),temp_input.end());
        Array <Expr_Command *> postfix(temp_input.size());

        if (commandObj.infix_to_postfix(user_input, factory, postfix))
        {
            Expr_Iterator<Expr_Command *> iter(postfix);
            commandObj.evaluate_postfix(iter, result);
            cout << "Result: "<< result << endl;
        }

    }

    return 0;
}
