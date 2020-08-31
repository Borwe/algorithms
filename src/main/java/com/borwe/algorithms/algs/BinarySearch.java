/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.algs;

/**
 *
 * @author brian
 */
public class BinarySearch {

	public static int rank(int key, int[] a){
		int lo=0;
		int hi=a.length-1;

		while(lo<=hi){
			int mid=lo+(hi-lo)/2;
			if(key<a[mid])
				hi=mid-1;
			else if(key>a[mid])
				lo=mid+1;
			else
				return mid;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		
	}
}
