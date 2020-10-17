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
public class Bag<Item> implements Iterable<Item>{
	
	private Node<Item> first;

	public void add(Item item){
		var oldFirst=first;
		first=new Node<>();
		first.item=item;
		first.next=oldFirst;
	}

	@Override
	public Iterator<Item> iterator() {
		return new BasicIterator<>(first);
	}

}
