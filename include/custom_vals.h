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

#ifndef CUSTOM_VALS_CUSTOM_H
#define CUSTOM_VALS_CUSTOM_H


#include <iostream>
#include <ostream>
#include "dymamic_preproc.h"

namespace DataHandler{

class DYNAMIC_SPEC Bool{
private:
    bool val;
public:
    Bool(bool x);

    friend DYNAMIC_SPEC std::ostream 
        &operator<<(std::ostream &os, const Bool &bs);
    DYNAMIC_SPEC const bool operator==(const Bool &bs) const;
    DYNAMIC_SPEC const bool operator==(const bool &bs) const;
    friend DYNAMIC_SPEC bool operator==(const bool &b, const Bool &bs);
};

}

#endif
