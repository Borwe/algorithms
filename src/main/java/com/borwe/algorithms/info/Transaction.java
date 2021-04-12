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
