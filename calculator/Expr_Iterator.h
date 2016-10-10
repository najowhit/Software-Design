/**
* Honor Pledge:
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#ifndef _EXPR_ITERATOR_H_
#define _EXPR_ITERATOR_H_

#include "Array.h"

template <typename T>
class Expr_Iterator
{
public:

    typedef T type;

    Expr_Iterator (Array <T> & a);

    ~Expr_Iterator (void);

    bool is_done (void);

    bool advance (void);

    T  operator * (void);

    T * operator -> (void);

private:

    Array <T> & a_;
    size_t curr_;

};


#include "Expr_Iterator.cpp"
#endif
