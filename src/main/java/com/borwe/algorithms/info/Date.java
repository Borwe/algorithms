/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
