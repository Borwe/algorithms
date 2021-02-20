#ifndef ITERATORS_CUSTOM_H
#define ITERATORS_CUSTOM_H

#include <memory>
#include "node.h"

template<typename T>
using ShPtr = std::shared_ptr<T>;

template<typename Item>
class LinkedListForwardIterator{
private:
    ShNode<Item> node;
public:
    LinkedListForwardIterator(ShNode<Item> node){
        this->node=node;
    }

    void operator++() {
        node=node->next;
    }

    const bool operator!=(LinkedListForwardIterator<Item> s2){
        bool value=false;
        if(s2.node==nullptr && this->node==nullptr){
            //meaning they are equal
            value=false;
        }else if(s2.node==nullptr && this->node!=nullptr){
            //they aren't equal
            value =true;
        }else if(node->item!=s2.node->item){
            //both are not equal and non null
            value=true;
        }
        return value;
    }

    Item &operator*(){
        return this->node->item;
    }
};

template<typename T>
class ReverseIterator{
public:
    virtual T &operator--(){};
    virtual T operator--(int){};
};

#endif
