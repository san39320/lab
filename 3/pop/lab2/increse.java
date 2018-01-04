import java.util.Scanner;
class increse{
	public static void main(String[] args)
	{
		int a,b,c;
		Scanner input=new Scanner(System.in);
		System.out.println("enter three numbers");
		a=input.nextInt();
		b=input.nextInt();
		c=input.nextInt();
		if(a>b)
		{
			if(b>c)
				System.out.println("decresing");
			else 
				System.out.println("not in order");
		}else {
			if(b<c)
				System.out.println("increasing order");
			else
				System.out.println("not in order");
		} 
	}
}