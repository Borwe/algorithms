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

/**
 *
 * @author brian
 */
public class Ex1_3_15 {
	public static void main(String[] args) {
		Queue<String> values=new Queue<>(args);

		var iterator=values.iterator();
		while(iterator.hasNext()){
			String val=iterator.next();
			if(iterator.hasNext()==false){
				System.out.println(val);
			}
		}
	}
}
