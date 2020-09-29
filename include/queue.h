#ifndef QUEUE_CUSTOM_H
#define QUEUE_CUSTOM_H

#include "node.h"
#include <memory>
#include "iterator.h"

template<typename Item>
class QueueIterator:public ForwardIterator<Item>{
private:
    ShNode<Item> node;
public:
    QueueIterator(ShNode<Item> node){
        this->node=node;
    }

    QueueIterator<Item> &operator++() override{
        node=node->next;
        return *this;
    }

    const QueueIterator<Item> &&operator++(int junk) override{
       QueueIterator<Item> copy(this->node);
       node=node->next;
       return std::move(copy);
    }

    ShNode<Item> operator*(){
        return this->node;
    }
};


template<typename Item>
class Queue{
private:
    ShNode<Item> first;
    ShNode<Item> last;
    int N;
public:
    Queue(){
        first=nullptr;
        last=nullptr;
        N=0;
    }

    bool isEmpty(){
        return N==0;
    }

    size_t size(){
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
            last=nullptr;
        return item;
    }

    QueueIterator<Item> begin(){
        return QueueIterator<Item>(this->first);
    }

    QueueIterator<Item> end(){
        return QueueIterator<Item>(nullptr);
    }
};

#endif
