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
public class Ex1_3_19{

	public static void main(String[] args) {
		var integerList=new LinkedList<Integer>();
		Printer.println("Adding: 1,2,3,4");
		integerList.add(1);
		integerList.add(2);
		integerList.add(3);
		integerList.add(4);

		Printer.println("Now has: "+integerList)
				.println("Removing last element");
		integerList.deleteLastNode();

		Printer.println("Now has: "+integerList);

		Printer.println("Now using list with only one element");
		integerList=new LinkedList<>();
		integerList.add(55);
		Printer.println("Now has: "+integerList).println("And removing it...");
		integerList.deleteLastNode();
		Printer.println("Now has: "+integerList);
	}

}
