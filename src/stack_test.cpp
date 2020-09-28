#include <iostream>
#include "stack.h"
#include <string>
#include "data_handler.h"

int main(){
    Stack<std::string> s;

    DataHandler::Algs4File file("tobe.txt");
    auto words=file.getWords();

    for(auto &word:words){
        if(word!="-")
            s.push(word);
        else if(s.isEmpty()==false)
            std::cout<<s.pop()<<" ";
    }

    std::cout<<"("<<s.size()<<" left on stack)\n";
    return 0;
}

