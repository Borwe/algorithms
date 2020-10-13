#ifndef ITERATORS_CUSTOM_H
#define ITERATORS_CUSTOM_H

#include <memory>

template<typename T>
using ShPtr = std::shared_ptr<T>;


template<typename T>
class ReverseIterator{
public:
    virtual T &operator--(){};
    virtual T operator--(int){};
};

#endif
