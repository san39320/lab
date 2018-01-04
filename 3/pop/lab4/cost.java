import java.util.Scanner;
class cost{
	static String p1;
	static String p2;
	static String p3;
	static int c1;
	static int c2;
	static int c3;
	
	
	static void product(String p11,String p22,String p33,int c11,int c22,int c33)
	{
		p1=p11;
		p2=p22;
		p3=p33;
		c1=c11;
		c2=c22;
		c3=c33;
	}
	int cal()
	{

		System.out.println("enter the product and quantity of items to buy enter space to get total");
		System.out.println(" 1 "+p1+" cost "+c1);
		System.out.println(" 2 "+p2+" cost "+c2);
		System.out.println(" 3 "+p3+" cost "+c3);
		int amount=0;
		while(true){
			int q;
			Scanner input=new Scanner(System.in);
			String a=input.nextLine();
			
			if(a.equals(cost.p1)){
				System.out.println("enter the quantity of "+p1);
				q=input.nextInt();
				amount=amount+q*c1;
			}
			else if(a.equals(cost.p2)){
				System.out.println("enter the quantity of "+p2);
				q=input.nextInt();
				amount=amount+q*c2;
			}
			else if(a.equals(cost.p3)){
				System.out.println("enter the quantity of "+p3);
				q=input.nextInt();
				amount=amount+q*c3;
			}
			else{
			System.out.println("invalid product"); 
			break;
		    }

			
		}
		return amount;

	}
	public static void main(String[] args){
		String p1,p2,p3;
		int c1,c2,c3;
		Scanner input=new Scanner(System.in);
		System.out.println("enter product 1");
		p1=input.nextLine();
		System.out.println("enter cost");
		c1=input.nextInt(); 
		System.out.println("enter product 2");
		p2=input.nextLine();
		p2=input.nextLine();
		System.out.println("enter cost");
		c2=input.nextInt();
		System.out.println("enter product 3");
		p3=input.nextLine();
		p3=input.nextLine();
		System.out.println("enter cost");
		c3=input.nextInt();
		cost.product(p1,p2,p3,c1,c2,c3);
		cost a=new cost();
		int total;
		total=a.cal();
		System.out.println("total cost is"+total);

	}

}