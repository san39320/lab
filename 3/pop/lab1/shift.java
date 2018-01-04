import java.util.Scanner;
class shift{
	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		System.out.println("enter the number");
		int a=input.nextInt();
		System.out.println("enter the number of places to be shifted");
		int b=input.nextInt();
		int c=(a>>>b);
		int d=(a>>b);
		int e=(a<<b);
		System.out.println("value of unsigned right shift"+c);
		System.out.println("value of right shift"+d);
		System.out.println("value of left shift"+e);

	}
}