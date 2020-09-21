#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <sstream>

namespace DataHandler{


    class Algs4File{
    private:
        static const std::string algs4Dir;
        std::string fileName;
    public:
        Algs4File(std::string fileName);
        
        std::vector<std::string> getLines() const;
        std::vector<std::string> getWords() const;

        std::stringstream simulateWordInput()const;
    };
    const std::string Algs4File::algs4Dir="/home/brian/workspace/algorihms/algs4-data/";

}

#endif
