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


#include "data_handler.h"
#include <iostream>

int main(){
    std::cout<<"Checking if works\n";

    DataHandler::Algs4File file("rates.txt");
    auto lines=file.getLines();
    std::cout<<"See the lines\n";
    for(auto &line:lines)
        std::cout<<line<<"\n";

    std::cout<<"\nSee if words show:\n";
    auto words=file.getWords();
    for(auto &word:words)
        std::cout<<word<<" ";
    std::cout<<"\n";

    std::cout<<"\nSee if input word simulation words:\n";
    auto in=file.simulateWordInput();
    while(in.eof()==false){
        std::string word;
        in>>word;

        std::cout<<"WORD: "<<word<<"\n";
    }
    return 0;
}
