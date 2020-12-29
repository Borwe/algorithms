package com.borwe.algorithms.exercises;

import com.borwe.algorithms.algs.Queue;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author brian
 */
public class Ex1_3_13 {

	private static void checkIfOccurs(String name,Queue<Integer> q){
		if(q==null || q.isEmpty()){
			System.out.println(name+"=error");
			return;
		}

		Queue<Integer> checker=new Queue<>();
		boolean result=false; //to hold the final result

		for(int i=0;i<10;++i){
			int v=q.peek();

			
			if(checker.isEmpty()==false && checker.peek()==v){
				v=q.dequeue();
				int c=checker.dequeue();
				result=true;
				checker.enqueue(i);
			}else{
				result=false;
				checker.enqueue(i);
			}
		}

		if(result){
			System.out.println(name+"=Does occur");
		}else{
			System.out.println(name+"=Does not occur");
		}
	}
	
	public static void main(String[] args) {
		Queue<Integer> a=new Queue<>(0,1,2,3,4,5,6,7,8,9);
		Queue<Integer> b=new Queue<>(4,6,8,7,5,3,2,9,0,1);
		Queue<Integer> c=new Queue<>(2,5,6,7,4,8,9,3,1,0);
		Queue<Integer> d=new Queue<>(4,3,2,1,0,5,6,7,8,9);

		checkIfOccurs("a",a);
		checkIfOccurs("b",b);
		checkIfOccurs("c",c);
		checkIfOccurs("d",d);
	}
}
