#ifndef ITERATORS_CUSTOM_H
#define ITERATORS_CUSTOM_H

#include <memory>

template<typename T>
using ShPtr = std::shared_ptr<T>;

template<typename T>
class BasicIteratorMethods{
public:
    virtual T begin();
    virtual T end();
};

template<typename T>
class ForwardIterator{
public:
    virtual ForwardIterator<T> &operator++(); 
    virtual ForwardIterator<T> operator++(int);
};

template<typename T>
class ReverseIterator{
public:
    virtual T &operator--();
    virtual T operator--(int);
};

template<typename T>
class Iterator:public ForwardIterator<T>,ReverseIterator<T>{
public:

};

#endif
