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
