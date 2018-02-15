#include<stdio.h>
#include<stdlib.h>
#define fr(a,n) for(int i=a;i<n;i++)
struct node{
	int starting_index;
	int ending_index;
	int occupied_index;
	int process_id;
	struct fixednode *next;
};
void initializeblock(struct node block[],int *a,int size[],int n){
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
	}
	if(prev<999){
	int i=n;
	block[i].starting_index=prev;
	block[i].ending_index=999;
	block[i].occupied_index=-1;
	block[i].process_id=-1;
	}
}
int freemeamory(struct node block){
	int free;
	if(block.occupied_index==-1){
	free=block.ending_index-block.starting_index+1;
	}else if(block.occupied_index==-2){
		return 0;
	}else{
	free=block.ending_index-block.occupied_index;
	}
	return (free);
}
void analyze(struct node meamory[],int n){
	for(int i=0;i<n;i++){
		int total;
		if(meamory[i].starting_index==meamory[i].ending_index)
			total=0;
		else
			total=(meamory[i].occupied_index==-2?0:(meamory[i].ending_index-meamory[i].starting_index+1));
		int free=freemeamory(meamory[i]);
		printf("block %d process_id:%d :total:%d bytes occupied:%d free:%d\n",i,meamory[i].process_id,total,total-free,free);
		//printf(" start adress:%d occcupied adress:%d end address:%d \n",meamory[i].starting_index,meamory[i].occupied_index,meamory[i].ending_index);}
}}
void firstfit(struct node block[],int *process,int *a,int n,int nop,int id){
	for(int i=0;i<nop;i++){
		for(int j=0;j<n;j++){
			if(process[i]<=freemeamory(block[j])){
				int index=process[i];
				if(block[j].occupied_index==-1)
					block[j].occupied_index=block[j].starting_index+index-1;
				else
					block[j].occupied_index=block[j].occupied_index+index;
				block[j].process_id=(id)?id:i+1;
				break;
			}
			if(j==n-1)printf("first meamory insufficient for proccess of %dbytes\n",process[i]);
		}
	}analyze(block,n);
}	
void bestfit(struct node block[],int *process,int *a,int n,int nop,int id){
	for(int i=0;i<nop;i++){
		int min=-1;
		for(int j=0;j<n;j++){
			if(process[i]<=freemeamory(block[j])){
				if(min==-1){min=j;}
				else if(freemeamory(block[j])<freemeamory(block[min])){
				min=j;}				
			}
		}
		if(min>=0){
			int index=process[i];
			if(block[min].occupied_index==-1)
					block[min].occupied_index=block[min].starting_index+index-1;
				else
					block[min].occupied_index=block[min].occupied_index+index;
			block[min].process_id=(id)?id:i+1;	
		}else{
		printf("meamory insufficient for proccess of %dbytes \n",process[i]);}
	}analyze(block,n);
}
void worstfit(struct node block[],int *process,int *a,int n,int nop,int id){
	for(int i=0;i<nop;i++){
		int max=-1;
		for(int j=0;j<n;j++){
			if(process[i]<=freemeamory(block[j])){
				if(max==-1){max=j;}
				else if(freemeamory(block[j])>freemeamory(block[max])){
				max=j;}				
			}
		}
		if(max>=0){
			int index=process[i];
			if(block[max].occupied_index==-1)
					block[max].occupied_index=block[max].starting_index+index-1;
				else
					block[max].occupied_index=block[max].occupied_index+index;
			block[max].process_id=(id)?id:i+1;
		}else{
			printf("meamory insufficient for proccess of %dbytes\n",process[i]);
		}
	}analyze(block,n);
}
int deleteprocess(struct node block[],int n,int id){
	for(int i=0;i<n;i++){
		if(block[i].process_id==id){
			block[i].occupied_index=-1;
			block[i].process_id=-1;
			return i;
		}
	}
	return -1;
}
int defragment(struct node block[],int n,int i,int noofblocks){
	if(i>=0){
		printf("defragmenting\n%d",noofblocks);
		for(int j=i;j<noofblocks-1;j++){
			if(block[j].occupied_index!=block[j].ending_index){
				int temp;
				temp=block[j].ending_index-(block[j].occupied_index!=-1?block[j].occupied_index:block[i].starting_index);
				if(block[j].occupied_index==-1){
					block[j].ending_index=block[j].starting_index;
					block[j+1].starting_index=block[j+1].starting_index-temp;
					block[j+1].occupied_index=(block[j+1].occupied_index==-1?-1:block[j+1].occupied_index-temp);
				}
				else{
					block[j].ending_index=block[j].occupied_index;
				block[j+1].starting_index=block[j+1].starting_index-temp;
				block[j+1].occupied_index=(block[j+1].occupied_index==-1?-1:block[j+1].occupied_index-temp);}
			}
		}
	}
}
void cleanblock(struct node block[],int blockno){
	block[blockno].occupied_index=-1;
	block[blockno].process_id=-1;
}
void mergeblock(struct node block[],int n){
	for(int i=0;i<n-1;i++){
		if(block[i].occupied_index==-1&&block[i+1].occupied_index==-1){
			block[i].ending_index=block[i+1].ending_index;
			block[i+1].occupied_index=-2;
			block[i+1].starting_index=block[i+1].ending_index;
			printf("mergeing index values%d%d",block[i+1].starting_index,block[i+1].ending_index);
		}

	}
}		
int main(){
	int a[1000];
	printf("total meamory size is 1000");
	int noofblocks;
	printf("enter number process\n");
	scanf("%d",&noofblocks);
	printf("enter the process sizes");
	int process[noofblocks];
	int blocks[noofblocks];
	for(int i=0;i<noofblocks;i++){scanf("%d",&process[i]);blocks[i]=process[i];}
	struct node meamory[noofblocks+1];
	initializeblock(meamory,a,process,noofblocks);
	printf("intial meamory\n");
	analyze(meamory,noofblocks+1);printf("\n");
	firstfit(meamory,blocks,a,noofblocks,noofblocks,0);
	noofblocks=noofblocks+1;
	/*printf("\nenter the fit you want to try \n1.first fit\n2.best fit\n3.worst fit\n");
	int choice;scanf("%d",&choice);
	switch(choice){
		case 1:firstfit(meamory,process,a,noofblocks,noofprocess,0);break;
		case 2:bestfit(meamory,process,a,noofblocks,noofprocess,0);break;
		case 3:worstfit(meamory,process,a,noofblocks,noofprocess,0);break;
		default:printf("wrong input");
	}*/
	while(1){
		printf("enter choice \n 1.delete process 2.enter new process 3.clean a block");
		int choice1;
		scanf("%d",&choice1);
		switch(choice1){
			case 1:printf("enter process id\n");
				int id,i;
				scanf("%d",&id);
				i=deleteprocess(meamory,noofblocks,id);
				//mergeblock(meamory,noofblocks);
				analyze(meamory,noofblocks);
				defragment(meamory,noofblocks,i,noofblocks);
				analyze(meamory,noofblocks);
				break;
			case 2:
				printf("enter the new process size and id\n");
				int newpr[1];
				scanf("%d",&newpr[0]);
				scanf("%d",&id);
				printf("%d,%d",newpr[0],id);
				printf("\nenter the fit you want to try \n1.first fit\n2.best fit\n3.worst fit\n");
				int choice;scanf("%d",&choice);
				if(choice==1)firstfit(meamory,newpr,a,noofblocks,1,id);
				else if(choice==2)bestfit(meamory,newpr,a,noofblocks,1,id);
				else if(choice==3)worstfit(meamory,newpr,a,noofblocks,1,id);
				break;
			case 3:printf("enter the block no u want to clean");
				int blockno;
				scanf("%d",&blockno);
				cleanblock(meamory,blockno);
				analyze(meamory,noofblocks);
				break;
			default :printf("wrong input");
		}
	}
	return(1);
}