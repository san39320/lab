import java.util.Scanner;
class student{
	int m1,m2,m3,m4;
	student(int m1,int m2,int m3,int m4)
	{
		this.m1=m1;
		this.m2=m2;
		this.m3=m3;
		this.m4=m4;
	}
	public void display()
	{
		System.out.println("mark1= "+this.m1);
		System.out.println("mark2= "+this.m2);
		System.out.println("mark3= "+this.m3);
		System.out.println("mark4= "+this.m4);
	}
	public static void main(String[] args)
	{
		int m1,m2,m3,m4;
		Scanner input=new Scanner(System.in);
		System.out.println("enter the marks of first semister 4 subjects");
		m1=input.nextInt();
		m2=input.nextInt();
		m3=input.nextInt();
		m4=input.nextInt();
		student s1=new student(m1,m2,m3,m4);
		System.out.println("enter the marks of second semister 4 subjects");
		m1=input.nextInt();
		m2=input.nextInt();
		m3=input.nextInt();
		m4=input.nextInt();
		student s2=new student(m1,m2,m3,m4);
		System.out.println("first semister marks of student is");
		s1.display();
		System.out.println("second semister marks of student is");
		s2.display();





	}
}