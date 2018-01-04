package package2;
import package1.*;
class pak2{
public static void main(String args[]){
int c=30;
System.out.println("value of static variable in pak1.java in package1 is"+pak1.a);
package1.pak1 x=new package1.pak1();
System.out.println("value of object variable in pak1.java in package1 is"+x.b);
System.out.println("value of variable in same class "+c);
}

} 
