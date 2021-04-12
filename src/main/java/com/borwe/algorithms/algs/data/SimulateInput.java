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
import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

/**
 *
 * @author brian
 */
public class SimulateInput {
	
	public static final String algsFileLocs=System
			.getProperty("user.home")+
			"/workspace/algorihms/algs4-data";
	
	public static void simulateWordsFromFileInput(String fileName) throws IOException{
		var words=DataInput.getWordsFromFile(fileName);

		var currInput=System.in;

		for(String word:words){
			ByteArrayInputStream arr=new ByteArrayInputStream(word.getBytes());
			System.setIn(arr);
			arr.close();
		}

		System.setIn(currInput);
	}

	public static void simulateLineFromFileInput(String fileName,Simulator simulator) throws IOException{
		var lines=DataInput.getLinesFromFile(fileName);

		var currInput=System.in;

		try{

			for(String line:lines){
				InputStream arr=new ByteArrayInputStream(line
						.getBytes("UTF-8"));
				System.setIn(arr);
			}

			simulator.simulate();
		}finally{

			System.setIn(currInput);
		}

	}

	public static Queue<String> getUserInputLine(String prompt){
		//used to get input
		Queue<String> inputs=new Queue<>();
		
		//prompt user for input
		System.out.println(prompt);
		
		Scanner scanner=new Scanner(System.in);
		while(scanner.hasNextLine()){
			String line=scanner.nextLine();
			if(line.trim().isEmpty()){
				break;
			}
			inputs.enqueue(line);
		}
		
		return inputs;
	}

	public static Queue<String> getUserInputWords(String prompt){
		Queue<String> inputs=getUserInputLine(prompt);
		Queue<String> words=new Queue<>();

		while(inputs.isEmpty()==false){
			String line=inputs.dequeue();
			words.enqueue(line.trim().split("\\s"));
		}

		return words;
	}

	public static String getFileFullName(String fileName){
		return algsFileLocs+"/"+fileName;
	}
}
