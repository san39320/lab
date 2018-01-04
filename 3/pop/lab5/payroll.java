import java.util.Scanner;
class abcd{
    String orgname = "abcd";
}
class Employee extends abcd{
    String name;
    String app;
    int age;
    int salary;
    Employee(String name,String grade,int age){
        this.name = name;
        this.app = grade;
        this.age = age;
    }
    public void appraisal(){
        switch(app){
            case "manager": salary = 60670;
                    break;
            case "assistant": salary = 52300;
                    break;
            case "hr": salary = 40358;
                    break;
            default: salary = 15566;
        }
    }
    public void display(){
        System.out.println(name + " working for " + orgname + "has salary" + salary);
    }
}
class payroll{
    public static void main(String[] args){
        Employee a = new Employee("aaa","manager",25);
        Employee b = new Employee("bbb","assistant",35);
        Employee c = new Employee("ccc","assistant",45);
        Employee d = new Employee("ddd","hr",55);
        System.out.println("After appraisal...");
        a.appraisal();
        a.display();
        b.appraisal();
        c.appraisal();
        d.appraisal();
        b.display();
        c.display();
        d.display();
    }
}