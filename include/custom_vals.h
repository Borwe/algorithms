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
