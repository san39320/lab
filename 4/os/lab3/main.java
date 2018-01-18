import java.util.*;
class main{
	static Scanner input=new Scanner(System.in);
	int[] meamory=new int[10];
	int[] processid=new int[10];
	main(){
	for(int i=0;i<10;i++){this.meamory[i]=0;this.processid[i]=0;}
	}

	public static void main(String args[]){
		int framesize=50;
		//allocation meamory for process
		while(true){
			System.out.println("Enter the choice 1.insert process");
			int choice;
			choice=input.nextInt();
			if(choice==1){
				System.out.println("Enter the size of process 50<size<200 ");
				int size;
				size=input.nextInt();
			}
		}
	}

}