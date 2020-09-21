#ifndef STACK_CUSTOM_H
#define STACK_CUSTOM_H

#include "node.h"
#include "iterator.h"

template<typename T>
class StackIterator;

template<typename Item>
class Stack:public BasicIteratorMethods<StackIterator<Item>>{
private:
    int N;
    ShNode<Item> first;
public:
    
    bool isEmpty() const;
    int size() const;

    void push(Item item);
    Item pop();

    StackIterator<Item> begin() override;
    StackIterator<Item> end() override;
};

template<typename Item>
class StackIterator:public ForwardIterator<Item>{
private:
    ShNode<Item> node;
public:
    StackIterator(ShNode<Item> node);
    StackIterator<Item> &operator++() override;
    StackIterator<Item> operator++(int) override;
    ShNode<Item> operator*();
};

#endif
