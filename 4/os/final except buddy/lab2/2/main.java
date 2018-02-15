import java.util.Scanner;
import java.util.*;
import node1.node;
public class main {
    static Scanner input=new Scanner(System.in);
    static Hashtable<String,ArrayList> table=new Hashtable<String,ArrayList>(15);
    static ArrayList<node> process=new ArrayList<node>(15);
    static void display(){
        for(int i=0;i<process.size();i++){
            if(process.get(i)!=null){
                System.out.println("|meamory:"+i+" processname:"+process.get(i).name+" pageno:"+process.get(i).pageno+"|");
            }else{
                System.out.println("|meamory:"+i+"|");
            }
        }
    }
    static void delete1(String p)//deletes the process
    {
        ArrayList<Integer> temp=table.get(p);
        for(int i=0;i<temp.size();i++)
        {
            process.set(temp.get(i),null);
        }
        table.remove(p);
    }
    static void allocate(int processsize,String name)//make an entry in page table and insert the process pages in frames
    {
        int noofpages=processsize/50;
        node head=new node(-1);
        node tail = head;
        ArrayList<Integer> temp=new ArrayList<Integer>(processsize);
        for(int j=0;j<noofpages;j++){
            int flag=0;
            for(int k=0;k<10;k++){
                if(process.get(k)==null){
                    flag=1;
                    process.set(k,new node(-1));
                    process.get(k).pageno=j;
                    process.get(k).name=name;
                    temp.add(k);
                    break;
                }
            }
            if(flag==0){
                System.out.println("insufficient meamory for some or all pages");break;
            }
        }
        table.put(name,temp);
    }


    public static void main(String args[]){
        int processsize[]=new int[]{100,50,210,120};
        for(int i=0;i<10;i++){process.add(i,null);}
        for(int i=0;i<processsize.length;i++){
            allocate(processsize[i],Integer.toString(i));
        }
        display();
        while(true){
            System.out.println("enter 1.insertion 2.deletion 3.display meamory 4.display process table 5.exit");
            int choice=input.nextInt();
            if(choice==1){  //inserting
                System.out.println("enter the size of process");
                int mea=input.nextInt();
                System.out.println("enter the process name");
                String a;
                a=input.nextLine();
                a=input.nextLine();
                allocate(mea,a);
            }else if(choice==2){  //deletion
                String a;
                System.out.println("enter the name of process");
                a=input.nextLine();
                a=input.nextLine();
                delete1(a);
            }else if(choice==3){
                display();
            }else if(choice==4){
                System.out.println(table);
            }else if(choice==5){
                break;
            }
            else{
                System.out.println("wrong input");
            }
        }
    }

}
