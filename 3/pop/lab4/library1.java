import java.util.Scanner;
class library{
	String[] aut=new String[10];
	String[] book=new String[10];
	int top;
	library(){
		top=-1;
	}
	static{
		System.out.println("welcome to library");
	}
	void insert(String book,String author){
		this.top=top+1;
		this.aut[top]=author;
		this.book[top]=book;

	}
	void display()
	{	System.out.println("book available are");
		for(int i=0;i<=this.top;i++)
		{
			System.out.println("book name:"+book[i]+"author name:"+aut[i]);
		}
	}
	void number()
	{
		System.out.println("Number of books are :"+this.top+1);
	}
}
class library1{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		library l=new library();
		boolean c=true;
		String str0=new String();
		String str=new String();
		String str2=new String();
		System.out.println("enter the author name and book name");

		while(c){
				
				str=input.nextLine();
				str2=input.nextLine();
				l.insert(str,str2);
			if(input.hasNextLine()){

			}
			else
				c=false;
		}
		l.number();
		l.display();

	}
	
}