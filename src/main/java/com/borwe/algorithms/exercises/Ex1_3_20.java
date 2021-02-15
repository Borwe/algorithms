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
public class Ex1_3_20 {

	private static LinkedList<Integer> getList(){

		LinkedList<Integer> integerList=new LinkedList<>();
		for(int i=1;i<6;++i){
			integerList.add(i);
		}
		return integerList;
	}
	
	public static void main(String[] args) {
		Printer.println("Adding 1,2,3,4,5");
		var integerList=getList();
		Printer.println("Done: "+integerList).newLine();

		Printer.println("Deleting 1st value");
		integerList.delete(0);
		Printer.println("Done: "+integerList).newLine();

		integerList=getList();
		Printer.println("Deleting last value");
		integerList.delete(integerList.size()-1);
		Printer.println("Done: "+integerList).newLine();

		integerList=getList();
		Printer.println("Deleting in the middle");
		integerList.delete(2);
		Printer.println("Done: "+integerList).newLine();
	}
}
