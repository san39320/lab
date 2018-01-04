import java.util.Scanner;
class area{
	double volume;
	public void vol(int a)
	{
		this.volume=a*a*6;
		System.out.println(volume);
	}
	public void vol(int a,int b)
	{
		this.volume=2*3.14*a*b;
		System.out.println(volume);

	}
	public void vol(double a,double b)
	{
		this.volume=3.14*a*(a+b);
		System.out.println(volume);

	}
	public void vol(int a,int b,int c)
	{
		this.volume=a*b*2+b*c*2+c*a*2;
		System.out.println(volume);

	}

	public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		System.out.println("length of cube in int");
		
		int b;
		a=input.nextInt();
		area z=new area();
		z.vol(a);
		System.out.println("radius and height of cylinder in int");
		a=input.nextInt();
		b=input.nextInt();
		z.vol(a,b);
		System.out.println("volume of cone with r=3 l=4");
		z.vol(3.0,4.0);
		System.out.println("voume of cuboid with a=2 b=3 c=4");
		z.vol(2,3,4);

	}
}