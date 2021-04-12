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
package com.borwe.algorithms.info;

import com.borwe.algorithms.algs.data.Printer;

/**
 *
 * @author brian
 */
public class Date {

	private final int month;
	private final int day;
	private final int year;
	
	public Date(String date){
		String fields[]=date.split("/");
		this.month=Integer.parseInt(fields[0]);
		this.day=Integer.parseInt(fields[1]);
		this.year=Integer.parseInt(fields[2]);
	}

	public static Integer[] readDates(String date){
		Integer [] results=new Integer[3];

		Date d=new Date(date);

		results[0]=d.month;
		results[1]=d.day;
		results[2]=d.year;

		return results;
	}

	public int getMonth() {
		return month;
	}

	public int getDay() {
		return day;
	}

	public int getYear() {
		return year;
	}

	@Override
	public String toString() {
		return "Date[" + "month=" + month + ", day=" + day + ", year=" + year + ']';
	}
}
