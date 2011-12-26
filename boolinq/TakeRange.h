#pragma once

#include "Count.h"

namespace boolinq
{
    template<typename R> 
    class TakeRange
    {
    public:
        typedef typename R::value_type value_type;

        TakeRange(R r, int n)
            : r(r)
        {
            int size = boolinq::count(r);
            if (size > n)
            {
                for (int i = 0; i < size-n; i++)
                    this->r.popBack();
            }
        }

        bool empty()       { return r.empty();    }
        value_type popFront()    { return r.popFront(); }
        value_type popBack()     { return r.popBack();  }
        value_type front() { return r.front();    }
        value_type back()  { return r.back();     }

    private:
        R r;
    };

    // take(take(xxx, ...), ...)

    template<typename R>
    TakeRange<R> take(R r, int n)
    {
        return TakeRange<R>(r,n);
    }

    // xxx.take(...).take(...)

    template<template<typename> class TLinq, typename R>
    class TakeRange_mixin
    {
    public:
        TLinq<TakeRange<R> > take(int n) const
        {
            return boolinq::take(((TLinq<R>*)this)->r,n);
        }
    };
}
// namespace boolinq
