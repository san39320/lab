import java.util.Scanner;
class interest{
	public static void main(String[] args){
		float amount,interest,year;
		System.out.println("enter the amount interest year");
		Scanner input=new Scanner(System.in);
		amount=input.nextInt();
		interest=input.nextInt();
		year=input.nextInt();
		for(int i=1;i<=year*12;i++)
		{
			amount=amount+(amount*interest/1200);
			if(i%12==0)
			{
				System.out.println("year "+(i/12)+"futurevalue "+amount);
			}
		}
		System.out.println("final amount is"+amount);
	}
}