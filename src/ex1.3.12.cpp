#include "stack.h"
#include <iostream>
#include "printer.h"

int main(){
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);

    DataHandler::Printer::println("Stack1:").println(stack1);

    auto stack2=Stack<int>::copy(stack1);
    DataHandler::Printer::println("Stack2:").println(stack2);
    return 0;
}
