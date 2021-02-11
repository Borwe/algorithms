/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.exercises;

import com.borwe.algorithms.algs.data.Printer;
import com.borwe.algorithms.info.Transaction;

/**
 *
 * @author brian
 */
public class Ex1_3_17 {

	public static void main(String[] args) {
		Printer.print("gotten: ").println(args);
		Printer.print("Transcations: ").println(Transaction.readTransactions(args));
	}
	
}
