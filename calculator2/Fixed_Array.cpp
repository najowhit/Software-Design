// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


// Nathan, You need to handle the resize() method on Array correctly.
/**
* I made improvements to my resize method within the Array class
*/
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
: Array_Base<T>::Array_Base(N)
{

}


// Nathan, you are using N wrongly here.
/**
* I removed the N and I pass the Fixed_Array object to the Array copy constructor
*/
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
: Array_Base<T>::Array_Base(arr)
{

}


// Nathan, call the base constructor in the bmi section.
/**
* I added the base constructor to the BMI list.
*/
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
: Array_Base<T>::Array_Base(N)
{
    Array_Base<T>::fill(fill);
}


/**
* No extra deconstructor is needed for the Fixed_Array. The Fixed_Array inherits from the Array class,
* which has a deconstructor that will delete the heap allocations.
*/
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{

}


/**
* Use the assignment operator defined in the Array_Base class instead of creating a new one
*/
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    for (int i = 0; i < rhs.Array_Base<T>::size(); i++)
    {
        Array_Base<T>::operator[](i) = rhs.Array_Base<T>::operator[](i);
    }

    return *this;
}
