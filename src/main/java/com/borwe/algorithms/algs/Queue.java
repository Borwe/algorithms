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
