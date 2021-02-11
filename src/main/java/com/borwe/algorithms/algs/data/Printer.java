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

	private static final Printer printer=new Printer();
	private Printer(){}
	
	
	public static <T> Printer println(T[] array){
		printer.print(array);
		System.out.println("");

		return printer;
	}

	public static <T> Printer print(T[] array){

		StringBuffer buffer=new StringBuffer("");

		for(T t:array){
			buffer.append(t);
			buffer.append(", ");
		}

		var value=buffer.substring(0,buffer.length()-2);
		System.out.print(value);
		return printer;
	}

	public static <T> Printer print(T obj){
		System.out.print(obj);
		return printer;
	}

	public static <T> Printer println(T obj){
		System.out.println(obj);
		return printer;
	}
}
