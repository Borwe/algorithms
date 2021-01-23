#include <iostream>
#include <string>

namespace DataHandler{
    template<typename T>
    void println(T &obj){
        std::cout<<obj<<std::endl;
    }

    template<typename T>
    void print(T &obj){
        std::cout<<obj;
    }

    std::string promptForReturn(std::string prompt){
        std::cin.clear();
        std::cin.clear();

        print(prompt);
        std::string result;
        std::cin>>result;

        return result;
    }
};
