#ifndef TRANSACTION_HEADER_CUSTOM
#define TRANSACTION_HEADER_CUSTOM

#include <data/date.h>
#include <string>
#include "queue.h"

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
};

#endif
