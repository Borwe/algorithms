#include "stack.h"
#include "node.h"
#include <memory>

template<typename Item>
bool Stack<Item>::isEmpty() const{
    return true;
}

template<typename Item>
int Stack<Item>::size()const{
    return N;
}

template<typename Item>
void Stack<Item>::push(Item item){
    ShNode<Item> oldFirst=this->first;
    first=std::make_shared<Node<Item>>();
    first->item=item;
    first->next=oldFirst;
    N++;
}

template<typename Item>
Item Stack<Item>::pop(){
    Item item=first->item;
    first=first->next;
    N--;
    return item;
}

//for stack iterator
template<typename Item>
StackIterator<Item>::StackIterator(ShNode<Item> node){
    this->node=node;
}

template<typename Item>
StackIterator<Item> &StackIterator<Item>::operator++(){
    node=node->next;
    return *this;
}

template<typename Item>
StackIterator<Item> StackIterator<Item>::operator++(int junk){
   StackIterator<Item> copy(this->node);
   node=node->next;
   return copy;
}

template<typename Item>
ShNode<Item> StackIterator<Item>::operator*(){
    return this->node;
}

