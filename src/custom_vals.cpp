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
