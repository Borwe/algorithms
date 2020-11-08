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

    public Queue(){

    }

    public Queue(Item ...items){
        for(Item i:items){
            this.enqueue(i);
        }
    }

    /**
     * Fill items with array of fixed items
     */
    public static <Item> Queue<Item>  generateQueuefromArray(final Item... items){
        Queue<Item> queue=new Queue<>();

        for(Item i:items){
            queue.enqueue(i);
        }
        return queue;
    }

	public boolean isEmpty(){
		return first==null;
	}

	public int size(){
		return N;
	}

	public void enqueue(Item ...items){
		for(Item item:items){
			this.enqueue(item);
		}
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

    public final Item peek(){
        return first.item;
    }

	@Override
	public Iterator<Item> iterator() {
		return new BasicIterator<Item>(first);
	}

    public String toString(){
        String result="";

        StringBuffer out=new StringBuffer();
        for(Item item:this){
            out.append(item.toString());
            out.append(", ");
        }

        result=out.toString();
		if(!result.isEmpty() &&
				result.charAt(result.length()-2)==','){
			
			result=result.substring(0, result.length()-2);
		}

        return result;
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
