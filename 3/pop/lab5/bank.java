import java.util.Scanner;
abstract class bankab{
	int balance;
	abstract void bal();
	abstract void dep();
	abstract void wid();
}
class bank1 extends bankab{
	int amt;
	Scanner input=new Scanner(System.in);
	void bal(){
		System.out.println("balance is "+balance);
	}
	void dep(){
		System.out.println("Enter the amount to be deposited");
		amt=input.nextInt();
		balance=balance+amt;
		System.out.println("new balance is "+balance);
	}
	void wid(){
		System.out.println("Enter the amount to be withdrawn");
		amt=input.nextInt();
		balance=balance-amt;
		System.out.println("new balance is "+balance);
	}

}	
class bank{
 public static void main(String[] args){
 	Scanner input=new Scanner(System.in);
 	bank1 b=new bank1();
	b.bal();
	boolean c=true;
	int d;
	while(c){
	System.out.println("Enter 1.deposit 2.withdraw 3.balance 4.exit");
	d=input.nextInt();
	switch(d)
	{
		case 1:b.dep();
				break;
		case 2:b.wid();
				break;
		case 3:b.bal();
				break;
		case 4:c=false;
				break;
		default:c=false;
	}

	}

	} 
}