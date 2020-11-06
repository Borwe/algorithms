#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"
#include "queue.h"

void fillBracketAndNumberStacks(Stack<char> &bracket,
        Stack<std::string> &number,std::string &stringToFill){
    
    std::string holdNumAndSum("");
    for(char c:stringToFill){
        if(c=='+' || c=='-' || std::isdigit(c)){
            holdNumAndSum+=c;
            continue;
        }
        if(c=='*' || c==')' ){
            bracket.push(c);
            if(holdNumAndSum.empty()==false){
                number.push(holdNumAndSum);
            }
            holdNumAndSum="";
        }
    }
            std::cout<<"BBBMMMMM: "<<bracket.toString()<<std::endl;
            std::cout<<"HHHMMMMM: "<<number.toString()<<std::endl;
}

std::string normalize(std::string value_passed){
    std::string result;

    Stack<std::string> numberAndSumMinuses;
    Stack<char> bracketsAndMulti;
    Stack<std::string> numbersWithBrackets;
    std::string resultQueue="";

    //fill in the number and bracketsMulti stacks
    fillBracketAndNumberStacks(bracketsAndMulti,
            numberAndSumMinuses,value_passed);


    //loop through brackets, filling in all
    //brackets with numbers putting results into numbersWithBrackets
    //then if numbers is empty, start popping from numbers with brackets
    //for each pop of bracketsAndMulti
    //if you meet a * then pop numbersWithBrackets twice
    //if you meet a ) , then pop numbersWithBrackets and encapsulate
    //in ()
    //after each add to Queue resultQueue
    while(bracketsAndMulti.isEmpty()==false){
        char c=bracketsAndMulti.pop();
        if(c==')'){
            if(numberAndSumMinuses.isEmpty()==false){
                std::string number_brackets="("+numberAndSumMinuses.pop()+")";
                numbersWithBrackets.push(number_brackets);
            }else{
                resultQueue="("+numbersWithBrackets.pop()+")";
            }
            continue;
        }

        if(c=='*'){
            if(numbersWithBrackets.isEmpty()){
                //meaning don't allow ending none
                //when getting the '*' operator
                std::cerr<<"How is it possible to have empty number brackets?\n"<<std::endl;
                throw std::runtime_error("How is it possible to have empty number brackets?");
            }

            if(numbersWithBrackets.size()%2==0 &
                    numbersWithBrackets.size()>=2){
                std::cout<<"asdadadjsadnajsdnjnddd"<<std::endl;
                std::string left=numbersWithBrackets.pop();
                std::string right=numbersWithBrackets.pop();
                std::string main=left+"*"+right;
                resultQueue+=main;
                std::cout<<"Wasdasd: "<<resultQueue<<std::endl;
            }else {
                resultQueue+="*"+numbersWithBrackets.pop();
                std::cout<<"WAAAAAH: "<<resultQueue<<std::endl;
            }
        }
    }

    return result;
}

int main(){
    std::string value_passed("1+2)*3-4)*5-6)))");
    std::cout<<"Turning "<<value_passed<<" to propert string:\n";
    std::string proper_sum=normalize(value_passed);
    std::cout<<"Done: \n";
    std::cout<<proper_sum<<"\n";
    std::cout<<"YEAH BITCHES\n";
    return 0;
}
