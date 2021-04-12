//Copyright (C) 2021  Brian Orwe
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.


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
        }else {
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
