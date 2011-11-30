#pragma once

#include <iterator>

template<typename T> 
class Range
{
public:
    typedef typename T::iterator iterator_type;
    typedef typename T::const_iterator const_iterator_type;
    typedef std::iterator_traits<iterator_type> traits;
    
    Range(const T & container)
        : b(container.begin())
        , e(container.end())
    {
    }

    /*
    Range(typename iterator_type begin,
          typename iterator_type end)
        : b(begin)
        , e(end)
    {
    }

    Range(typename const_iterator_type begin,
          typename const_iterator_type end)
        : b(begin)
        , e(end)
    {
    }
    */

    bool empty() const
    {
        return (b == e);
    }

    void popFront()
    {
        assert(!empty());
        ++b;
    }

    void popBack()
    {
        assert(!empty());
        --e;
    }

    typename traits::value_type front() const
    {
        assert(!empty());
        return *b;
    }

    typename traits::value_type back() const
    {
        assert(!empty());
        return *(e-1);
    }

private:
    typename const_iterator_type b;
    typename const_iterator_type e;
};

template<typename T>
Range<T> range(const T & container)
{
    return Range<T>(container);
}

template<typename T>
Range<T> range(typename T::iterator b,
               typename T::iterator e)
{
    return Range<T>(b, e);
}