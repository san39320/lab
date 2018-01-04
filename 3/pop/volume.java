import java.util.Scanner;
class volume{
	double volume;
	public void vol(int a)
	{
		this.volume=a*a*a;
		System.out.println(volume);
	}
	public void vol(int a,int b)
	{
		this.volume=3.14*a*a*h;
		System.out.println(volume);

	}
	public void vol(double a,double b)
	{
		this.volume=3.14*a*a*b/3;
		System.out.println(volume);

	}
	public void vol(int a,int b,int c)
	{
		this.volume=a*b*c;
		System.out.println(volume);

	}

	public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		System.out.println("length of cube in int");
		int a=input.nextInt();
		int b;
		a=input.nextInt();
		vol(a);
		System.out.println("radius and height of cylinder in int");
		a=input.nextInt();
		b=input.nextInt();
		

	}
}