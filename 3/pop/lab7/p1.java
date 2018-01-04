import java.util.Scanner;
class p1{
	public static Scanner in=new Scanner(System.in);
	public static void main(String[] args){
		System.out.println("enter the size of array");
		int n;
		n=in.nextInt();
		int arr[]=new int[n];
		System.out.println("enter the array elements");
		for(int i=0;i<n;i++){
			arr[i]=in.nextInt();
		}
		System.out.println("enter index pair to be divided");
		int c,d,ea;
		c=in.nextInt();
		d=in.nextInt();
		try{  
    		int a[]=new int[5];  
    		ea=arr[c]/arr[d];
    		System.out.println("ans is"+ea);  
   		}  
   		catch(ArithmeticException e){System.out.println("you cannot divide niumber by zero");}  
   		catch(ArrayIndexOutOfBoundsException e){System.out.println("accesing array index out of bound");}  
   		catch(Exception e){System.out.println("invalid operation");}  
   
 }  	
}  
	
