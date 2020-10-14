#include <iostream>
#include <utility>
#include "queue.h"
#include "stack.h"

Stack<int> produceStackOfInts(){
    Stack<int> ints;

    for(int i=0;i<10;++i)
        ints.push(i);

    return ints;
}

Queue<std::pair<std::string,Stack<int>>> listOfPredictions(){
    Queue<std::pair<std::string,Stack<int>>> predictions;

    //stack a
    Stack<int> a;
    return predictions;
}

int main(){
    std::cout<<"SHIT FACE\n";
    auto stacks=produceStackOfInts();
    std::cout<<stacks.toString()<<"\n";

    std::cout<<"TEST2\n";
    Stack<int> stacks2=Stack<int>::fillValues(1,2,3,4,5);
    std::cout<<stacks2.toString()<<"\n";

    std::cout<<"Test3\n";
    Queue<int> queue=Queue<int>::fillValues(1,2,3,4,5,6,7,8,9,0);
    std::cout<<queue.toString()<<"\n";
    return 0;
}
