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
    Date(const Date &date);

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
