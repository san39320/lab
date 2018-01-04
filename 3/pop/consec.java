import java.util.Scanner;
import java.util.Arrays;
class consec{
	public static void main(String[] args)
	{
		int n;
		int a[]=new int[50];
		Scanner input=new Scanner(System.in);
		System.out.println("enter the number of elements");
		n=input.nextInt();
		System.out.println("enter array of elements");
		for(int i=0;i<n;i++){
			a[i]=input.nextInt();
		}
		Arrays.sort(a);
		int min=0,max=0,count=0,temp;
		for(int i=0;i<n;i++)
		{
			temp=a[i];
			for(int j=i;j<n;j++)
			{
			if(a[j]==temp)
			{	

				count=count+1;
				System.out.println("count "+count);
				temp=temp+1;
			}
			else
			{
				if(count>max)
					max=count;
				else
					min=count;
				i=i+count;
				count=0;
				break;
			}
			}
		}
		System.out.println("largest sequence length is "+max+" sortest sequence lenght is "+min);

	}
}