/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
