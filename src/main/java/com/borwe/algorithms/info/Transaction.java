/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.info;

/**
 *
 * @author brian
 */
public class Transaction {
	
	private final String customer;
	private final Date date;
	private final Double amount;

	public Transaction(String args){
		String []splits=args.split(" ");
		customer=splits[0];
		date=new Date(splits[1]);
		amount=Double.parseDouble(splits[2]);
	}

	public static Transaction[] readTransactions(String[] args){
		String transactionsInputs[]=args;
		int size=transactionsInputs.length;

		Transaction transactions[]=new Transaction[size/3];

		for(int j=0,i=0,k=0;j<size;++k){
			StringBuilder builder=new StringBuilder();

			while(i<3){
				builder.append(transactionsInputs[j]);
				builder.append(" ");
				++i;
				++j;
			}

			i=0;
			transactions[k]=new Transaction(builder.toString());
		}

		return transactions;
	}

	@Override
	public String toString() {
		StringBuilder builder=new StringBuilder();

		builder.append("[ customer: "+customer)
				.append(" , Date: "+date)
				.append(" , amount: "+amount)
				.append(" ]");

		return builder.toString();
	}

	
}
