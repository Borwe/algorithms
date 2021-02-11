#include "printer.h"
#include "data/date.h"

int main(int argc,char **argv){
    DataHandler::Printer::println("Check validity");
    Date d=Date::readDates();
    DataHandler::Printer::println(d);
    return 0;
}
