import java.util.Scanner;
class a{
	int x=0;
	int y=0;
	int sum=0;

}
final class b extends a{
	static Scanner ip=new Scanner(System.in);
	void input()
	{
		int a,b;
		System.out.println("enter two numbers");
		a=ip.nextInt();
		b=ip.nextInt();
		this.x=a;
		this.y=b;

	}
	void calc()
	{
		this.sum=this.x+this.y;
		System.out.println("sum is "+this.sum);
	}
}
class p5{
	public static void main(String[] args){
	b c=new b();
	c.input();
	c.calc();
}

}