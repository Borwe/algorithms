//Copyright (C) 2021  Brian Orwe
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.


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
