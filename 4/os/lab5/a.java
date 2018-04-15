import java.util.*;
import java.io.*;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
class a{
	public static void main(String args[]){

		try{
		  BufferedReader out =new BufferedReader(new FileReader("output.txt"));
String line;
		while((line=out.readLine())!=null){
System.out.println(line);
}  
		out.close();
		  BufferedReader out =new BufferedReader(new FileReader("output.txt"));
String line;
		while((line=out.readLine())!=null){
System.out.println(line);
}  
		out.close();
		  BufferedReader out =new BufferedReader(new FileReader("output.txt"));
String line;
		while((line=out.readLine())!=null){
System.out.println(line);
}  
		out.close();
		  BufferedReader out =new BufferedReader(new FileReader("output.txt"));
String line;
		while((line=out.readLine())!=null){
System.out.println(line);
}  
		out.close();
			}
		catch(IOException e){
		System.out.println("not opend");
		}
	
	}
}
