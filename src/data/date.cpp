#include "data/date.h"
#include "printer.h"
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

Date Date::readDates(){
    std::string input=
        DataHandler::Printer::promptForReturn("Give date as input, MM/DD/YYYY");

    return Date(input);
}

Date::Date(std::string date){
    auto values=parseDateIntsFromString(date);
    assert(values.size()==3);
    month=values.dequeue();
    day=values.dequeue();
    year=values.dequeue();
}
