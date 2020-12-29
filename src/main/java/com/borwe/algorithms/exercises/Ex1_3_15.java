/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.exercises;

import com.borwe.algorithms.algs.Queue;

/**
 *
 * @author brian
 */
public class Ex1_3_15 {
	public static void main(String[] args) {
		Queue<String> values=new Queue<>(args);

		var iterator=values.iterator();
		while(iterator.hasNext()){
			String val=iterator.next();
			if(iterator.hasNext()==false){
				System.out.println(val);
			}
		}
	}
}
