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
    return 0;
}
