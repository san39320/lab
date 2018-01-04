import java.util.Scanner;
class weekday{
	public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		int a;
		System.out.println("enter the day");
		a=input.nextInt();
		a=a+7;
		switch(a%7)
		{
			case 1:System.out.println("monday");break;
			case 2:System.out.println("tuesday");break;
			case 3:System.out.println("wednesday");break;
			case 4:System.out.println("thursday");break;
			case 5:System.out.println("friday");break;
			case 6:System.out.println("satursday");break;
			case 7:System.out.println("sunday");break;
			

		}
	}
}