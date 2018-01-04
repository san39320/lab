class a{

	interface b{				//nested class  
		public void method1();
	}
	interface c extends b{	//inheriting interface
		public void method2();
	}
}
abstract class d implements a.c{		//abstract class inmpleting one method
		public void method1(){
			System.out.println("inside class a interface b");
		}
}
class e extends d{						//implementing second method
	public void method2()
	{
		System.out.println("inside class a interface c");
	}
}



class adap implements a.c{			//using adapter class implementation
	public void method1()
	{
	}
	public void method2(){
	}

}
class marker implements a.c{}
class f extends adap{
	public void method1(){
		System.out.println("using adapterclass method1");
	}
	public void method2(){
		System.out.println("using adapterclass method2");

	}

}
class interface1{
	public static void main(String[] args){
	e z=new e();
	f y=new f();
	z.method1();
	z.method2();
	y.method1();
	y.method2();
}
}


