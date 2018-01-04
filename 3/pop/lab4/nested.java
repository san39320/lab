class nested{
	static int a=15;
	int b;
	nested(){
		b=10;
	}
	static class innerclass{
		void display(){
		System.out.println("static class access static variable of outer class "+a);
	}
	}
	class inner1{
		void display(){

		System.out.println("it can access both static variable and outer class variable b "+a+" "+b);
	}
	}
	public static void main(String[] args){
		nested a=new nested();
		nested.innerclass b=new nested.innerclass();
		nested.inner1 c=a.new inner1();
		b.display();
		c.display();
	}
}