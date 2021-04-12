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


#ifndef STACK_CUSTOM_H
#define STACK_CUSTOM_H

#include "node.h"
#include "iterator.h"
#include "queue.h"
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <sstream>


template<typename Item>
class Stack;


template<typename T>
std::ostream &operator<<(std::ostream &os,Stack<T> &stack){
    os<<stack.toString();
    return os;
}

template<typename Item>
class Stack{
private:
    int N;
    ShNode<Item> first;

    template<typename ItemA,typename... ItemsA>
    static void fillIn(Stack<ItemA> &s,const ItemA &i,const ItemsA&... is){
        s.push(i);
        fillIn(s,is...);
    }

    template<typename ItemA>
    static void fillIn(Stack<ItemA> &s){
    }

public:
    Stack(){
       this->first=nullptr; 
    }

    template<typename ItemA,typename... ItemsA>
    static Stack<ItemA> fillValues(const ItemA &i,const ItemsA&... is ){
        Stack<ItemA> stack;
        
        stack.push(i);//push item i
        fillIn(stack,is... );
        return stack;
    }
    
    bool isEmpty() const{
        return N==0; 
    }
    int size() const{
        return N;
    }

    Item peek(){
        return first->item;
    }

    void push(Item item){
        ShNode<Item> oldFirst=this->first;
        first=std::make_shared<Node<Item>>();
        first->item=item;
        first->next=oldFirst;
        N++;
    }

    Item pop(){
        Item item=first->item;
        first=first->next;
        N--;
        return item;
    }

    LinkedListForwardIterator<Item> begin() {
        //go to the beggining of the stack which is first
        return LinkedListForwardIterator<Item>(this->first);
    }

    LinkedListForwardIterator<Item> end() {
        //go to the end
        return LinkedListForwardIterator<Item>(nullptr);
    }

    /**
     * For creating a copy of toBeCopied
     */
    template <typename T>
    static Stack<T> copy(Stack<T> &toBeCopied){
        Stack<T> copy;
        //hold temp queue
        Stack<T> tempStack;
        for(T t:toBeCopied){
            T temp=t;
            tempStack.push(t);
        }

        for (T t : tempStack) {
          copy.push(t);
        }

        return copy;
    }

    template<typename T>
    friend std::ostream &operator<<(std::ostream &os,Stack<T> &stack);


    /**
     * For printing out items in stack as they appear
     */
    const std::string toString() {
        std::string result="";

        std::stringstream strm;

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
