/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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

	public static <T> boolean find(final LinkedList<T> list,String key){
		for(T t:list){
			if(t.equals(key)){
				return true;
			}
		}
		return false;
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
