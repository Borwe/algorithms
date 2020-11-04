package com.borwe.algorithms.exercises;

import com.borwe.algorithms.algs.Queue;
import com.borwe.algorithms.algs.Stack;

public class Ex1_3_3{

    static class SuccessValue{
        public final boolean success;
        public final String option;

        public SuccessValue(boolean success,String option){
            this.success=success;
            this.option=option;
        }
    }

    static SuccessValue checkIfPossible(String test,Queue<Integer> valuesToHappen){
        Stack<Integer> testing=new Stack<>();

        Queue<Integer> queue=new Queue<>(0,1,2,3,4,5,6,7,8,9);

        while(valuesToHappen.isEmpty()==false){

                // pop a value of it
                var whatToPop=valuesToHappen.dequeue();

                //increment testing with all values in queue until we reach
                // value of whatToPop
                while(queue.isEmpty()==false && queue.peek()<=whatToPop){
                    //keep adding the values to testing stack
                    //while removing them from queue
                    testing.push(queue.dequeue());
                }

                //pop value from testing queue, and check if it matches
                //whatTopop
                if(whatToPop==testing.pop()){
                    continue;
                }else{
                    return new SuccessValue(false, test);
                }
        }
        return new SuccessValue(true, test);
    }

    static void showResult(SuccessValue successValue){
        System.out.println("Option: "+successValue.option+
                " has Passed? : "+successValue.success);
    }

    public static void main(String... args){

        System.out.println("Starting");

        showResult(checkIfPossible("A",
                    new Queue<Integer>(4,3,2,1,0,9,8,7,6,5)));
        showResult(checkIfPossible("B",
                    new Queue<Integer>(4,6,8,7,5,3,2,9,0,1)));
        showResult(checkIfPossible("C",
                    new Queue<Integer>(2,5,6,7,4,8,9,3,1,0)));
        showResult(checkIfPossible("D",
                    new Queue<Integer>(4,3,2,1,0,5,6,7,8,9)));
        showResult(checkIfPossible("E",
                    new Queue<Integer>(1,2,3,4,5,6,9,8,7,0)));
        showResult(checkIfPossible("F",
                    new Queue<Integer>(0,4,6,5,3,8,1,7,2,9)));
        showResult(checkIfPossible("G",
                    new Queue<Integer>(1,4,7,9,8,6,5,3,0,2)));
        showResult(checkIfPossible("H",
                    new Queue<Integer>(2,1,4,3,6,5,8,7,9,0)));

        System.out.println("Done");
    }
}
