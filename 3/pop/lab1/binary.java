import java.util.Scanner;
class binary{
	public static void main(String args[])
	{
		Scanner input=new Scanner(System.in);
		System.out.println("enter the number");
		int a=input.nextInt();
		int b;
		b=0;
		int i=0;
		int d[]=new int[100];
		/*while(a!=0){
			int c=(int)Math.pow(10,i);
			b=b+(((a%2)==0)?c:((a%2)*c));
			a=a/2;
			i++;
		}*/
		while(a!=0)
		{
			d[i++]=a%2;
			a=a/2;

		}
		int s=i;
		System.out.println("number in binary format is "+b);
		for(i=s-1;i>=0;i--)
		{
			System.out.print(d[i]);
		}
	}
}