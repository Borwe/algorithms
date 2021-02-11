#include "data/date.h"
#include <data/transaction.h>
#include "printer.h"

Transaction::Transaction(const std::string name,const Date date,double amount)
    :name(name),d(date),amount(amount){

}


Transaction Transaction::readTransactionFromInput(){
    std::string customer=
        DataHandler::promptForReturn("Enter name of customer: ");

    Date d=Date::readDates();

    double amount =
        DataHandler::promptForReturn<double>("Enter amount: ");

    return Transaction(customer,d,amount);
}
