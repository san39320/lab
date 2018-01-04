import java.util.Scanner;
class bankab{
	int balance;
	abstract void bal();
	abstract void dep();
	abstract void wit();
}
class bank1 extends bankab{
	void bal(){
		System.out.println("balance is "+balance);
	}
	void dep(int amt){
		balance=balance+amt;
		System.out.println("new balance is "+balance);
	}
	void wit(int amt){
		balance=balance-amt;
		System.out.println("new balance is "+balance);
	}

}
class bank{
	bank1 b=new bank1;
	boolean i=true;


} 