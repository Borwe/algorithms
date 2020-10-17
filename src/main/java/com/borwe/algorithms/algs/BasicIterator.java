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
public class BasicIterator<Item> implements Iterator<Item>{

	private Node<Item> current;

	public BasicIterator(Node<Item> first) {
		this.current=first;
	}

	@Override
	public boolean hasNext() {
		return current!=null;
	}

	@Override
	public Item next() {
		Item item=current.item;
		current=current.next;
		return item;
	}

	
}
