import java.util.Scanner;
class area{
	double volume;
	int a;
	int b;
	area(int a,int b){
		this.a=a;
		this.b=b;
	}
	area(int a)
	{
		this.a=a;
	} 
	public void square()
	{
		this.volume=a*a;
		System.out.println(volume);
	}
	public void cylinder()
	{
		this.volume=3.14*a*a+3.14*a*b;
		System.out.println(volume);

	}
	public void cube()
	{
		this.volume=a*a*a;
		System.out.println(volume);

	}
	public void sphere()
	{
		this.volume=4*3.14*a*a;
		System.out.println(volume);

	}
	public void rectangle()
	{
		this.volume=a*b;
		System.out.println(volume);

	}

	public static void main(String[] args){
		System.out.println("area of square with length 4" );
		area a=new area(4);
		a.square();
		System.out.println("area of rectangle with a= 4 b=4" );
		area b=new area(4,4);
		b.rectangle();
		System.out.println("area of cylender with a= 4 h=5" );
		area c=new area(4,5);
		c.cylinder();
		System.out.println("area of cube with a=3" );
		area d=new area(3);
		d.cube();
		System.out.println("area of sphere with r= 2" );
		area e=new area(2);
		e.sphere();		

	}
}
