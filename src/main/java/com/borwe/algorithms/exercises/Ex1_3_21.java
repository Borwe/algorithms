/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.exercises;

import com.borwe.algorithms.algs.LinkedList;
import com.borwe.algorithms.algs.data.Printer;

/**
 *
 * @author brian
 */
public class Ex1_3_21 {
	public static void main(String[] args) {
		Printer.println("Creating LinkedList with strings");
		LinkedList<String> stringsList=new LinkedList<>();
		stringsList.add("yolo");
		stringsList.add("zoo");
		stringsList.add("shoo");
		stringsList.add("boom");

		Printer.print("Gotten: ").println(stringsList.toString());
		Printer.println("Check for 'ex' string: "+stringsList.find("ex"));
		Printer.println("Checking for 'zoo' string: "+stringsList.find("zoo"));
	}
}
