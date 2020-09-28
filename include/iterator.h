#ifndef ITERATORS_CUSTOM_H
#define ITERATORS_CUSTOM_H

#include <memory>

template<typename T>
using ShPtr = std::shared_ptr<T>;

template<typename T>
class Iterator{
};

template<typename T>
class ForwardIterator:public Iterator<T>{
public:
    //postfix increment
    virtual ForwardIterator<T> &operator++()=0; 
    //prefix increment
    const virtual ForwardIterator<T> &&operator++(int junk)=0;
};

template<typename T>
class ReverseIterator{
public:
    virtual T &operator--();
    virtual T operator--(int);
};

#endif
