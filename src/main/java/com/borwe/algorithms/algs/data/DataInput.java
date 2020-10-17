/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
