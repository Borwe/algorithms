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
#include <vector>

//for linux getting home directory
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
#ifdef _WIN32
    const std::string Algs4File::algs4Dir=std::string(getHomeDir()+"/Documents/workspace/algorihms/algs4-data/");
#else
    const std::string Algs4File::algs4Dir=std::string(getHomeDir()+"/Workspace/algorithms/algs4-data/"); 
#endif

    Algs4File::Algs4File(std::string fileName){
        this->fileName=fileName;
    }
    

    Queue<std::string> Algs4File::getLines()const{
        Queue<std::string> lines;

        std::string fileLocation=Algs4File::algs4Dir+this->fileName;
        std::cout<<"FILE @: "<<fileLocation.c_str()<<std::endl;
        //get location of file and see if it exists
        
        std::ifstream file;
        file.open(fileLocation.c_str());
        if(file.is_open()==false)
            throw std::runtime_error("file "+fileLocation+ " Doesn't exist'");

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
            std::stringstream line_words(line);
            std::string word;
            while(line_words >> word)
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


