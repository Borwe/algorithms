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

}

#endif
