/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.algs;

import com.borwe.algorithms.algs.data.SimulateInput;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import java.io.IOException;
import java.util.Iterator;

/**
 *
 * @author brian
 */
public class Stack<Item> implements Iterable<Item>{
	
	private Node<Item> first;
	private int N;

    public Stack(){

    }

    public Stack(Item ...items){
        for(Item i:items){
            this.push(i);
        }
    }

	public boolean isEmpty(){
		return first==null;
	}

	public int size(){
		return N;
	}

	public void push(Item item){
		Node oldfirst=first;
		first=new Node();
		first.item=item;
		first.next=oldfirst;
		N++;
	}

	public Item pop(){
		Item item=first.item;
		first=first.next;
		N--;
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
        StringBuffer buffer=new StringBuffer();

        for(Item i:this){
            buffer.append(i.toString());
            buffer.append(", ");
        }

        result=buffer.toString();
        result=result.substring(0, result.length()-2);

        return result;
    }

	public static void main(String[] args) throws IOException {
		Stack<String> s=new Stack<>();

		SimulateInput
				.simulateLineFromFileInput(
						SimulateInput.getFileFullName("tobe.txt"),
						()->{

			while (!StdIn.isEmpty()){
				String item=StdIn.readString();
				if(!item.equals("-")){
					s.push(item);
				}else if(!s.isEmpty()){
					StdOut.print(s.pop()+" ");
				}
			}

			StdOut.println("("+s.size()+" left on stack)");
		});
	}
}
