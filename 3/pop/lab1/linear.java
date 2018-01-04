import java.util.Scanner;
class linear{
	public static void main(String args[]){
		int a,e,b,f,c,g;
	    Scanner input=new Scanner(System.in);
	    System.out.println("1.enter the coefficints of x,y and c");
	    a=input.nextInt();
	    b=input.nextInt();
	    c=input.nextInt();
	    System.out.println("2.enter the coefficints of x,y and c");
	    e=input.nextInt();
	    f=input.nextInt();
	    g=input.nextInt();
	    int d=(a*f)-(e*b);
	    double x=(c*f)-(g*b);
	    double y=(a*g)-(e*c);
	    x=x/d;
	    y=y/d;
	    System.out.print("x=");
	    System.out.print(x);
	    System.out.print("y=");
	    System.out.print(y);
	}
}