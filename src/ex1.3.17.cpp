#include "printer.h"
#include "data/date.h"
#include "data/transaction.h"
#include "queue.h"

int main(int argc,char **argv){
    DataHandler::Printer::print("Got: ").println(argc,argv);
    //decrement last value
    --argc;++argv;
    Queue<Transaction> transactions=Transaction::readTransaction(argc,argv);
    DataHandler::Printer::print("Which is: ").println(transactions);
    return 0;
}
