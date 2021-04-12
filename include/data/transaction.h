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

#ifndef TRANSACTION_HEADER_CUSTOM
#define TRANSACTION_HEADER_CUSTOM

#include <data/date.h>
#include <ostream>
#include <string>
#include "queue.h"
#include <ostream>

class Transaction;


std::ostream &operator<<(std::ostream &os,Transaction &trans);

class Transaction{
private:
    //private variables
    Date d;
    std::string name;
    double amount;
public:
    //public variables

    Transaction(std::string name,Date date,double amount);
    Transaction()=default;
    Transaction(const Transaction &trans) = default;
    Transaction(Transaction &&trans) = default;

    static Queue<Transaction> readTransaction(int argc,char **argv);
    Transaction &operator=(const Transaction &trans)=default;

    friend std::ostream &operator<<(std::ostream &os,Transaction &trans);
};

#endif
