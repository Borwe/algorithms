#include <iostream>
#include <string>
#include "data_handler.h"
#include "queue.h"


int main(){
    Queue<std::string> q;

    auto file=DataHandler::Algs4File("tobe.txt");

    auto words=file.getWords();
    for(auto &word:words){
        if(word!="-")
            q.enqueue(word);
        else if(q.isEmpty()==false)
            std::cout<<q.dequeue()<<" ";
    }

    std::cout<<"("<<q.size()<<" left on queue)";
    return 0;
}
