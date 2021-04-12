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
#include <cmath>
#include <deque>
#include <fstream>
#include <istream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include "queue.h"
#ifndef __GNUC__
    #include <filesystem>
#else
    #if __GNUC__ > 8
        #include <filesystem>
    #elif __clang_major__ > 6
        #include <filesystem>
    #else
        #include <boost/filesystem.hpp>
    #endif
#endif

#include <boost/algorithm/string.hpp>

//for linux
#ifdef __linux__

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#endif

//for windows getting home directory
#ifdef _WIN32
#include <ShlObj.h>
#endif

namespace DataHandler{
    Algs4File::Algs4File(std::string fileName){
        this->fileName=fileName;
    }
    

    Queue<std::string> Algs4File::getLines()const{
        Queue<std::string> lines;

        std::string fileLocation=this->algs4Dir+this->fileName;
        //get location of file and see if it exists
#if __GNUC__ > 8
        if(std::filesystem::exists(this->algs4Dir+this->fileName)==false)
            throw std::runtime_error("file "+this->algs4Dir+this->fileName+ "Doesn't exist'");
#elif __clang_major__ > 6
        if(std::filesystem::exists(this->algs4Dir+this->fileName)==false)
            throw std::runtime_error("file "+this->algs4Dir+this->fileName+ "Doesn't exist'");
#else
        std::string fileToCheckIfExists=this->algs4Dir+this->fileName;
        if(boost::filesystem::exists(boost::filesystem::path(fileToCheckIfExists.c_str()))==false)
            throw std::runtime_error("file "+this->algs4Dir+this->fileName+ "Doesn't exist'");
#endif

        std::ifstream file(fileLocation.c_str());
        std::string line;//for holding a line
        while(std::getline(file,line)){
            lines.enqueue(line);
        }
        return lines;
    }

    Queue<std::string> Algs4File::getWords()const{
        Queue<std::string> words;

        auto lines=this->getLines();//get the lines in file
        for(auto &line:lines){
            //get the words in the line and store them into words
            std::vector<std::string> line_words;
            boost::split(line_words,line,boost::is_any_of(" "));

            for(auto &word:line_words)
                words.enqueue(word);
        }
        return words;
    }

    std::stringstream Algs4File::simulateWordInput()const{
        auto words=this->getWords();
        
        std::stringstream inSim;

        size_t pos=0;
        for(auto &word:words){
            inSim<<word;
            ++pos;
            if (pos<words.size())
                inSim<<" ";
        }
        return std::move(inSim);
    }


    std::string getHomeDir()
        #ifdef _WIN32
        throw()
        #endif
    {
        std::string p;
        #ifdef _WIN32
            //we get parent dir here if on windows 10+
            CHAR path[MAX_PATH];
            if(SHGetFolderPath(NULL,CSIDL_PROFILE,NULL,0,path)!=S_OK){
                throw std::runtime_error("no home dir found, something wen't wrong");
            }else{
                std::string result(path);
                return result;
            }
        #elif defined(__linux__)
            //if linux
            std::string homedir(getpwuid(getuid())->pw_dir);
            return homedir;
        #endif
        return p;
    }
}


