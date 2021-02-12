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
    Date()=default;

    //MM/DD/YY
    Date(std::string date);

    /**
     * Compare if they match
     */
    bool operator!=(const Date &date);

    /**
     * Read dates from standard input
     */
    static Queue<Date> readDates(int args,char **argv);
};

#endif
