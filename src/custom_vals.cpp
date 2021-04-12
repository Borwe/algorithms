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


#include "custom_vals.h"
#include <ostream>

namespace DataHandler{
    
    Bool::Bool(bool x){
        this->val=x;
    }

    std::ostream &operator<<(std::ostream &os,const Bool &bs){
        if(bs.val==true){
            os<<"true";
        }else if(bs.val==false){
            os<<"false";
        }
        return os;
    }

    const bool Bool::operator==(const Bool &bs)const{
        return bs.val==this->val;
    }
    const bool Bool::operator==(const bool &bs)const{
        return this->val==bs;
    }

    bool operator==(const bool &b, const Bool &bs){
        return b==bs.val;
    }
}
