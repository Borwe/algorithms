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

