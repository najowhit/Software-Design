/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/

#include <stdexcept>

template <typename T>
Array_Base <T>::Array_Base (void)
: data_(0),
  cur_size_(0)
{

}


template <typename T>
Array_Base <T>::Array_Base (size_t length)
: data_(0),
  cur_size_(length)
{
    data_ = new T[length];
}


template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
: data_(new T[length]),
  cur_size_(length)
{
    this->fill(fill);
}


template <typename T>
Array_Base <T>::Array_Base (const Array_Base & arrb)
: data_(new T[arrb.cur_size_]),
  cur_size_(arrb.cur_size_)
{
    for (int i = 0; i < arrb.size(); i++)
    {
        data_[i] = arrb.data_[i];
    }
}


template <typename T>
Array_Base <T>::~Array_Base (void)
{
    delete [] data_;
}


template <typename T>
T & Array_Base <T>::operator [] (size_t index)
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


template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
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


template <typename T>
T Array_Base <T>::get (size_t index) const
{
    if(index > cur_size_)
    {
        throw std::out_of_range ("The index chosen exceeds the size of the array");
    }

    else
    {
        T getitem  = data_[index];
        return getitem;
    }
}


template <typename T>
void Array_Base <T>::set (size_t index, T value)
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


template  <typename T>
int Array_Base <T>::find (T value) const
{
    for(int i = 0; i <= cur_size_; i++)
    {
        if(data_[i] == value)
        {
            return i;
        }
    }

    return -1;
}


template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    if(start > cur_size_)
    {
        throw std::out_of_range("The start index chosen exceeds the size of the array");
    }

    else
    {
        for(int i = start; i <= cur_size_; i++)
        {
            if(data_[i] == val)
            {
                return i;
            }
        }

        return -1;
    }
}


template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    for(int i = 0; cur_size_; i++)
    {
        if (data_[i] != rhs[i])
        {
            return false;
        }
    }

    return true;
}


template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] == rhs[i])
        {
            return false;
        }
    }

    return true;
}


template <typename T>
void Array_Base <T>::fill (T value)
{
    for(int i = 0; i < cur_size_; i++)
    {
        data_[i] = value;
    }
}
