#include "data/date.h"
#include <cstdlib>
#include <data/transaction.h>
#include "printer.h"
#include "queue.h"
#include <assert.h>

Transaction::Transaction(const std::string name,const Date date,double amount)
    :name(name),d(date),amount(amount){

}


Queue<Transaction> Transaction::readTransaction(int argc,char **argv){
    Queue<Transaction> transactions;
    assert(argc % 3 ==0); //make sure only three value groups where sent

    int limit=argc/3;
    for(int group_loop=0,in_loop=0;group_loop<limit;++group_loop){
        int count_for_group=0;
        Queue<std::string> group_values;
        while(count_for_group<3){
            group_values.enqueue(argv[in_loop]);
            ++in_loop;
            ++count_for_group;
        }

        std::string customer_name=group_values.dequeue();
        std::string date=group_values.dequeue();
        const char *amount=group_values.dequeue().c_str();
        char *end;
        Transaction t(customer_name,
                Date(date),
                strtod(amount,&end));
        
        transactions.enqueue(std::move(t));
    }
    return transactions;
}


std::ostream &operator<<(std::ostream &os,Transaction &trans){
    os<<"[ "<<trans.name<<","<<trans.d<<","<<trans.amount<<" ]";
    return os;
}
