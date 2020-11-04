#include <iostream>
#include "queue.h"
#include "stack.h"


bool validateIfCanHappen(Queue<int> &qCheckup){
    Stack<int> toFillAndPop;

    Queue<int> queue=Queue<int>::fillValues(0,1,2,3,4,5,6,7,8,9);

    while(!qCheckup.isEmpty()){
        int valtoPop=qCheckup.dequeue();
        
        while(queue.isEmpty()==false && queue.peek()<=valtoPop){
            toFillAndPop.push(queue.dequeue());
        }

        if(valtoPop==toFillAndPop.pop()){
            continue;
        }else{
            return false;
        }
    }

    return true;
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


    std::cout<<"a."<<validateIfCanHappen(a)<<"\n";
    std::cout<<"b."<<validateIfCanHappen(b)<<"\n";
    std::cout<<"c."<<validateIfCanHappen(c)<<"\n";
    std::cout<<"d."<<validateIfCanHappen(d)<<"\n";
    std::cout<<"e."<<validateIfCanHappen(e)<<"\n";
    std::cout<<"f."<<validateIfCanHappen(f)<<"\n";
    std::cout<<"g."<<validateIfCanHappen(g)<<"\n";
    std::cout<<"h."<<validateIfCanHappen(h)<<"\n";

    return 0;
}
