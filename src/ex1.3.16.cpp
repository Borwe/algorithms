#include "printer.h"
#include "data/date.h"
#include "queue.h"

int main(int argc,char **argv){
    DataHandler::Printer::println("Check validity");
    Queue<Date> d=Date::readDates(argc,argv);
    DataHandler::Printer::println(d).println("Done");
    return 0;
}
