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


#include <cstdlib>
#include <printer.h>
#include "queue.h"
#include <string>

int main(int argc,char **argv){
    Queue<std::string> q1_input;
    for(int i=1;i<argc;++i){
        //put in data to queue fro argv
        q1_input.enqueue(argv[i]);
    }

    DataHandler::Printer::println(q1_input);

    if(q1_input.isEmpty()){
        DataHandler::Printer::print("There is no K'th number passed");
        return 0;
    }

    //get the K'th term given as input
    if(q1_input.size()<=1){
        //meaning nothing really inside
        DataHandler::Printer::println("Done, there was nothing to print");
        return 0;
    }

    //otherwise get first value
    std::string val=q1_input.dequeue();
    int kth=atoi(val.c_str());

    std::string gotten=q1_input[kth];
    DataHandler::Printer::print("Found @ ").print(kth).print(" Value : ")
        .println(gotten).println("Done");
    return 0;
}
