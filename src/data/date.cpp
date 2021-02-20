#include "data/date.h"
#include "printer.h"
#include "queue.h"
#include <cassert>
#include <ostream>

std::ostream &operator<<(std::ostream &os,Date &d){
    os<<d.month<<"/"<<d.day<<"/"<<d.year;
    return os;
}

Queue<int> Date::parseDateIntsFromString(const std::string &input){
    Queue<int> holdValues;
    std::string tempValue;
    for(int i=0;i<input.size();++i){
        char c=input[i];
        if(i==(input.size()-1)){
            tempValue+=c;
            int r=atoi(tempValue.c_str());
            holdValues.enqueue(r);
            continue;
        }
        if(c=='/'){
            int r=atoi(tempValue.c_str());
            holdValues.enqueue(r);
            tempValue="";
            continue;
        }
        tempValue+=c;
    }

    return holdValues;
}

bool Date::operator!=(const Date &date){
    if(this->month==date.month &&
            this->year == date.year &&
            this->day == date.day){
        return true;
    }
    return false;
}

Queue<Date> Date::readDates(int args,char **argv){
    Queue<Date> queue;

    for(int i=1;i<args;++i){
        std::string d(argv[i]);
        queue.enqueue(d);
    }
    return queue;
}

Date::Date(std::string date){
    auto values=parseDateIntsFromString(date);
    assert(values.size()==3);
    month=values.dequeue();
    day=values.dequeue();
    year=values.dequeue();
}

Date::Date(const Date &d):month(d.month),day(d.day),year(d.year){
    
}
