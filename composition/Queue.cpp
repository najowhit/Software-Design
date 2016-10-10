//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================
#include <iostream>

// Nathan, make sure you are calling the constructor coorectly. Array<T> is not required.
/**
* I removed the Array<T>
*/
template <typename T>
Queue <T>::Queue (void)
: qarray(20),
  frontofq_(0),
  endofq_(0)
{

}

// Nathan, make sure you are calling the constructor coorectly. Array<T> is not required.
/**
* I removed the Array<T>
*/
template <typename T>
Queue <T>::Queue (const Queue & queue)
: qarray(queue.qarray),
  frontofq_(queue.frontofq_),
  endofq_(queue.endofq_)
{

}

// Nathan, you need not call resize method before the array is destructed.
/**
* I removed the resize method.
*/
template <typename T>
Queue <T>::~Queue(void)
{

}


// Nathan, you should always check for self assignment first.
/**
* I check for self assignment by creating an if statement that compares the equality of the addresses
* if they addresses are the same, it is the same object.
*
* To overload the = operator the values from the rhs queue will be assigned to the
* queue that is currently being used.
*/
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    if (&qarray == &rhs.qarray)
    {
        std::cout << "Self assignment!" << std::endl;
        return *this;
    }

    else
    {
        for (int i = 0; i <= rhs.size(); i++)
        {
            qarray[i] = rhs.qarray[i];
        }
    }

    frontofq_ = rhs.frontofq_;
    endofq_ = rhs.endofq_;

    return *this;
}


// Nathan, make sure you do not waste any space in the front of the array if you must
// resize the array to accommodate new elements. This will require updates
// to your dequeue method.
/**
* I made changes to the dequeue method that will not waste space at the front of the array.
*
* Using the array object qarray, an enqueue will add an element to the end of the qarray
* by calling methods from the Array class.
*/
template <typename T>
void Queue <T>::enqueue(T element)
{
    int qmult = 2;

    if (endofq_ > qarray.size())
    {
        qarray.resize(qarray.size() * qmult);
        qarray.set(endofq_, element);
        endofq_++;
    }

    else if (endofq_ == qarray.size())
    {
        qarray.resize(qarray.size() * qmult);
        qarray.set(endofq_, element);
        endofq_++;
    }

    else if(endofq_ < qarray.size())
    {
        qarray.set(endofq_, element);
        endofq_++;
    }

}


// Nathan, This solution will work, but you are wasting space at the front
// of the array since those "unused" spaces will never be used again. Please
// come up with a better design that uses memory more efficiently.
/**
* I created a new dequeue method that will not waste space at the beginning of the array by shifting
* elements as needed.
*
* The dequeue method needs to preserve the data at the end of the queue so the resize method should
* not be utilized.
*/
template <typename T>
void Queue<T>::dequeue(void)
{
    if (endofq_ == 0)
    {
        throw empty_exception();
    }

    else
    {
        for (int i = 0; i < endofq_; i++)
        {
            qarray[i] = qarray[i + 1];
        }

        endofq_--;
    }
}


// Nathan, you don't have to use a for loop here.
/**
* An exception does not need to be thrown in the clear method because if an exception occurs.
* Rather than using a for loop, I now instead set the front and head variables to zero, thus clearing the queue in a
* timely manner.
*/
template <typename T>
void Queue<T>::clear(void)
{
    frontofq_ = 0;
    endofq_ = 0;
}
