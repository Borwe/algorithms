#include <iostream>

namespace DataHandler{
    template<typename T>
    void println(T &obj){
        std::cout<<obj<<std::endl;
    }

    template<typename T>
    void print(T &obj){
        std::cout<<obj;
    }

};
