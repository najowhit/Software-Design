// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
#include <iostream>

Array::Array (void)
: data_(nullptr),
  cur_size_(10),
  max_size_(100)
{

}

Array::Array (size_t length)
: data_(nullptr),
  cur_size_(length),
  max_size_(100)
// Nathan, Initialize all member variables in the base member initialization section
// of the constructor.
// Dr. Hill, I initialized all member variables in the order in which they were declared in the header file.
{
    // Nathan, You must implement this method.
    //Dr. Hill, I implemented this method by creating an array of size length and filling it with the default value of '0'
    //which is not user specified.
    data_ = new char[length];
    Array::fill('0');
}

Array::Array (size_t length, char fill)
// Nathan, Initialize all member variables in the base member initialization section
// Dr. Hill, I initialized all member variables in the order in which they were declared in the header file.
// of the constructor.
: data_(new char[length]),
  cur_size_(length),
  max_size_(100)
{
    Array::fill(fill);
}

Array::Array (const Array & array)
: data_(new char[array.max_size_]),
  cur_size_(array.cur_size_),
  max_size_(array.max_size_)

{

}

Array::~Array (void)
{
    delete [] data_;

    // Nathan, There is no need to reset the data_ variable since this oject is
    // no longer useable after the desturctor returns.
    // Dr. Hill, I removed the unnecessary statement "data_ = nullptr" because the object will be no longer usable after the destructor returns.
}

const Array & Array::operator = (const Array & rhs)
{
    // Nathan, You must implement this method.
    // Dr Hill, I implemented this method by assigning all values in the array on the right hand side to the
    // main array. I returned a reference to the Array object.
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = rhs[i];
    }

    return *this;

}

/**
* This method needs to return a character at the index
* that will be defined in the driver using the [x] operator. If the index is out of range,
* throw an exception.
*/
char & Array::operator [] (size_t index)
{

    if(index > cur_size_)
    {
        throw std::out_of_range ("The index chosen is out of range");
    }

    else
    {
        return data_[index];
    }

}

const char & Array::operator [] (size_t index) const
{
    // Nathan, You are to thrown an exception if the index is invalid.
    // Dr. Hill, I created an if statement to throw an exception if the index is invalid.
    if(index > cur_size_)
    {
        throw std::out_of_range ("The index chosen is out of range");
    }

    else
    {
        return data_[index];
    }

}

/**
* Return a character at an index that is specified in the driver.
* Throw an exception if the index is out of range.
*/
char Array::get (size_t index) const
{
    if(index > cur_size_)
    {
        throw std::out_of_range ("The index chosen exceeds the size of the array");
    }

    else
    {
        char selectChar  = data_[index];
        return selectChar;
    }

}

/**
* This method sets an index in the array to a certain character value.
* The method will throw an exception if the index is out of range.
*/
void Array::set (size_t index, char value)
{
    if(index > cur_size_)
    {
        throw std::out_of_range ("The index chosen exceeds the size of the array");
    }

    else
    {
        data_[index] = value;
    }

}

/**
* This method resizes the current size of the array, but if the new size is greater than
* the max size, a new array will be allocated and the max size will be double the new size.
* The data has to be copied through the use of a temporary array.
*/
void Array::resize (size_t new_size)
{
    // Nathan, The resize method should only increase the size of the allocation
    // is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data.

    // Dr. Hill, I created an if statement that only increases the size when new_size is larger than the current size.
    // To preserve the original data, I remove the statement that created a new array when the method was called.
    // If the new size is greater than the max size, I allocate a new array that is the size of the new size,
    // use a temporary array to swap the values, delete that temporary array, set the current size to new size, and
    // create a new max size that is twice the new size.
    if (new_size > max_size_)
    {
        char * temp = new char[new_size];

        for (int i = 0; i < cur_size_; i++)
        {
            temp[i] = data_[i];
            data_[i] = temp[i];
        }

        delete [] temp;
        cur_size_ = new_size;
        max_size_ = 2* new_size;

    }

    else if(new_size > cur_size_ && cur_size_ < max_size_)
    {
        cur_size_ = new_size;
    }

}

/**
* The find method allows a character be entered as a parameter.
* The method will search the array and return the index of the
* FIRST INSTANCE of that character. If the character is not found,
* -1 is returned.
*/
int Array::find (char ch) const
{
    for(int i = 0; i <= cur_size_; i++)
    {
        if(data_[i] == ch)
        {
            return i;
        }
    }

    return -1;

}

/**
* This find method will be slightly tweaked. This version accepts a start parameter which
* specifies which index in the array to start searching from. An exception will be thrown
* if the start index is out of range. If the character is not found -1 will be returned.
*/
int Array::find (char ch, size_t start) const
{
    if(start > cur_size_)
    {
        throw std::out_of_range("The start index chosen exceeds the size of the array");
    }

    else
    {
        for(int i = start; i <= cur_size_; i++)
        {
            if(data_[i] == ch)
            {
                return i;
            }
        }

        return -1;
    }

}


bool Array::operator == (const Array & rhs) const
{
    // Nathan, the code below is always going to be true!
    // Dr. Hill, I compared for equality by comparing each character of the array to the rhs array that will be taken as a parameter
    // if the two compared elements are inequal at anytime, false is returned.
    for(int i = 0; cur_size_; i++)
    {
        if (data_[i] != rhs[i])
        {
            return false;
        }
    }

    return true;

}

bool Array::operator != (const Array & rhs) const
{
    // Nathan, You can define operator != in terms of operator ==.
    // Dr. Hill, I compared the two arrays for inequality by using the == operator like you mentioned.
    // If the arrays are equal, they cannot be inequal.
    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] == rhs[i])
        {
            return false;
        }
    }

    return true;

}

/**
* Array::fill will place the specified character in ALL indecies of the array.
*/
void Array::fill (char ch)
{
    for(int i = 0; i < cur_size_; i++)
    {
        data_[i] = ch;
    }

}

