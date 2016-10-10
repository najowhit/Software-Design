//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include <exception>

template <typename T>
class Queue
{
public:

    typedef T type;


    class empty_exception : public std::exception
    {
    public:
        empty_exception (void)
         : std::exception () { }

    };

    /**
    * Default constructor
    */
    Queue (void);

    /**
    * Copy Constructor
    */
    Queue (const Queue & q);

    /**
    * Deonstructor
    */
    ~Queue (void);

    /**
    * Operator overloader
    */
    const Queue & operator = (const Queue & rhs);

    /**
    * Enqueue will add an element to the end of the queue
    */
    void enqueue(T element);

    /**
    * Dequeue removes the element at the front of the queue. FIFO.
    */
    void dequeue(void);

   /**
   * The last method is a simple test method so I can ensure that the enqueue and dequeue methods
   * are working as expected. Similar to the top method in the Stack class.
   */
    T last (void) const;

    /**
    * is_empty should return True if the queue is empty and false otherwise
    */
    bool is_empty (void) const;

    /**
    * Returns the size of the queue
    */
    size_t size (void) const;

    /**
    * Clear should clear all element from the queue
    */
    void clear (void);

/**
* Create an Array<T> object and use aggregation because a queue is composed of an array, a queue is not an array.
*/
private:

    Array<T> qarray;
    int frontofq_;
    int endofq_;


};



#include "Queue.inl"
#include "Queue.cpp"

#endif
