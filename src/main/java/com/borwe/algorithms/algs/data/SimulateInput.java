/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.borwe.algorithms.algs.data;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

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

	public static String getFileFullName(String fileName){
		return algsFileLocs+"/"+fileName;
	}
}
