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
#include "data_handler.h"
#include "queue.h"


int main(){
    Queue<std::string> q;

    auto file=DataHandler::Algs4File("tobe.txt");

    auto words=file.getWords();
    for(auto &word:words){
        if(word!="-")
            q.enqueue(word);
        else if(q.isEmpty()==false)
            std::cout<<q.dequeue()<<" ";
    }

    std::cout<<"("<<q.size()<<" left on queue)";
    return 0;
}
