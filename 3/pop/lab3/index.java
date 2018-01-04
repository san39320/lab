import java.util.Scanner;
class index{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int a[]=new int[20];
		System.out.println("enter the size of array");
		int b,count=0;
		b=input.nextInt();
		System.out.println("enter the array elements");
		for(int i=0;i<b;i++)
		{
			a[i]=input.nextInt();
		}
		int start=0;
		int end=b-1,value;
		System.out.println("enter the value to be searched");
		value=input.nextInt();
		int j;
		for(j=0;j<b;j++){
			
			if(value==a[j])
			{
			System.out.println("element found at position "+(j+1));
			break;	
			}
		}


	}
}