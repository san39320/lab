class Test{
	public static void main(String s[]){
		int a,b;
		try{
			a=Integer.parseInt(s[0]);
			try{
				b=2/a;
			}
			catch(ArithmeticException a){
			}
		}
		catch(Exception e){
			System.out.println(e);
		}	
		//System.out.println(a);
		System.out.println("after exception");
	}
}
