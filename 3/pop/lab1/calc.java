import java.util.Scanner;
class calc{
	
	public static void main(String args[]){
	 Scanner input=new Scanner(System.in);
     System.out.println("enter the two numbers");
     int a=input.nextInt();
     int b=input.nextInt();
     System.out.println("enter the operator");
     char c=input.next().charAt(0);
     switch(c)
     {
     	case '+':System.out.println(a+"+"+b+"="+(a+b));
     			  break;
     	case '-':System.out.println(a+"-"+b+"="+(a-b));
     			break;
     	case '*':System.out.println(a+"*"+b+"="+(a*b));
     			  break;
     	case '/':System.out.println(a+"/"+b+"="+(a/b));
     			break;
     	case '%':System.out.println(a+"-"+b+"="+(a%b));
     			break;
     	default:System.out.println("invalid operator");
     }
	}

}