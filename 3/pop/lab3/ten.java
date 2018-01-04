import java.util.Scanner;
class ten{
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
			if(a[i]==10)
			{
				count=count+1;
			}
		
		}
		
		if(count==3){
			System.out.println("true");
		}
		else{
			System.out.println("false");
		}


	}
}