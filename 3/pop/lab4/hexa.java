import java.util.Scanner;
class hexa{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("enter a number");
		int n;
		int[] a=new int[10];
		n=input.nextInt();
		int i=0;
		while(n>0){
		
			a[i]=n%16;
			
			n=n/16;
			i++;


		}
		for(int j=i-1;j>=0;j--)
			System.out.print(a[j]);
	}
}