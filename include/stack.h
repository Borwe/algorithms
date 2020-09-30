#ifndef STACK_CUSTOM_H
#define STACK_CUSTOM_H

#include "node.h"
#include "iterator.h"
#include <deque>
#include <utility>

template<typename Item>
class StackIterator:public ForwardIterator<Item>{
private:
    ShNode<Item> node;
public:
    StackIterator(ShNode<Item> node){
        this->node=node;
    }

    StackIterator<Item> &operator++() override{
        node=node->next;
        return *this;
    }

    const StackIterator<Item> &&operator++(int junk) override{
       StackIterator<Item> copy(this->node);
       node=node->next;
       return std::move(copy);
    }

    ShNode<Item> operator*(){
        return this->node;
    }
};

template<typename Item>
class Stack{
private:
    int N;
    ShNode<Item> first;

    void fillInValues(Item i,Item is...){
        
    }
public:
    Stack(){
       this->first=nullptr; 
    }

    Stack(Item i,Item is... ){
        fillInValues(i,is);
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

    StackIterator<Item> begin() {
        //go to the beggining of the stack which is first
        return StackIterator<Item>(this->first);
    }

    StackIterator<Item> end() {
        //go to the end
        return StackIterator<Item>(nullptr);
    }

};

#endif
