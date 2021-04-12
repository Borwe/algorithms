/* 
 * Copyright (C) 2021 brian
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
