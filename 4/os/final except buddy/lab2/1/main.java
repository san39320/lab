import java.util.Scanner;
import java.util.*;
import node1.node;
public class main {
    static Scanner input=new Scanner(System.in);
    static ArrayList<node> process=new ArrayList<node>(15);
    static void display(){//displays current status of the block
        for(int i=0;i<process.size();i++){
            if(process.get(i)!=null){
            System.out.println("|meamory:"+i+" processid:"+process.get(i).name+" pageno:"+process.get(i).pageno+"|");
        }else{
                System.out.println("|meamory:"+i+"|");      
            }
        }
    }
    static void delete1(String p)//deletes the process
    {   int temp=-1;
        for(int i=0;i<process.size();i++)//get the pointer to the node to be deleted
        {
            if(process.get(i)!=null && process.get(i).name.equals(p))
            {
                temp=i;
                break;
            }
        }
        if(temp==-1)//checking whether the process is found or not
        {
            System.out.println("No process found");
            return;
        }
        node pointer = process.get(temp);
        while(pointer!=null)//freeing the node
        {
            int index=pointer.addr;
            process.set(index,null);
            pointer=pointer.next;
        }
    }
    static void allocate(int processsize,String name)//allocating memory for a process
    {
           sss int noofpages=proceize/50;     //calculte the number of pages
            node tail = new node;//starting 

            for(int j=0;j<noofpages;j++){     //allocation process pages in frames and linking the nodes
                int flag=0;
                for(int k=0;k<10;k++){
                    if(process.get(k)==null){
                        flag=1;
                        process.set(k,new node());
                        process.get(k).pageno=j;
                        process.get(k).name=name;
                        process.get(k).addr=k;
                        tail.next=process.get(k);
                        tail=process.get(k);break;
                    }
                }
                if(flag==0){		//checking if the memory is insufficient
                    System.out.println("insufficient meamory for some or all pages");break;
                }
            }

        }


    public static void main(String args[]){
        int processsize[]=new int[]{100,50,210,120};
        for(int i=0;i<10;i++){process.add(i,null);}
        for(int i=0;i<processsize.length;i++){
         allocate(processsize[i],Integer.toString(i));
        }
        display();
        while(true){
            System.out.println("enter 1.insertion 2.deletion 3.display meamory 4.exit");
            int choice=input.nextInt();
            if(choice==1){
                System.out.println("enter the size of process");//insertion 
                int mea=input.nextInt();
                System.out.println("enter the process name");
                String a;
                a=input.nextLine();
                a=input.nextLine();
                allocate(mea,a);
            }else if(choice==2){//deletion
                String a;
                System.out.println("enter the name of process");
                a=input.nextLine();
                a=input.nextLine();
                delete1(a);
            }else if(choice==3){//display
                display();
            }else if(choice==4){
                break;
            }else{
                System.out.println("wrong input");
            }
        }
        }

}

