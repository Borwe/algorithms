package com.borwe.algorithms.exercises;

import com.borwe.algorithms.algs.Queue;
import com.borwe.algorithms.algs.Stack;
import com.borwe.algorithms.algs.data.SimulateInput;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author brian
 */
public class Ex1_3_9 {

	private static String
		 normalize(Queue<String> strings){
		Stack<String> operators=new Stack<>();
		Stack<String> operands=new Stack<>();

		for(String s:strings){
			switch(s){
				case "*":
				case "+":
				case "-":
				case "/": operators.push(s);break;
				case ")": {
					String operator=operators.pop();
					String val2=operands.pop();
					String val1=operands.pop();
					operands.push("( "+val1+" "+operator
						+" "+val2+" )");
				} break;
				default: operands.push(s);
			}
		}

		return operands.pop();
	}

	public static void main(String[] args) {
		//get input from user
		Queue<String> words=SimulateInput.getUserInputWords("Enter some words");

		System.err.println("INPUT:"+words.toString());
		System.err.println("OUPUT: "+normalize(words));

	}
	
}
