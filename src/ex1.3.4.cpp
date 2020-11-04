#include <iostream>
#include "stack.h"
#include "custom_vals.h"

DataHandler::Bool evaluate(const std::string &val){

    //have a stack to hold parenthisis once pushed
    Stack<char> params;


    for(char c:val){
        if(c=='[' || c=='(' || c=='{' ){
            params.push(c);
        }else{
            if(params.isEmpty()){
                return false;
            }

            char item=params.peek();
            if(c==')' && item!='(' ||
                    c==']' && item!='[' ||
                    c=='}' && item!='{')
                return false;
            else if(c==')' && item=='(' ||
                    c==']' && item=='[' ||
                    c=='}' && item=='{')
                params.pop();
        }
    }

    if(params.isEmpty()==false){
        return false;
    }
    return true;
}


int main(){
    std::string val1="[()]{}{[()()]()}"; //should pass
    std::string val2="[(])"; //should fail

    std::cout<<val1<<" has proper matching: "<<evaluate(val1)<<"\n";
    std::cout<<val2<<" has proper matching: "<<evaluate(val2)<<"\n";
    return 0;
}
