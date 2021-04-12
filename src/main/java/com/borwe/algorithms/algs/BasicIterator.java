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
