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


#ifndef QUEUE_CUSTOM_H
#define QUEUE_CUSTOM_H

#include "node.h"
#include <memory>
#include "iterator.h"
#include <string>
#include <sstream>
#include <ostream>
#include <cassert>
#include <iostream>

template<typename Item>
class Queue;

template<typename Item>
std::ostream &operator<<(std::ostream &os,Queue<Item> &queue){
    os<<queue.toString();
    return os;
}

template<typename Item>
class Queue{
private:
    ShNode<Item> first;
    ShNode<Item> last;
    int N;

    template<typename ItemA,typename... ItemsA>
    static void fillIn(Queue<ItemA> &q,const ItemA &i,const ItemsA&... is){
        q.enqueue(i);
        fillIn(q,is...);
    }

    template<typename ItemA>
    static void fillIn(Queue<ItemA> &q){

    }
public:
    Queue(){
        first=nullptr;
        last=nullptr;
        N=0;
    }

    template<typename ItemA,typename... ItemsA>
    static Queue<ItemA> fillValues(const ItemA &i,const ItemsA&... is){
        Queue<ItemA> queue;
        
        queue.enqueue(i);

        fillIn(queue,is...);

        return queue;
    }

    bool isEmpty(){
        return N==0;
    }

    const size_t size(){
        return N;
    }

    void enqueue(Item item){
        auto oldLast=this->last;
        last=std::make_shared<Node<Item>>();
        last->item=item;
        last->next=nullptr;

        if (isEmpty())
            first=last;
        else
            oldLast->next=last;

        ++N;
    }

    Item dequeue(){
        Item item=first->item;
        first=first->next;
        --N;
        if(this->isEmpty())
            throw std::runtime_error("Calling dequeue() on empty queue");
        else{
            Item item=first->item;
            first=first->next;
            --N;
            return item;
        }
    }

    Item operator[](int pos){
        assert(this->size()>0);
        assert(pos < this->size());
        assert(pos >= 0);
        
        //loop till reach pos, and return item
        int i=0;
        LinkedListForwardIterator<Item> iterator=this->begin();
        while(i!=pos && i<=pos ){
            if(pos==i){
                return *iterator;
            }
            ++iterator;
            ++i;
        }
        return first->item;
    }

    const Item peek() const{
        Item item=first->item;
        return item;
    }

    LinkedListForwardIterator<Item> begin(){
        return LinkedListForwardIterator<Item>(this->first);
    }

    LinkedListForwardIterator<Item> end(){
        return LinkedListForwardIterator<Item>(nullptr);
    }


    template<typename T>
    friend std::ostream &operator<<(std::ostream &os,const Queue<T> &queue);

    const std::string toString() {
        std::stringstream strm;

        std::string result;

        auto iterator=begin();

        while(iterator!=end()){
            strm<<*iterator;
            strm<<", ";
            ++iterator;
        }

        result=strm.str();
        result=result.substr(0,result.length()-2);

        return result;
    }
};

#endif
