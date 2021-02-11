#ifndef PRINER_HEADER_CUSTOM
#define PRINER_HEADER_CUSTOM


#include <iostream>
#include <string>

namespace DataHandler{

    class Printer{
    private:
        //private variables
        Printer()=default;
        Printer(const Printer &copy)=default;
        Printer(Printer &&moved)=default;

        static Printer printer;
    public:
        template<typename T>
        static Printer print(T &obj){
            std::cout<<obj;
            return printer;
        }

        template<typename T>
        static Printer println(T &obj){
            std::cout<<obj<<std::endl;
        }

        static std::string promptForReturn(std::string prompt){
            std::cin.clear();
            std::cin.clear();

            print(prompt);
            std::string result;
            std::cin>>result;

            return result;
        }
    };

};

#endif
