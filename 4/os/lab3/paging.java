import java.util.*;
class linkedlist{
	public int processno;
	public int pageno;
	public int frameadress;
	public int status;
	public linkedlist next;
	linkedlist(){
	this.processno=-1;
	this.pageno=-1;
	this.frameadress=-1;
	this.next=null;
	this.status=0;
}
}
class paging{
	static Scanner input=new Scanner(System.in);
	int[] meamory=new int[10];
	int[] processid=new int[10];
	paging(){
	for(int i=0;i<10;i++){this.meamory[i]=0;this.processid[i]=0;}
	}

	public static void main(String args[]){
		int framesize=50;
		int[] process=new int[10];
		//allocation meamory for process
		while(true){
			System.out.println("Enter the choice 1.insert process");
			int choice;
			choice=input.nextInt();
			if(choice==1){

			}
		}
	}

}