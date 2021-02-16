#include "printer.h"

int main(int argc,char **argv){
    DataHandler::Printer::print("Got: ").println(argc,argv);
    return 0;
}
