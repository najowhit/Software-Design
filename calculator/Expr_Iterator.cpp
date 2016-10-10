/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include "Expr_Iterator.h"
#include <iostream>

template <typename T>
Expr_Iterator<T>::Expr_Iterator (Array <T> & a)
: a_ (a),
curr_ (0)
{

}

template <typename T>
Expr_Iterator<T>::~Expr_Iterator (void)
{

}

template <typename T>
bool Expr_Iterator<T>::is_done(void)
{
    return this->curr_ >= this->a_.size();
}

template <typename T>
bool Expr_Iterator<T>::advance(void)
{
    ++ this->curr_;
    return true;
}

template <typename T>
T Expr_Iterator<T>::operator * (void)
{
    return this->a_[this->curr_];
}

template <typename T>
T* Expr_Iterator<T>::operator->(void)
{
    return &this->a_[this->curr_];
}



