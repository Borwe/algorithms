/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.algs.data;

/**
 *
 * @author brian
 */
public class Printer {
	private Printer(){

	}

	private static Printer printer=new Printer();

	private <T> String getStringFromArray(T[] valuePassed){
		
		StringBuffer buffer=new StringBuffer();
		for(T t:valuePassed){
			buffer.append(t);
			buffer.append(", ");
		}

		String toPrint=buffer.substring(0, buffer.length()-2);
		return toPrint;
	}

	public static <T> Printer print(T[] gotten) {

		System.out.print(printer.getStringFromArray(gotten));

		return printer;
	}

	public static <T> Printer println(T[] gotten){
		System.out.println(printer.getStringFromArray(gotten));
		return printer;
	}
	
	public static <T> Printer print(T gotten) {
		System.out.print(gotten);

		return printer;
	}

	public static <T> Printer println(T gotten){
		System.out.println(gotten);
		return printer;
	}
	
	public static Printer newLine(){
		println("");
		return printer;
	}
}
