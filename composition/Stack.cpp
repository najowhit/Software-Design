// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>


// Nathan, make sure you are calling the constructor coorectly. Array<T> is not required.
/**
* I removed the Array<T>, as well as the maxstack_ variable as it was redundant.
*/
template <typename T>
Stack <T>::Stack (void)
: stackarray(20),
  topofstack_(0)
{

}


template <typename T>
Stack <T>::Stack (const Stack & stack)
: stackarray(stack.stackarray),
  topofstack_(stack.topofstack_)
{

}


/**
* No data has been allocated on the heap by the Stack class.
*/
template <typename T>
Stack <T>::~Stack (void)
{

}


/**
* The stack should not have to resize each time an element is pushed to the top.
* This will be achieved by initializing the array object to 50. If the stack has
* more than 50 items, then the stack will be resized to the current maxstack_ * 2.
*/
template <typename T>
void Stack <T>::push (T element)
{
    int resizeMulti = 2;

    if (topofstack_ > stackarray.size())
    {
        stackarray.resize(stackarray.size() * resizeMulti);
        stackarray.set(topofstack_, element);
        topofstack_++;
    }

    else if (topofstack_ == stackarray.size())
    {
        stackarray.resize(stackarray.size() * resizeMulti);
        stackarray.set(topofstack_, element);
        topofstack_++;
    }

    else if (topofstack_ < stackarray.size())
    {
        stackarray.set(topofstack_, element);
        topofstack_++;
    }
}


template <typename T>
void Stack <T>::pop (void)
{
    if (topofstack_ == 0 )
    {
        throw empty_exception();
    }

    else
    {
        topofstack_--;
       // stackarray.resize(topofstack_);
    }
}


// Nathan, you should always check for self assignment first.
/**
* I check for self assignment by creating an if statement that compares the equality of the addresses
* if they addresses are the same, it is the same object.
*
* All items with the rhs stack will be assigned to the instance of the stack class
* created in the driver.
*/
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if (&stackarray == &rhs.stackarray)
    {
        std::cout << "Self assignment!" << std::endl;
        return *this;
    }

    else
    {
        for (int i = 0; i <= rhs.size(); i++)
        {
            stackarray[i] = rhs.stackarray[i];
        }
    }

    topofstack_ = rhs.topofstack_;
    return *this;
}


template <typename T>
void Stack <T>::clear (void)
{
    while (topofstack_ > 0)
    {
        pop();
    }
}
