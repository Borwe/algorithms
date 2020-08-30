#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "data.h"
#include <cstddef>

namespace algs{
    template<typename T>
    ShPtr<T> binary_search(ShPtr<T> ke,ShPtr<T[]> array){
        size_t lo=0;
        size_t hi=sizeof(*array)/sizeof(*ke);

        while(lo<=hi){
            size_t mid=lo+(hi-lo)/2;
        }
    }
}
#endif
