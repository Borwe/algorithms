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

	public static <T> Stack<T>  copy(Stack<T> stack){
		Stack<T> temp=new Stack<>();
		Stack<T> copy=new Stack<>();
		for(T t:stack){
			temp.push(t);
		}

		for(T t:temp){
			copy.push(t);
		}
		return copy;
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
