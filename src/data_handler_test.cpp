#include "data_handler.h"
#include <iostream>

int main(){
    std::cout<<"Checking if works\n";

    DataHandler::Algs4File file("rates.txt");
    auto lines=file.getLines();
    std::cout<<"See the lines\n";
    for(auto &line:lines)
        std::cout<<line<<"\n";

    std::cout<<"\nSee if words show:\n";
    auto words=file.getWords();
    for(auto &word:words)
        std::cout<<word<<" ";
    std::cout<<"\n";

    std::cout<<"\nSee if input word simulation words:\n";
    auto in=file.simulateWordInput();
    while(in.eof()==false){
        std::string word;
        in>>word;

        std::cout<<"WORD: "<<word<<"\n";
    }
    return 0;
}
