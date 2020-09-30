#ifndef BAG_CUSTOM_H
#define BAG_CUSTOM_H

#include "node.h"
#include "stack.h"



template<typename Item>
class BagIterator:public StackIterator<Item>{
};


template<typename Item>
class Bag{
private:
    ShNode<Item> first;
    int N;
public:
    Bag(){
        first=nullptr;
    }

    void add(Item item){
        auto oldFirst=first;
        first=std::shared_ptr<Node<Item>>();
        first->item=item;
        first->next=oldFirst;
    }

    BagIterator<Item> begin(){
        return BagIterator(first);
    }

    BagIterator<Item> end(){
        return BagIterator<Item>(nullptr);
    }
};


#endif
