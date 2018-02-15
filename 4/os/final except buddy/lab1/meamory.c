#include<stdio.h>
#include<stdlib.h>
#define fr(a,n) for(int i=a;i<n;i++)
struct node{    //structure which stores the information of the block
	int starting_index;
	int ending_index;
	int occupied_index;
	int process_id;
	struct fixednode *next;
	int status;
};
void initializeblock(struct node block[],int *a,int size[],int n){//initiales the blocksize based on the size of process
	for(int i=1;i<n;i++){
		size[i]=size[i-1]+size[i];
	}
	int prev=0;
	for(int i=0;i<n;i++){
	block[i].starting_index=prev;
	block[i].ending_index=size[i]-1;
	block[i].occupied_index=-1;
	block[i].process_id=-1;
	prev=size[i];
	block[i].status=0;
	}
}
int freemeamory(struct node block){//calculates amount of free meamory
	int free;
	if(block.occupied_index==-1){
	free=block.ending_index-block.starting_index+1;
	}else{
	free=block.ending_index-block.occupied_index;
	}
	return (free);
}
void analyze(struct node meamory[],int n){//displays the amount of free meamory,size and proccess occupied.
	for(int i=0;i<n;i++){
		int total=(meamory[i].ending_index-meamory[i].starting_index+1);
		int free=freemeamory(meamory[i]);
		printf("block %d process_id:%d :total:%d bytes occupied:%d free:%d\n",i,meamory[i].process_id,total,total-free,free);}
}
void firstfit(struct node block[],int *process,int *a,int n,int nop,int id){//finds the first block the fits the process
	for(int i=0;i<nop;i++){
		for(int j=0;j<n;j++){
			if(process[i]<=freemeamory(block[j])&&(block[j].status==0)){
				int index=process[i];
				block[j].occupied_index=block[j].starting_index+index-1;
				block[j].status=1;
				block[j].process_id=(id)?id:i+1;
				break;
			}
			if(j==n-1)printf("first meamory insufficient for proccess of %dbytes\n",process[i]);
		}
	}analyze(block,n);
}	
void bestfit(struct node block[],int *process,int *a,int n,int nop,int id){//finds the best block the fits the process
	for(int i=0;i<nop;i++){
		int min=-1;
		for(int j=0;j<n;j++){
			if(process[i]<=freemeamory(block[j])&&(block[j].status==0)){
				if(min==-1){min=j;}
				else if(freemeamory(block[j])<freemeamory(block[min])){
				min=j;}				
			}
		}
		if(min>=0){
			int index=process[i];
			block[min].occupied_index=block[min].starting_index+index-1;
			block[min].status=1;block[min].process_id=(id)?id:i+1;	
		}else{
		printf("meamory insufficient for proccess of %dbytes \n",process[i]);}
	}analyze(block,n);
}
void worstfit(struct node block[],int *process,int *a,int n,int nop,int id){//finds the worst block the fits the process
	for(int i=0;i<nop;i++){
		int max=-1;
		for(int j=0;j<n;j++){
			if(process[i]<=freemeamory(block[j])&&(block[j].status==0)){
				if(max==-1){max=j;}
				else if(freemeamory(block[j])>freemeamory(block[max])){
				max=j;}				
			}
		}
		if(max>=0){
			int index=process[i];
			block[max].occupied_index=block[max].starting_index+index-1;
			block[max].status=1;block[max].process_id=(id)?id:i+1;
		}else{
			printf("meamory insufficient for proccess of %dbytes\n",process[i]);
		}
	}analyze(block,n);
}
void deleteprocess(struct node block[],int n,int id){//deletes the process from memory
	for(int i=0;i<n;i++){
		if(block[i].process_id==id){
			block[i].occupied_index=-1;
			block[i].process_id=-1;
			block[i].status=0;
		}
	}analyze(block,n);
}		
int main(){
	int* a=(int *)malloc(1000*sizeof(int));//main meamory of 4000 bytes
	printf("size of main meamory is 1000 bytes\n");
	int noofblocks=5;
	struct node meamory[noofblocks];
	int size[]={50,50,200,300,400};//5 blocks of different size
	initializeblock(meamory,a,size,noofblocks);
	analyze(meamory,noofblocks);
	int process[]={160,152,350,25,120};
	int noofprocess;
	noofprocess=sizeof(process)/sizeof(int);
	printf("process size to be allocated is");
	fr(0,noofblocks)printf(" %dbytes ",process[i]);
	printf("\nenter the fit you want to try \n1.first fit\n2.best fit\n3.worst fit\n");
	int choice;scanf("%d",&choice);
	switch(choice){
		case 1:firstfit(meamory,process,a,noofblocks,noofprocess,0);break;
		case 2:bestfit(meamory,process,a,noofblocks,noofprocess,0);break;
		case 3:worstfit(meamory,process,a,noofblocks,noofprocess,0);break;
		default:printf("wrong input");
	}
	while(1){
		printf("enter choice \n 1.delete process 2.enter new process ");
		int choice1;
		scanf("%d",&choice1);
		switch(choice1){
			case 1:printf("enter process id\n");//input a process
				int id;
				scanf("%d",&id);
				deleteprocess(meamory,noofblocks,id);
				break;
			case 2://deleting a process
				printf("enter the new process size and id\n");
				int newpr[1];
				scanf("%d",&newpr[0]);
				scanf("%d",&id);
				printf("%d,%d",newpr[0],id);
				if(choice==1)firstfit(meamory,newpr,a,noofblocks,1,id);
				else if(choice==2)bestfit(meamory,newpr,a,noofblocks,1,id);
				else if(choice==3)worstfit(meamory,newpr,a,noofblocks,1,id);
				break;
			default :printf("wrong input");
		}
	}
	return(1);
}
