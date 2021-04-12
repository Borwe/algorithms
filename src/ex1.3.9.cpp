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
#include <string>
#include <cctype>
#include "stack.h"
#include "queue.h"


std::string normalize(std::string value_passed){
    std::string proper_sum;

    Stack<std::string> numbers;
    Stack<char> operators;

    for(char c:value_passed){
        if(std::isdigit(c)){
            numbers.push(std::string(1,c));
        }else if(c== '+'|| c== '-' || c=='*' || c=='/'){
            operators.push(c);
        }else if(c==')'){
            std::string right=numbers.pop();
            std::string left=numbers.pop();
            char ops= operators.pop();
            std::string result="("+left+ops+right+")";
            numbers.push(result);
        }
    }

    proper_sum=numbers.toString();

    return proper_sum;
}

int main(){
    std::string value_passed("1+2)*3-4)*5-6)))");
    std::cout<<"Turning "<<value_passed<<" to propert string:\n";
    std::string proper_sum=normalize(value_passed);
    std::cout<<"Done Result is: \n";
    std::cout<<proper_sum<<"\n";
    return 0;
}
