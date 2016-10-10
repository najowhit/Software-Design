//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================
template <typename T>
inline
T Queue <T>::last (void) const
{
    return qarray[endofq_ - 1];
}


template <typename T>
inline
size_t Queue <T>::size (void) const
{
    return endofq_;
}

template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    if (frontofq_ == endofq_)
    {
        return true;
    }

    else
    {
        return false;
    }
}
