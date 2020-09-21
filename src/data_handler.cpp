#include "data_handler.h"
#include <deque>
#include <fstream>
#include <istream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <filesystem>
#include <boost/algorithm/string.hpp>

namespace DataHandler{
    Algs4File::Algs4File(std::string fileName){
        this->fileName=fileName;
    }

    std::vector<std::string> Algs4File::getLines()const{
        std::vector<std::string> lines;

        std::string fileLocation=this->algs4Dir+this->fileName;
        //get location of file and see if it exists
        if(std::filesystem::exists(this->algs4Dir+this->fileName)==false)
            throw std::runtime_error("file "+this->algs4Dir+this->fileName+ "Doesn't exist'");

        std::ifstream file(fileLocation.c_str());
        std::string line;//for holding a line
        while(std::getline(file,line)){
            lines.push_back(line);
        }
        return lines;
    }

    std::vector<std::string> Algs4File::getWords()const{
        std::vector<std::string> words;

        auto lines=this->getLines();//get the lines in file
        for(auto &line:lines){
            //get the words in the line and store them into words
            std::vector<std::string> line_words;
            boost::split(line_words,line,boost::is_any_of(" "));

            for(auto &word:line_words)
                words.push_back(word);
        }
        return words;
    }

    std::stringstream Algs4File::simulateWordInput()const{
        auto words=this->getWords();
        
        std::stringstream inSim;

        size_t pos=0;
        for(auto &word:words){
            std::cerr<<"WORRD: "<<word<<"\n";
            inSim<<word;
            ++pos;
            if (pos<words.size())
                inSim<<" ";
        }
        return std::move(inSim);
    }
}
