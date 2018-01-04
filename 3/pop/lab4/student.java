import java.util.Scanner;
class student{
	int m1;
	int m2;
	int m3;
	int m4;
	int total;
	student(int m1,int m2,int m3,int m4){
		this.m1=m1;
		this.m2=m2;
		this.m3=m3;
		this.m4=m4;
		

	}
	int totalmark(student ob){
		ob.total=ob.m1+ob.m2+ob.m3+ob.m4;
		return(ob.total);

	}
	public static void main(String[] args){
		student[] s=new student[7];
		Scanner ip=new Scanner(System.in);
		System.out.println("enter number of students");
		int n,i,total;
		int m1,m2,m3,m4;
		n=ip.nextInt();
		for(i=0;i<n;i++){
			System.out.println("enter student "+(i+1)+" marks of 4 subjects");
			m1=ip.nextInt();
			m2=ip.nextInt();
			m3=ip.nextInt();
			m4=ip.nextInt();
			s[i]=new student(m1,m2,m3,m4);
		}
		for(i=0;i<n;i++){
			total=s[i].totalmark(s[i]);
			System.out.println("total of student"+(i+1)+"marks is"+total);

		}


	}
}
