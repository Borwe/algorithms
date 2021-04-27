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
//

#ifndef LINKED_LIST_HEADER_CUSTOM
#define LINKED_LIST_HEADER_CUSTOM

#include "iterator.h"
#include <initializer_list>
#include <node.h>
#include <ostream>
#include <stdexcept>
#include <sstream>

template<typename Item>
class LinkedList{
private:
    ShNode<Item> first;
    ShNode<Item> last;
    int N;
public:

    LinkedList(std::initializer_list<Item> list){
        for(Item &i:list){
            enque(i);
        }
    }

    const size_t size() const{
        return N;
    }

    const bool isEmpty() const{
        return N==0;
    }

    void enque(Item item){
        ShNode<Item> i(item);
        auto oldLast=last;
        last=i;
        last->next=nullptr;
        ++N;

        if(isEmpty())
            first=last;
        else
            oldLast->next=last;
    }

    Item dequeue(){
        if(isEmpty()){
            N--;
            Item item=first->item;
            first=first->next;
            return item;
        }else{
            throw std::runtime_error("Calling dequeue() on empty linkedlist");
        }
    }

    LinkedListForwardIterator<Item> begin(){
        return LinkedListForwardIterator<Item>(first);
    }

    LinkedListForwardIterator<Item> end(){
        return LinkedListForwardIterator<Item>(nullptr);
    }

    friend std::ostream &operator<<(std::ostream &os,const LinkedList &list){
        std::stringstream ss;
        ss<<"[ ";
        auto begin=list.first;
        auto end=list.end;
        int count=0;

        while(begin!=end){
            ss<<begin<<", ";
            ++count;
        }

        std::string result="";
        if(count>0){
            result=ss.str();
            result=result.substr( 0,result.size()-2);
            result+=" ]";
        }else{
            ss<<" ]";
            result=ss.str();
        }

        os<<result;
        return os;
    }
};

#endif
