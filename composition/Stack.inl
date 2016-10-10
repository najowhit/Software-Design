// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return topofstack_;
}


template <typename T>
inline
T Stack <T>::top (void) const
{
    if (topofstack_ == 0)
    {
        throw empty_exception();
    }

    else
    {
        return stackarray.get(topofstack_ - 1);
    }
}


template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if (topofstack_ == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}
