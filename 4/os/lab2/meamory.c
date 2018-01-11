#include<stdio.h>
#include<stdlib.h>
#define fr(a,n) for(int i=a;i<n;i++)
struct node{
	int starting_index;
	int ending_index;
	int occupied_index;
	int *starting_address;
	int *ending_address;
	int status;//0=free 1=occupied
	struct fixednode *next;
};
void initializeblock(struct node *block,int *a,int size[],int n){
	for(int i=1;i<n;i++){
		size[i]=size[i-1]+size[i];
	}
	int prev=0;
	for(int i=0;i<n;i++){
	block[i].starting_index=prev;
	block[i].ending_index=size[i]-1;
	block[i].occupied_index=-1;
	block[i].starting_address=&a[prev];
	block[i].ending_address=&a[size[i-1]];
	prev=size[i-1];
	}
}
int freemeamory(struct node block){
	int free=block.ending_index-block.starting_index;
	return(free*4);
}
void firstfit(struct node *block,int *a){
	
}	
int main(){
	int meamory_size=1000;
	int* a=(int *)malloc(1000*sizeof(int));//main meamory of 4kb
	printf("size of main meamory is 4000 bytes");
	int noofblocks=5;
	struct node meamory[noofblocks];
	int size[noofblocks]={50,50,200,300,400};
	//making the 10 partitions of 400 bytes
	initializeblock(&meamory,a,size,noofblocks);
	fr(0,10)printf("%d\n",freemeamory(meamory[i]));
	//print("enter the fit you wnat to try 1.first 2.best 3.worst");
	int choice;
	return(1);
}