#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include "queue.h"
#include <fstream>
#include <sstream>
#include "dymamic_preproc.h"


namespace DataHandler{

    DYNAMIC_SPEC std::string getHomeDir()
        #ifdef _WIN32
        throw()
        #endif
    ;

    class Algs4File{
    private:
        static const std::string algs4Dir;
        std::string fileName;
    public:
        DYNAMIC_SPEC Algs4File(std::string fileName);
        
        DYNAMIC_SPEC Queue<std::string> getLines() const;
        DYNAMIC_SPEC Queue<std::string> getWords() const;

        DYNAMIC_SPEC std::stringstream simulateWordInput()const;
    };
#ifdef _WIN32
    const std::string Algs4File::algs4Dir=std::string(getHomeDir()+"/Documents/workspace/algorihms/algs4-data/");
#else
    const std::string Algs4File::algs4Dir=std::string(getHomeDir()+"/workspace/algorihms/algs4-data/"); 
#endif

}

#endif
