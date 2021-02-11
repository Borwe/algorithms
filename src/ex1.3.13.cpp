#include <iostream>
#include "custom_vals.h"
#include "printer.h"
#include "queue.h"
#include "data_handler.h"

template<typename T>
const DataHandler::Bool happens(Queue<T> &queue){
    bool result=false;// hold the result

    Queue<int> test;

    Queue<int> temp=queue;

    for(int i=0;i<10;++i){
        int peek=temp.peek();
        if(test.isEmpty()){
            test.enqueue(i);
            continue;
        }

        if(test.peek()==peek){
            test.dequeue();
            temp.dequeue();
            result=true;
            test.enqueue(i);
        }else{
            test.enqueue(i);
            result=false;
        }
    }

    return result;
}

int main(){

    Queue<int> a=Queue<int>::fillValues(0,1,2,3,4,5,6,7,8,9);
    Queue<int> b=Queue<int>::fillValues(4,6,8,7,5,3,2,9,0,1);
    Queue<int> c=Queue<int>::fillValues(2,5,6,7,4,8,9,3,1,0);
    Queue<int> d=Queue<int>::fillValues(4,3,2,1,0,5,6,7,8,9);

    DataHandler::Printer::print("a. ").print(a).print(" passes: ")
        .println(happens(a));

    DataHandler::Printer::print("b. ").println(b).print(" passes: ")
        .println(happens(b));

    DataHandler::Printer::print("c. ").println(c).print(" passes: ")
        .println(happens(c));

    DataHandler::Printer::print("d. ").println(d).print(" passes: ")
        .println(happens(d));

    return 0;
}
