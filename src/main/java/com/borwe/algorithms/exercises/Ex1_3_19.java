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
