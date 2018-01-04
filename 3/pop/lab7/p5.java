interface b{			
		public void method1();
		public void method2();
	}


abstract class a implements b{			//partial implementation
public void method1(){
	System.out.println("inside class a");
}
}
class c extends a{

	public void method2(){
		System.out.println("inside class c");
	}

}
class p5{
	public static void main(String[] args){
	c d=new c();
	d.method1();
}
}


