#ifndef TRANSACTION_HEADER_CUSTOM
#define TRANSACTION_HEADER_CUSTOM

#include <data/date.h>
#include <string>

class Transaction{
private:
    //private variables
    Date d;
    std::string name;
    double amount;
public:
    //public variables

    Transaction(std::string name,Date date,double amount);
    Transaction(Transaction &&trans) = default;

    Transaction readTransactionFromInput();
};

#endif
