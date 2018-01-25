import java.util.Scanner;
import java.util.*;
import node1.node;
public class main {
    static int total=1000;
    static int freesize=1000;
    static Scanner input=new Scanner(System.in);
    static ArrayList<node> process=new ArrayList<node>(15);
    static void display(){
        int size=0;
        System.out.println("--------------------------------------------------");
        for(int i=0;i<process.size();i++){
            if(size!=(total-freesize)){
                if(process.get(i)!=null) {
                    size = process.get(i).size + size;
                    System.out.println("|meamory:" + i + " processname:" + process.get(i).name + "process size" + process.get(i).size + "|");
                }
            }else{
                System.out.println("|meamory:"+i+" freemeamory"+freesize+"|");
                break;
            }
        }
        System.out.println("--------------------------------------------------");
    }
    static void delete1(String p)
    {   int temp=-1;
        for(int i=0;i<process.size();i++)
        {
            if(process.get(i)!=null && process.get(i).name.equals(p))
            {
                temp=i;
                break;
            }
        }
        if(temp==-1)
        {
            System.out.println("No process found");
            return;
        }
        else{
            freesize=freesize+process.get(temp).size;
            process.set(temp,null);
        }
        for(int i=temp;i<process.size()-1;i++){
            if(process.get(i+1)!=null){
                process.set(i,process.get(i+1));
            }else{break;}
        }
    }
    static void allocate(int processsize,String name)
    {
            for(int k=0;k<10;k++){
                if(process.get(k)==null && freesize!=0){
                    process.set(k,new node());
                    process.get(k).name=name;
                    process.get(k).addr=k;
                    process.get(k).size=processsize;
                    freesize=freesize-processsize;
                    break;
                }
                else if(k==9){
                    System.out.println("meamory full or excess process");
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
        delete1("2");
        delete1("0");
        display();
        /*
        System.out.println("--------------------------------------------------");
        display();
        allocate(300,"google");
        System.out.println("--------------------------------------------------");
        display();*/

        }

}

