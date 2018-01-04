import java.util.Scanner;
class p2{
	public static Scanner in=new Scanner(System.in);
	public static void main(String[] args){
		System.out.println("enter the size of array");
		int n;
		n=in.nextInt();
		int arr[]=new int[n];


		try{
					try{
			 int c,d,e;
			 System.out.println("enter the two numbers to be divided");
			 c=in.nextInt();
			 d=in.nextInt();
			 e=c/d;
			 System.out.println("answer is "+e);

			}
			catch(ArithmeticException e){System.out.println("you cannot divide niumber by zero");} 

				
		try{
			arr[7]=4;
			arr[100]=10;
		}  
   		catch(ArrayIndexOutOfBoundsException e){System.out.println("accesing array index out of bound");}	  
   		}  
  
   		catch(Exception e){System.out.println("exception handled");}  
   
 }  	
}  