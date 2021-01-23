#ifndef DATE_SEGWICK_CUSTOM
#define DATE_SEGWICK_CUSTOM

#include <string>
#include "queue.h"
#include <ostream>

class Date;

std::ostream &operator<<(std::ostream &os,Date &d);

class Date{
private:
    //private variables
    int month;
    int day;
    int year;

    Queue<int> parseDateIntsFromString(const std::string &input); 

    friend std::ostream &operator<<(std::ostream &os,Date &d);


public:
    //public variables

    //MM/DD/YY
    Date(std::string date);

    /**
     * Read dates from standard input
     */
    static Date readDates();
};

#endif
