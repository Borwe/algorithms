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
    int size=argc-1; //number of items passed
    assert(size % 3 ==0); //make sure only three value groups where sent

    int limit=size/3;
    for(int group_loop=0,in_loop=1;group_loop<limit;++group_loop){
        int count_for_group=0;
        Queue<std::string> group_values;
        while(count_for_group<3){
            group_values.enqueue(argv[in_loop]);
            ++in_loop;
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
