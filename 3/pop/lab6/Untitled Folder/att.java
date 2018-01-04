import java.util.Scanner;

import Student.NewClass;

class att{
    
    public static void main(String args[]){
     
        Scanner in=new Scanner(System.in);
        int choice=4;
        int[] info=new int[5];
        while(choice!=3){
        System.out.println("Choose the subject to calculate attendance:\n1.POP\t2.Unix\n3.QUIT");  
        choice=in.nextInt();
        
        if(choice==1){
            
              System.out.print("Enter the number of students taking the course: ");
              int n=in.nextInt();
            for(int j=0;j<n;j++){
            in.nextLine();
            System.out.print("Student details:\nNAME: ");
            String name=in.nextLine();
            System.out.print("\nROLL NO: ");
            int rn=in.nextInt();
            
            NewClass s1=new NewClass(name,rn,"pop");     
            s1.SetN(n);
            for(int i=1;i<=5;i++)
            {
                 System.out.println("Class "+i+": Attended ?");
                 char yn=in.next().charAt(0);
                 if(yn=='y')
                     info[i-1]=1;
                 else
                     info[i-1]=0;
            }
            s1.SetPR(info);
            
            s1.Attendance();
            
        }
        }
        
        if(choice==2){
            
        System.out.print("Enter the number of students taking the course: ");
        int n=in.nextInt();
        for(int j=0;j<n;j++){    
            in.nextLine();
            System.out.print("Enter their details:\nNAME: ");
            String name=in.nextLine();
            System.out.print("\nROLL NO: ");
            int rn=in.nextInt();
            
            NewClass s2=new NewClass(name,rn,"unix");     
            s2.SetN(n);
            for(int i=1;i<=5;i++)
            {
                 System.out.println("Class "+i+": Attended ?(Y/N)");
                 char yn=in.next().charAt(0);
                 if(yn=='y')
                     info[i-1]=1;
                 else
                     info[i-1]=0;
            }
            s2.SetPR(info);
            s2.Attendance();
        }
        }
     }System.out.print("Good bye");
    }
}
