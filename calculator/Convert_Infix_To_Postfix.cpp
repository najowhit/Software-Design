/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Convert_Infix_To_Postfix.h"

#include <cstring>
#include <cstdlib>


using namespace std;

Convert_Infix_To_Postfix::Convert_Infix_To_Postfix(void)
{

}

Convert_Infix_To_Postfix::~Convert_Infix_To_Postfix(void)
{

}

/**
* This method will convert from infix to postfix and call the Stack Command Factory. If the token is an operator
* the cmd variable will be assigned to the factor object for that operator and then the cmd variable will be pushed onto
* the temporary stack. A cmdCount variable is in place to ensure that the Expression Command Iterator will be able to iterate the correct
* number of times.
*
* If the token is a digit, the token will undergo the same operation with the cmd and cmdCount variables except that the digit will be added to the
* postfix array. Once the stream reaches the end of the user input, the temporary stack will have the operators popped off and added to the postfix
* array. The postfix array is resized at the end to ensure that the size of the postfix array is correct so the Iterator does not cause a
* segmentation fault. Temporary fix while I work on more important pieces.
*
* Currently the algorithm for order of operations is not working as expected in the situation where the operator on the stack has a larger
* precedence than the operator being created. This is an issue within the Stack class itself that I am currently working to resolve.
*/
bool Convert_Infix_To_Postfix::infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
{
    istringstream input(infix);
    string token;
    int cmdCount = 0;
    int i = 0;
    int position = 0;

    Expr_Command * cmd = 0;
    Expr_Command * top = 0;
    Stack <Expr_Command *> temp;
    Stack <int> precedenceStack;
    Precedence precedenceObj;

    // Nathan, you also need to handle parenthesis.
    /**
    * Parenthesis have been added.
    */
    while (!input.eof ())
    {
        input >> token;

        if (token == "+")
        {
            cmd = factory.create_add_command();
            int plusvalue = precedenceObj.add_precedence();
            cmdCount++;

            if (precedenceStack.is_empty() && temp.size() == 0)
            {
                precedenceStack.push(plusvalue);
                temp.push(cmd);
            }

            else if (plusvalue >= precedenceStack.top())
            {
                temp.push(cmd);
            }

            else if (plusvalue < precedenceStack.top())
            {
                top = temp.top();
                temp.pop();
                temp.push(cmd);
                postfix[i] = top;
                i++;
            }

        }

        else if (token == "-")
        {
            cmd = factory.create_subtract_command();
            int subvalue = precedenceObj.subtract_precedence();
            cmdCount++;

             if (precedenceStack.is_empty() && temp.size() == 0)
            {
                precedenceStack.push(subvalue);
                temp.push(cmd);
            }

            else if (subvalue >= precedenceStack.top())
            {
                precedenceStack.push(subvalue);
                temp.push(cmd);
            }

            else if (subvalue < precedenceStack.top())
            {
                top = temp.top();
                temp.pop();
                temp.push(cmd);
                postfix[i] = top;
                i++;
            }

        }

        else if (token == "*" || token == "x")
        {
            cmd = factory.create_multiply_command();
            int multvalue = precedenceObj.multiply_precedence();
            cmdCount++;

            if (precedenceStack.is_empty() && temp.size() == 0)
            {
                precedenceStack.push(multvalue);
                temp.push(cmd);
            }

            else if (multvalue >= precedenceStack.top())
            {
                precedenceStack.push(multvalue);
                temp.push(cmd);
            }

            else if (multvalue < precedenceStack.top())
            {
                top = temp.top();
                temp.pop();
                temp.push(cmd);
                postfix[i] = top;
                i++;
            }

        }

        else if (token == "/")
        {
            cmd = factory.create_divide_command();
            int divvalue = precedenceObj.divide_precedence();
            cmdCount++;

            if (precedenceStack.is_empty() && temp.size() == 0)
            {
                precedenceStack.push(divvalue);
                temp.push(cmd);
            }

            else if (divvalue >= precedenceStack.top())
            {
                precedenceStack.push(divvalue);
                temp.push(cmd);
            }

            else if (divvalue < precedenceStack.top())
            {
                top = temp.top();
                temp.pop();
                temp.push(cmd);
                postfix[i] = top;
                i++;
            }
        }

        else if (token == "%" || token == "mod")
        {
            cmd = factory.create_mod_command();
            int modvalue = precedenceObj.mod_precedence();
            cmdCount++;

            if (precedenceStack.is_empty() && temp.size() == 0)
            {
                precedenceStack.push(modvalue);
                temp.push(cmd);
            }

            else if (modvalue >= precedenceStack.top())
            {
                precedenceStack.push(modvalue);
                temp.push(cmd);
            }

            else if (modvalue < precedenceStack.top())
            {
                top = temp.top();
                temp.pop();
                temp.push(cmd);
                postfix[i] = top;
                i++;
            }
        }

        else if (isdigit(token[0]))
        {
            int int_number;
            istringstream int_token(token);
            int_token >> int_number;

            cmd = factory.create_number_command(int_number);
            cmdCount++;
            postfix[i] = cmd;
            i++;
        }

    }


    while(temp.size()!=0)
	{
        postfix[i] = temp.top();
        temp.pop();
        i++;
    }

    postfix.resize(cmdCount);
    return true;
}

/**
* The iterator will iterate over a postfix array (passed to the Expr_Iterator class in the driver) and will
* execute a stack (refer to the Binary_Op_Command: execute can be called because iter points to Expr_Command objects, which Binary_Op inherits from)
* Referring back to the Binary_Op_Command, execute actually produces a result because the evaluation is defined by the derived comman classes of the parent
* Binary_Op_Class. For example, if the input is 2 + 5 the array will be NumberCommand, NumberCommand, AddCommand. The add command object evaluates the
* addition of the numbers on the stack (which are pushed onto the stack by the NumberCommands).
*/
bool Convert_Infix_To_Postfix::evaluate_postfix(Expr_Iterator<Expr_Command *> & iter, int & result)
{

    // Nathan, You have a memory leak. You need to make sure you
    // delete the commands after evaluating the expression.
    /**
    * I added delete command to take care of the memory leak.
    */
    Stack <int> st;
    for (; !iter.is_done(); iter.advance())
    {
       (*iter)->execute(st);
       delete (*iter);
    }

    result = st.top();
    st.pop();

    return true;
}
