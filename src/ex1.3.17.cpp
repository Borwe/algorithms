#include "printer.h"
#include "data/date.h"

int main(int argc,char **argv){
    DataHandler::Printer::print("Got: ").println(argc,argv);
    return 0;
}
