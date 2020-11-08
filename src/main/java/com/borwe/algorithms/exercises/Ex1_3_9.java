package com.borwe.algorithms.exercises;

import com.borwe.algorithms.algs.Queue;
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

	public static void main(String[] args) {
		//get input from user
		Queue<String> words=SimulateInput.getUserInputWords("Enter some words");
		System.out.println("Words are:");
		System.out.println(words);
	}
	
}
