// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
#include <iostream>


template <typename T>
Array <T>::Array (void)
: Array_Base<T>::Array_Base(0),
  max_size_(0)
{

}


template <typename T>
Array <T>::Array (size_t length)
: Array_Base<T>::Array_Base(length),
  max_size_(length)
{

}


template <typename T>
Array <T>::Array (size_t length, T fill)
: Array_Base<T>::Array_Base(length),
  max_size_(length)
{
    Array_Base<T>::fill(fill);
}


template <typename T>
Array <T>::Array (const Array & array)
: Array_Base<T>::Array_Base(array),
  max_size_(array.max_size_)
{

}


template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if (rhs.Array_Base<T>::size() <= Array_Base<T>::size())
    {
        for (int i = 0; i < rhs.Array_Base<T>::size(); i++)
        {
            Array_Base<T>::operator[](i) = rhs.Array_Base<T>::operator[](i);
        }

    }

    else if (rhs.Array_Base<T>::size() > Array_Base<T>::size())
    {
        for (int i = 0; i < Array_Base<T>::size(); i++)
        {
            Array_Base<T>::operator [](i) = rhs.Array_Base<T>::operator [](i);
        }

    }

    return *this;
}


/**
* The previous structure of the resize method caused memory issues. To combat this,
* I create an Array object temp that will serve as my new temporary array to hold the items from data_.
* This method will allow me to delete the data and create a new array of the appropriate size.
*
* Previously, I allocated my temporary array as T * temp = new T[new_size] which did not work succesfully.
*/
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if (new_size > max_size_)
    {
        Array_Base<T> temp(new_size);

		for (int i = 0; i < Array_Base<T>::cur_size_; i++)
		{
			Array_Base<T>::data_[i] = Array_Base<T>::data_[i];
		}

		delete[] Array_Base<T>::data_;
        Array_Base<T>::data_ = new T[new_size];

		for (int i = 0; i < Array_Base<T>::cur_size_; i++)
		{
			Array_Base<T>::data_[i] = Array_Base<T>::data_[i];
		}

		Array_Base<T>::cur_size_ = new_size;
		max_size_ = new_size;
    }

	else  if (new_size <= max_size_)
	{
		Array_Base<T>::cur_size_ = new_size;
	}

}


