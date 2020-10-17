#include <iostream>
#include "stack"
#include <stdexcept>
#include <string>
#include "custom_vals.h"

class Brak {
private:
    char open;
    char close;
public:
    Brak(const char &c){
        switch(c){
            case '[':
            case ']':
                open='[';
                close=']';
                break;
            
            case '(':
            case ')':
                open='(';
                close=')';
                break;

            case '{':
            case '}':
                open='{';
                close='}';
                break;
            default:
                throw std::runtime_error("Unkown character passed");
        }
    }

    DataHandler::Bool isClose(const char &c){
        return close==c;
    }

    DataHandler::Bool isOpen(const char &c){
        return open==c;
    }
};

DataHandler::Bool evaluate(const std::string &val){
    return false;
}

int main(){
    std::string val1="[()]{}{[()()]()}"; //should pass
    std::string val2="[(])"; //should fail

    std::cout<<val1<<" has: "<<evaluate(val1)<<"\n";
    std::cout<<val2<<" has: "<<evaluate(val2)<<"\n";
    return 0;
}
