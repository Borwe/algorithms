#ifndef QUEUE_CUSTOM_H
#define QUEUE_CUSTOM_H

#include "node.h"
#include <memory>
#include "iterator.h"
#include <string>
#include <sstream>
#include <ostream>

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
    friend std::ostream &operator<<(std::ostream &os,Queue<T> &queue);

    const std::string toString(){
        std::stringstream strm;

        std::string result;

        for(auto &temp:(*this)){
            strm<<temp;
            strm<<", ";
        }

        result=strm.str();
        result=result.substr(0,result.length()-2);

        return result;
    }
};

#endif
