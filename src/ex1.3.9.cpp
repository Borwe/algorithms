#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"
#include "queue.h"


std::string normalize(std::string value_passed){
    return nullptr;
}

int main(){
    std::string value_passed("1+2)*3-4)*5-6)))");
    std::cout<<"Turning "<<value_passed<<" to propert string:\n";
    std::string proper_sum=normalize(value_passed);
    std::cout<<"Done: \n";
    std::cout<<proper_sum<<"\n";
    std::cout<<"YEAH BITCHES\n";
    return 0;
}
