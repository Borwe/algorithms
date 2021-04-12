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
package com.borwe.algorithms.algs.data;

import com.borwe.algorithms.algs.Queue;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 *
 * @author brian
 */
public class DataInput {
	
	public static Queue<String> getLinesFromFile(String fileName) throws  IOException{
		Queue<String> lines=new Queue<>();
		Files.lines(Paths.get(fileName)).forEach(line->{
			lines.enqueue(line);
		});

		return lines;
	}

	public static Queue<String> getWordsFromFile(String fileName) throws IOException{
		Queue<String> words=new Queue<>();

		for(String line:getLinesFromFile(fileName)){
			for(String word:line.split(" "))
				words.enqueue(word);
		}

		return words;
	}
}
