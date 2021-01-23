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

    DataHandler::println(q1_input);

    if(q1_input.isEmpty()){
        DataHandler::print("There is no K'th number passed");
        return 0;
    }

    //get the K'th term given as input
    if(q1_input.size()<=1){
        //meaning nothing really inside
        DataHandler::println("Done, there was nothing to print");
        return 0;
    }

    //otherwise get first value
    std::string val=q1_input.dequeue();
    int kth=atoi(val.c_str());

    std::string gotten=q1_input[kth];
    DataHandler::print("Found @ ");
    DataHandler::print(kth);
    DataHandler::print(" Value : ");
    DataHandler::println(gotten);
    DataHandler::println("Done");
    return 0;
}
