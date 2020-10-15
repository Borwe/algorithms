#include <iostream>
#include "queue.h"
#include "stack.h"


bool validateIfCanHappen(Queue<int> &q){
    bool result=false;

    Stack<int> stack;

    //get where to start looping from
    int i=0;

    while(q.size()!=0){
        int valtoPop=q.dequeue();

        //fill stack until we reach the value 
        for(;i<=valtoPop;i++){
            stack.push(i);
        }

        i=valtoPop;
        
        //then pop
        int check=stack.pop();
        if(check!=valtoPop){
            result=false;
            break;
        }else{
            result=true;
        }

    }

    return result;
}

int main(){
    auto a=Queue<int>::fillValues(4,3,2,1,0,9,8,7,6,5);
    auto b=Queue<int>::fillValues(4,6,8,7,5,3,2,9,0,1);
    auto c=Queue<int>::fillValues(2,5,6,7,4,8,9,3,1,0);
    auto d=Queue<int>::fillValues(4,3,2,1,0,5,6,7,8,9);
    auto e=Queue<int>::fillValues(1,2,3,4,5,6,9,8,7,0);
    auto f=Queue<int>::fillValues(0,4,6,5,3,8,1,7,2,9);
    auto g=Queue<int>::fillValues(1,4,7,9,8,6,5,3,0,2);
    auto h=Queue<int>::fillValues(2,1,4,3,6,5,8,7,9,0);


    std::cout<<"A."<<validateIfCanHappen(a)<<"\n";
    std::cout<<"B."<<validateIfCanHappen(b)<<"\n";
    std::cout<<"C."<<validateIfCanHappen(c)<<"\n";
    std::cout<<"D."<<validateIfCanHappen(d)<<"\n";
    std::cout<<"E."<<validateIfCanHappen(e)<<"\n";
    std::cout<<"F."<<validateIfCanHappen(f)<<"\n";
    std::cout<<"G."<<validateIfCanHappen(g)<<"\n";
    std::cout<<"H."<<validateIfCanHappen(h)<<"\n";

    return 0;
}
