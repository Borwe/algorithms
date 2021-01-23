#include "printer.h"
#include "data/date.h"

int main(int argc,char **argv){
    DataHandler::println("Check validity");
    Date d=Date::readDates();
    DataHandler::println(d);
    return 0;
}
