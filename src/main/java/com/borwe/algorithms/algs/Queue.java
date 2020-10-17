/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.algs;

import com.borwe.algorithms.algs.data.SimulateInput;
import com.borwe.algorithms.algs.data.Simulator;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import java.io.IOException;
import java.util.Iterator;

/**
 *
 * @author brian
 */
public class Queue<Item> implements Iterable<Item>{
	
	private Node<Item> first;
	private Node<Item> last;
	private int N;

	public boolean isEmpty(){
		return first==null;
	}

	public int size(){
		return N;
	}

	public void enqueue(Item item){
		Node oldLast=last;
		last=new Node<>();
		last.item=item;
		if(isEmpty())
			first=last;
		else
			oldLast.next=last;
		N++;
	}

	public Item dequeue(){
		Item item=first.item;
		first=first.next;
		N--;
		if(isEmpty())last=null;
		return item;
	}

	@Override
	public Iterator<Item> iterator() {
		return new BasicIterator<Item>(first);
	}

	public static void main(String[] args) throws IOException {
		Simulator simulaor=()->{
			Queue<String> q=new Queue<>();

			while(!StdIn.isEmpty()){
				String item=StdIn.readString();
				if(!item.equals("-"))
					q.enqueue(item);
				else if(!q.isEmpty())
					StdOut.print(q.dequeue()+" ");
			}
			StdOut.println("("+q.size()+" left on queue)");
		};

		SimulateInput
				.simulateLineFromFileInput(
						SimulateInput.getFileFullName("tobe.txt"),
						simulaor);
	}
}