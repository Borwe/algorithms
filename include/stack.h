#ifndef STACK_CUSTOM_H
#define STACK_CUSTOM_H

#include "node.h"
#include "iterator.h"
#include "dymamic_preproc.h"

template<typename T>
class StackIterator;

template<typename Item>
class Stack:public BasicIteratorMethods<StackIterator<Item>>{
private:
    int N;
    ShNode<Item> first;
public:
    
    DYNAMIC_SPEC bool isEmpty() const;
    DYNAMIC_SPEC int size() const;

    DYNAMIC_SPEC void push(Item item);
    DYNAMIC_SPEC Item pop();

    DYNAMIC_SPEC StackIterator<Item> begin() override;
    DYNAMIC_SPEC StackIterator<Item> end() override;
};

template<typename Item>
class StackIterator:public ForwardIterator<Item>{
private:
    ShNode<Item> node;
public:
    DYNAMIC_SPEC StackIterator(ShNode<Item> node);
    DYNAMIC_SPEC StackIterator<Item> &operator++() override;
    DYNAMIC_SPEC StackIterator<Item> operator++(int) override;
    DYNAMIC_SPEC ShNode<Item> operator*();
};

#endif
