//Copyright (C) 2021  Brian Orwe
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.


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
