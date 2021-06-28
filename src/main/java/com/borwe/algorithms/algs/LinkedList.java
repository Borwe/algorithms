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

import java.util.Iterator;

/**
 *
 * @author brian
 */
public class LinkedList<T> implements Iterable<T> {

	private Node<T> first;
	private int N;


	public LinkedList() {
		first=null;
		N=0;
	}

	public boolean  isEmpty(){
		if(N==0){
			return true;
		}
		return false;
	}

	public int size(){
		return N;
	}

	public void add(T item){
		if(isEmpty()){
			first=new Node<>();
			first.item=item;
			first.next=null;
		}else{
			Node current=null;
			for(current=first;current.next!=null;current=current.next){}

			Node addition=new Node();
			addition.item=item;
			current.next=addition;
		}
		++N;
	}

	public void deleteLastNode(){
		if(isEmpty()==false){
			if(size()==1)
				first=null;
			else{
				Node current=first;
				for(int i=0;i<size()-2;++i){
					current=current.next;
				}
				current.next=null;
			}

			--N;
		}
	}

	/**
	 * Return true if element deleted
	 * @param position
	 * @return 
	 */
	public boolean delete(int position){
		if(position<N && position>=0 ){
			if(position==0){
				//meaning delete the first field
				first=first.next;
			}else if(position==N-1){
				//meaning deleting at the end
				Node current=first;
				for(int i=0;i<N-2;++i){
					current=current.next;
				}
				current.next=null;
			}else{
				//meaning it is an element in the middle
				Node leftEnd=first; //of element
				Node rightEnd=first; //of element
				for(int i=0;i<position;++i){
					leftEnd=leftEnd.next;
				}
				rightEnd=leftEnd.next.next;

				leftEnd.next=rightEnd;
			}
			--N;
			return true;
		}
		return false;
	}

	public static <T> boolean find(final LinkedList<T> list,T key){
		for(T t:list){
			if(t.equals(key)){
				return true;
			}
		}
		return false;
	}

	public void removeAfter(T item){
		if(isEmpty() || !find(this, item))
			return;

		boolean found=false;
		int position=-1;
		for(T t:this){
			if(t== item || t.equals(item) ){
				++position;
				found=true;
				break;
			}
			++position;
		}

		if(found==true){
			delete(position);
		}
	}

	@Override
	public Iterator<T> iterator() {
		return new ListIterator();
	}

	class ListIterator implements Iterator<T>{

		private Node<T> current=first;

		@Override
		public boolean hasNext() {
			return current!=null;
		}

		@Override
		public T next() {
			T item=current.item;
			current=current.next;

			return item;
		}

	}

	@Override
	public synchronized String toString() {
		var buffer=new StringBuffer();

		buffer.append("[ ");

		for(T t:this){
			buffer.append(t);
			buffer.append(", ");
		}

		if(!isEmpty()){
			buffer=new StringBuffer(buffer.substring(0, buffer.length()-2));
		}

		buffer.append(" ]");

		return buffer.toString();
	}
}
